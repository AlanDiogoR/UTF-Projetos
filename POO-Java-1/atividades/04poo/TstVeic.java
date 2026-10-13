// RA: 2809311
// Nome: Alan Diogo Ribeiro de Carvalho

import java.util.GregorianCalendar;

public class TstVeic {

    public static void main(String[] args) {
        Leitura leitura = new Leitura();

        // ---------- ENTRADA DE DADOS ----------
        int qtdPasseio = lerInteiro(leitura, "Quantos veiculos de passeio deseja cadastrar? ", 0);
        Passeio[] passeios = new Passeio[qtdPasseio];
        for (int i = 0; i < passeios.length; i++) {
            System.out.println();
            System.out.println("--- Cadastro do veiculo de passeio " + (i + 1) + " ---");
            passeios[i] = new Passeio();
            lerDadosComuns(leitura, passeios[i]);
            passeios[i].setQtdePassageiro(lerInteiro(leitura, "Quantidade de passageiros: ", 0));
        }

        System.out.println();
        int qtdCarga = lerInteiro(leitura, "Quantos veiculos de carga deseja cadastrar? ", 0);
        Carga[] cargas = new Carga[qtdCarga];
        for (int i = 0; i < cargas.length; i++) {
            System.out.println();
            System.out.println("--- Cadastro do veiculo de carga " + (i + 1) + " ---");
            cargas[i] = new Carga();
            lerDadosComuns(leitura, cargas[i]);
            cargas[i].setTara(lerInteiro(leitura, "Tara (Kg): ", 0));
            cargas[i].setCargaMax(lerInteiro(leitura, "Carga maxima (Kg): ", 0));
        }

        // ---------- SAIDA DE DADOS ----------
        for (int i = 0; i < passeios.length; i++) {
            System.out.println();
            System.out.println("===== VEICULO DE PASSEIO " + (i + 1) + " =====");
            imprimirDadosComuns(passeios[i]);
            System.out.println("Quantidade de passageiros: " + passeios[i].getQtdePassageiro());
            System.out.println("Velocidade maxima: " + passeios[i].calcVel() + " M/h");
            System.out.println("Soma das letras dos atributos String: " + passeios[i].calcular());
        }

        for (int i = 0; i < cargas.length; i++) {
            System.out.println();
            System.out.println("===== VEICULO DE CARGA " + (i + 1) + " =====");
            imprimirDadosComuns(cargas[i]);
            System.out.println("Tara: " + cargas[i].getTara() + " Kg");
            System.out.println("Carga maxima: " + cargas[i].getCargaMax() + " Kg");
            System.out.println("Velocidade maxima: " + cargas[i].calcVel() + " Cm/h");
            System.out.println("Soma dos atributos numericos: " + cargas[i].calcular());
        }
    }

    // Le os dados que Passeio e Carga herdam de Veiculo.
    // O Motor e instanciado aqui, sem declarar variavel do tipo Motor.
    private static void lerDadosComuns(Leitura leitura, Veiculo v) {
        v.setPlaca(leitura.entDados("Placa: "));
        v.setMarca(leitura.entDados("Marca: "));
        v.setModelo(leitura.entDados("Modelo: "));
        v.setCor(leitura.entDados("Cor: "));
        v.setQtdRodas(lerInteiro(leitura, "Quantidade de rodas: ", 0));

        int velocidade = lerInteiro(leitura, "Velocidade maxima (Km/h): ", Integer.MIN_VALUE);
        if (velocidade < 10 || velocidade > 250) {
            System.out.println("A velocidade est\u00e1 fora dos limites brasileiros");
            velocidade = 100;
        }
        v.setVelocMax(velocidade);

        v.setMotor(new Motor());
        v.getMotor().setQtdPistoes(lerInteiro(leitura, "Quantidade de pistoes do motor: ", 0));
        v.getMotor().setPotencia(lerInteiro(leitura, "Potencia do motor: ", 0));

        // Data de cadastro: capturada automaticamente da data do sistema
        GregorianCalendar hoje = new GregorianCalendar();
        v.setDataCadastro(String.format("%02d/%02d/%d",
                hoje.get(GregorianCalendar.DAY_OF_MONTH),
                hoje.get(GregorianCalendar.MONTH) + 1,
                hoje.get(GregorianCalendar.YEAR)));
    }

    private static void imprimirDadosComuns(Veiculo v) {
        System.out.println("Placa: " + v.getPlaca());
        System.out.println("Marca: " + v.getMarca());
        System.out.println("Modelo: " + v.getModelo());
        System.out.println("Cor: " + v.getCor());
        System.out.println("Quantidade de rodas: " + v.getQtdRodas());
        System.out.println("Motor: " + v.getMotor().getQtdPistoes() + " pistoes, potencia "
                + v.getMotor().getPotencia());
        System.out.println("Data de cadastro: " + v.getDataCadastro());
    }

    // Repete a pergunta ate o usuario digitar um inteiro valido (maior ou igual a minimo)
    private static int lerInteiro(Leitura leitura, String mensagem, int minimo) {
        while (true) {
            try {
                int valor = Integer.parseInt(leitura.entDados(mensagem));
                if (valor >= minimo) {
                    return valor;
                }
                System.out.println("Valor nao pode ser menor que " + minimo + ".");
            } catch (NumberFormatException e) {
                System.out.println("Digite um numero inteiro valido.");
            }
        }
    }
}
