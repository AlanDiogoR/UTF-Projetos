# QA — Estacionamento (Entrega Parcial) — 23/10/2026
Ambiente: javac/java 17.0.21 (Temurin), `javac -Xlint:all src/*.java` → 0 erros (2 warnings de serialVersionUID, inofensivos).
Teste roteirizado: `qa/entrada-teste.txt` → `qa/saida-teste.txt` (todas as opções 0–11 + opção inválida + entrada não numérica).

| # | Critério | Verificação | Resultado |
|---|---|---|---|
| 1 | Compila e executa | javac sem erros; execução termina na opção 0 | PASS |
| 2 | Default package | `grep ^package` → nenhum | PASS |
| 3 | Nome + RA nas primeiras linhas de todos os .java (18) | head -3 de cada arquivo | PASS |
| 4 | Um arquivo por classe/interface | 18 arquivos, 18 tipos | PASS |
| 5 | Menu switch/case na Principal | Principal.java `switch (opcao)` casos 0–11 + default | PASS |
| 6 | E/S só em Controle (+ Leitura auxiliar) | System.out/Scanner só em Controle*.java e Leitura.java; Principal sem E/S | PASS |
| 7 | Entidades só com atributos, get/set e sobrescritas | Cliente, Veiculo, Carro, Moto, Caminhonete, Vaga, Ticket sem E/S | PASS |
| 8 | Só construtor default; valores via setters | grep de construtores com parâmetro nas entidades → nenhum | PASS |
| 9 | Encapsulamento só public/private | grep `protected` e membros sem modificador → nenhum | PASS |
| 10 | Herança: 3 filhas de Veiculo, 2+ atributos próprios cada | Carro(numPortas, tipoCarroceria), Moto(cilindradas, temBau), Caminhonete(capacidadeCargaKg, cabineDupla) | PASS |
| 11 | Interface com uso efetivo | Tarifavel implementada pelas 3 filhas; calcularTarifa chamada em ControleTicket.registrarSaida; TOLERANCIA_MINUTOS usada | PASS |
| 12 | Sobrecarga com `//Sobrecarga` na linha acima | calcularTarifa(int, boolean) (interface + 3 filhas), listarVagas(boolean) | PASS |
| 13 | Sobrescrita com `//Sobrescrita` na linha acima | toString (7 classes), getTipoVaga, calcularTarifa(int) | PASS |
| 14 | Reflexividade: `this.` com `//Reflexividade` no fim da linha | 30 usos, 0 `this.` sem marca | PASS |
| 15 | 2 exceções próprias lançadas + try/catch sem multicatch | PlacaInvalidaException (validarPlaca, buscarPorPlaca), VagaIndisponivelException (buscarVagaLivre); catches separados; grep `catch(..|..)` → nenhum | PASS |
| 16 | RF01–RF03 cadastros aparecem nos relatórios; prompts com formato/tipo | saída: "Nome do cliente (String):", "Data/hora de entrada (dd/mm/aaaa hh:mm):" etc.; relatórios 7/8/9 | PASS |
| 17 | RF04 entrada: ticket criado e vaga ocupada; sem vaga → catch e continua | Ticket 1/2 criados; vagas OCUPADA; CAM9Z99 sem vaga → "Erro: Nao ha vaga livre..." | PASS |
| 18 | RF05 saída: ≤15 min = 0; tarifa por tipo; diária via calcularTarifa(int, boolean); vaga liberada | Moto 10 min = R$ 0,00; Carro SUV 150 min = R$ 21,00; Moto diária 2940 min = R$ 54,00; vaga volta a LIVRE | PASS |
| 19 | RF07/RF08 placa inexistente/vazia/repetida → PlacaInvalidaException | opção 6 "NAO0000", entrada "XXX0000", placa vazia e repetida → mensagem do catch | PASS |
| 20 | Sem SGBD, sem login, sem GUI, sem validação de documento | ArrayList em memória; validarPlaca só checa vazia/repetida | PASS |
| 21 | Diagrama PNG/PDF fundo branco, linhas pretas, nome no topo, igual ao código | diagrama-classes.png/.pdf (monochrome); inclui ControleMenu, sets, Reflexividade | PASS |

Pendências para o Alan (não são falhas): prazo da Parcial não publicado; confirmar com o professor se a classe `Leitura` (E/S) e o uso de `ArrayList`/`LocalDateTime` são aceitos; conferir o enunciado no Moodle antes de enviar (sujeito a alterações).
