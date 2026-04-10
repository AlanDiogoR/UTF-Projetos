/**
 * Simulação do Problema Produtor-Consumidor com semáforos e prevenção de deadlock.
 *
 * Parte 1: Vários fluxos concorrentes (3 produtores + 2 consumidores = 5 "threads")
 *          compartilham um buffer circular.
 * Parte 2: mutex + empty + full garantem exclusão mútua e ausência de corrida no buffer.
 * Parte 3: Ordem fixa de aquisição — sempre counting (empty/full) ANTES do mutex,
 *          nunca o contrário, evitando espera circular e deadlock clássico.
 *
 * Nota: Em JavaScript do navegador não há threads POSIX; usamos async/await e
 * filas de Promises nos semáforos para modelar bloqueio/desbloqueio como em SO.
 */

/** Semáforo binário (0 ou 1) — equivalente a um lock quando inicializado em 1 */
class BinarySemaphore {
  /**
   * @param {number} initial 0 ou 1
   */
  constructor(initial = 1) {
    this._value = initial;
    /** @type {Array<() => void>} */
    this._waiters = [];
  }

  /** P / wait — entra na seção ou bloqueia */
  async wait() {
    if (this._value > 0) {
      this._value--;
      return;
    }
    await new Promise((resolve) => {
      this._waiters.push(resolve);
    });
  }

  /** V / signal — libera um esperador ou incrementa */
  signal() {
    if (this._waiters.length > 0) {
      const wake = this._waiters.shift();
      wake();
    } else {
      this._value++;
    }
  }

  get value() {
    return this._value;
  }
}

/** Semáforo contador (filas de produtos ou espaços vazios) */
class CountingSemaphore {
  /**
   * @param {number} initial número de permissões iniciais
   */
  constructor(initial) {
    this._value = initial;
    /** @type {Array<() => void>} */
    this._waiters = [];
  }

  async wait() {
    if (this._value > 0) {
      this._value--;
      return;
    }
    await new Promise((resolve) => {
      this._waiters.push(resolve);
    });
  }

  signal() {
    if (this._waiters.length > 0) {
      const wake = this._waiters.shift();
      wake();
    } else {
      this._value++;
    }
  }

  get value() {
    return this._value;
  }
}

/**
 * Lock explícito sobre o mesmo BinarySemaphore do mutex — reforço didático da Parte 2.
 * Na prática o buffer já é protegido por `mutex`; esta classe documenta o padrão lock/unlock.
 */
class Lock {
  /** @param {BinarySemaphore} binarySemaphore */
  constructor(binarySemaphore) {
    this._sem = binarySemaphore;
  }

  async acquire() {
    await this._sem.wait();
  }

  release() {
    this._sem.signal();
  }
}

// --- Configuração do problema ---

const BUFFER_SIZE = 5;
const NUM_PRODUCERS = 3;
const NUM_CONSUMERS = 2;

/** Buffer compartilhado (recurso comum) */
const buffer = {
  /** @type {Array<string | null>} */
  slots: Array(BUFFER_SIZE).fill(null),
  in: 0,
  out: 0,
  count: 0,
};

/** empty: espaços livres; full: itens; mutex: exclusão no buffer */
const empty = new CountingSemaphore(BUFFER_SIZE);
const full = new CountingSemaphore(0);
const mutex = new BinarySemaphore(1);
const bufferLock = new Lock(mutex);

/** Ordem global de IDs de recurso para documentação de prevenção de deadlock (Parte 3) */
const RESOURCE_ORDER = {
  EMPTY: 1,
  FULL: 2,
  MUTEX: 3,
};

/**
 * Regra de prevenção: nunca adquirir mutex antes de empty/full.
 * Produtor: empty → mutex → crítica → mutex → full
 * Consumidor: full → mutex → crítica → mutex → empty
 * Assim não há ciclo A espera B e B espera A com locks diferentes.
 */

let itemSerial = 0;
let running = false;
let delayMs = 400;

/** Estatísticas para o relatório / UI */
const stats = {
  produced: 0,
  consumed: 0,
};

/**
 * Produtor id — segue ordem: wait(empty) [R1], depois wait(mutex) [R3]
 * @param {number} id
 */
async function producer(id) {
  while (running) {
    const item = `P${id}-item-${++itemSerial}`;

    /* Ordem fixa: empty antes de mutex (evita deadlock com consumidor) */
    await empty.wait();

    await mutex.wait();

    try {
      // Seção crítica: apenas uma thread manipula in/count/slots
      buffer.slots[buffer.in] = item;
      buffer.in = (buffer.in + 1) % BUFFER_SIZE;
      buffer.count++;
      stats.produced++;
      renderBuffer();
      updateSemDisplay();
      log("prod", `Produtor ${id} INSERIU "${item}" (count=${buffer.count})`);
    } finally {
      mutex.signal();
    }

    full.signal();

    await sleep(delayMs + Math.random() * 200);
  }
}

/**
 * Consumidor id — ordem: wait(full) [R2], depois wait(mutex) [R3]
 * @param {number} id
 */
async function consumer(id) {
  while (running) {
    /* Ordem fixa: full antes de mutex (par simétrico ao produtor) */
    await full.wait();

    await bufferLock.acquire();

    try {
      const item = buffer.slots[buffer.out];
      buffer.slots[buffer.out] = null;
      buffer.out = (buffer.out + 1) % BUFFER_SIZE;
      buffer.count--;
      stats.consumed++;
      renderBuffer();
      updateSemDisplay();
      log("cons", `Consumidor ${id} REMOVEU "${item}" (count=${buffer.count})`);
    } finally {
      bufferLock.release();
    }

    empty.signal();

    await sleep(delayMs + Math.random() * 250);
  }
}

function sleep(ms) {
  return new Promise((r) => setTimeout(r, ms));
}

/** @param {"prod"|"cons"|"sys"} type */
function log(type, message) {
  const el = document.getElementById("log");
  const line = document.createElement("p");
  line.className = "log-line";
  const span = document.createElement("span");
  span.className = type === "prod" ? "t-prod" : type === "cons" ? "t-cons" : "t-sys";
  span.textContent = `[${new Date().toLocaleTimeString("pt-BR", { hour12: false })}] ${message}`;
  line.appendChild(span);
  el.appendChild(line);
  el.scrollTop = el.scrollHeight;
  const max = 200;
  while (el.children.length > max) {
    el.removeChild(el.firstChild);
  }
}

function renderBuffer() {
  const container = document.getElementById("buffer-slots");
  container.innerHTML = "";
  for (let i = 0; i < BUFFER_SIZE; i++) {
    const div = document.createElement("div");
    const val = buffer.slots[i];
    div.className = "slot " + (val ? "filled" : "empty");
    div.textContent = val ? val.slice(0, 12) : "∅";
    div.title = val || "vazio";
    container.appendChild(div);
  }
}

function updateSemDisplay() {
  const e = document.getElementById("sem-empty");
  const f = document.getElementById("sem-full");
  const m = document.getElementById("sem-mutex");
  if (e) e.textContent = String(empty.value);
  if (f) f.textContent = String(full.value);
  if (m) m.textContent = mutex.value === 1 ? "Livre" : "Ocupado";
  const mutexRow = document.querySelector(".sem-item.sem-mutex");
  if (mutexRow) mutexRow.classList.toggle("is-busy", mutex.value === 0);

  document.getElementById("stat-produced").textContent = String(stats.produced);
  document.getElementById("stat-consumed").textContent = String(stats.consumed);
  document.getElementById("stat-buffer-count").textContent = String(buffer.count);
}

function startSimulation() {
  if (running) return;
  running = true;
  document.getElementById("btn-start").disabled = true;
  document.getElementById("btn-stop").disabled = false;

  log(
    "sys",
    `--- Início: 3 produtores + 2 consumidores | Ordem de locks: empty(${RESOURCE_ORDER.EMPTY})/full(${RESOURCE_ORDER.FULL}) antes de mutex(${RESOURCE_ORDER.MUTEX}) ---`
  );

  for (let p = 1; p <= NUM_PRODUCERS; p++) {
    producer(p);
  }
  for (let c = 1; c <= NUM_CONSUMERS; c++) {
    consumer(c);
  }
}

function stopSimulation() {
  running = false;
  document.getElementById("btn-start").disabled = false;
  document.getElementById("btn-stop").disabled = true;
  log("sys", "--- Simulação parada pelo usuário ---");
}

function clearLog() {
  const el = document.getElementById("log");
  el.innerHTML = "";
}

function init() {
  renderBuffer();
  updateSemDisplay();

  document.getElementById("btn-start").addEventListener("click", startSimulation);
  document.getElementById("btn-stop").addEventListener("click", stopSimulation);
  document.getElementById("btn-clear").addEventListener("click", clearLog);

  document.getElementById("speed").addEventListener("input", (ev) => {
    delayMs = Number(ev.target.value);
    document.getElementById("speed-val").textContent = `${delayMs} ms`;
  });
}

if (document.readyState === "loading") {
  document.addEventListener("DOMContentLoaded", init);
} else {
  init();
}
