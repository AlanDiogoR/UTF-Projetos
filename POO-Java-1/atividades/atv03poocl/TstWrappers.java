// Aluno: Alan Diogo Ribeiro de Carvalho

public class TstWrappers {

    public static void main(String[] args) {
        Leitura leitura = new Leitura();
        TstInt tstInt = new TstInt();
        TstBool tstBool = new TstBool();
        TstChar tstChar = new TstChar();
        TstDoub tstDoub = new TstDoub();
        TstByte tstByte = new TstByte();
        TstShort tstShort = new TstShort();
        TstFloat tstFloat = new TstFloat();
        TstLong tstLong = new TstLong();

        int opcao = -1;
        while (opcao != 0) {
            System.out.println();
            System.out.println("USO DE CLASSES WRAPPERS");
            System.out.println("1) INTEGER");
            System.out.println("2) BOOLEAN");
            System.out.println("3) CHARACTER");
            System.out.println("4) DOUBLE");
            System.out.println("5) BYTE");
            System.out.println("6) SHORT");
            System.out.println("7) FLOAT");
            System.out.println("8) LONG");
            System.out.println("0) SAIR");

            try {
                opcao = tstInt.convertStr_Int(leitura.entDados("ESCOLHA UMA OPCAO: "));

                switch (opcao) {
                    case 1: {
                        int n = tstInt.convertStr_Int(leitura.entDados("Digite um numero inteiro: "));
                        System.out.println("Convertido para String: " + tstInt.convertInt_Str(n));
                        System.out.println("Em binario: " + tstInt.intParaBinario(n));
                        break;
                    }
                    case 2: {
                        System.out.println("(qualquer texto diferente de true e convertido para false)");
                        boolean a = tstBool.convertStr_Bool(leitura.entDados("Digite o valor de A (true/false): "));
                        boolean b = tstBool.convertStr_Bool(leitura.entDados("Digite o valor de B (true/false): "));
                        System.out.println("A = " + a + " e B = " + b);
                        System.out.println("A XOR B = " + tstBool.xorLogico(a, b));
                        break;
                    }
                    case 3: {
                        String frase = leitura.entDados("Digite uma frase: ");
                        System.out.println("Quantidade de digitos na frase: " + tstChar.contarDigitos(frase));
                        String lido = leitura.entDados("Digite um caractere: ");
                        if (lido.length() == 0) {
                            System.out.println("Nenhum caractere informado.");
                        } else {
                            char c = lido.charAt(0);
                            System.out.println(c + " -> " + tstChar.inverterCaixa(c));
                        }
                        break;
                    }
                    case 4: {
                        System.out.println("(use ponto como separador decimal)");
                        double x = tstDoub.convertStr_Doub(leitura.entDados("Digite o dividendo: "));
                        double y = tstDoub.convertStr_Doub(leitura.entDados("Digite o divisor: "));
                        System.out.println("Resultado da divisao: " + tstDoub.analisarDivisao(x, y));
                        break;
                    }
                    case 5: {
                        byte bt = tstByte.convertStr_Byte(leitura.entDados("Digite um valor entre -128 e 127: "));
                        System.out.println("Valor sem sinal (0 a 255): " + tstByte.byteSemSinal(bt));
                        break;
                    }
                    case 6: {
                        short s = tstShort.convertStr_Short(leitura.entDados("Digite um valor entre -32768 e 32767: "));
                        System.out.println("Com os bytes invertidos: " + tstShort.inverterBytes(s));
                        break;
                    }
                    case 7: {
                        System.out.println("(use ponto como separador decimal)");
                        float f = tstFloat.convertStr_Float(leitura.entDados("Digite um numero real: "));
                        System.out.println("Bits IEEE 754: " + tstFloat.bitsIEEE754(f));
                        break;
                    }
                    case 8: {
                        long l = tstLong.convertStr_Long(leitura.entDados("Digite um numero inteiro grande: "));
                        System.out.println("Em hexadecimal: " + tstLong.longParaHex(l));
                        break;
                    }
                    case 0:
                        System.out.println("Encerrando o programa.");
                        break;
                    default:
                        System.out.println("Opcao invalida.");
                        break;
                }
            } catch (NumberFormatException e) {
                System.out.println("Valor invalido ou fora da faixa do tipo: " + e.getMessage());
                opcao = -1;
            }
        }
    }
}
