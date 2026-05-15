import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int quantidadeVertices;

        System.out.print("Digite a quantidade de vertices: ");
        quantidadeVertices = sc.nextInt();

        while (quantidadeVertices <= 0) {
            System.out.print("Quantidade invalida. Digite novamente: ");
            quantidadeVertices = sc.nextInt();
        }

        int[][] matrizAdjacencia = new int[quantidadeVertices][quantidadeVertices];
        int[][] matrizMultiplicadora = new int[quantidadeVertices][quantidadeVertices];
        int[][] matrizConexo = new int[quantidadeVertices][quantidadeVertices];

        System.out.println("\nDigite a matriz de adjacencia:");

        for (int i = 0; i < quantidadeVertices; i++) {
            for (int j = 0; j < quantidadeVertices; j++) {
                matrizAdjacencia[i][j] = sc.nextInt();

                while (matrizAdjacencia[i][j] != 0 && matrizAdjacencia[i][j] != 1) {
                    System.out.print("Valor invalido. Digite apenas 0 ou 1: ");
                    matrizAdjacencia[i][j] = sc.nextInt();
                }

                matrizMultiplicadora[i][j] = matrizAdjacencia[i][j];
                matrizConexo[i][j] = matrizAdjacencia[i][j];
            }
        }
        
        for (int i = 0; i < quantidadeVertices; i++) {

            if (matrizAdjacencia[i][i] != 0) {
                System.out.println("\nO grafo nao eh simples, pois possui laco.");
                sc.close();
                return;
            }

            for (int j = 0; j < quantidadeVertices; j++) {
                if (matrizAdjacencia[i][j] != matrizAdjacencia[j][i]) {
                    System.out.println("\nO grafo nao eh simples, pois a matriz nao eh simetrica.");
                    sc.close();
                    return;
                }
            }
        }

        System.out.println("\nA1:");
        mostrarMatriz(matrizMultiplicadora, quantidadeVertices);

        for (int comprimento = 2; comprimento <= quantidadeVertices - 1; comprimento++) {
            int[][] matrizResultado = new int[quantidadeVertices][quantidadeVertices];

            for (int i = 0; i < quantidadeVertices; i++) {
                for (int j = 0; j < quantidadeVertices; j++) {
                    matrizResultado[i][j] = 0;

                    for (int k = 0; k < quantidadeVertices; k++) {
                        matrizResultado[i][j] += matrizMultiplicadora[i][k] * matrizAdjacencia[k][j];
                    }
                }
            }

            matrizMultiplicadora = matrizResultado;

            for (int i = 0; i < quantidadeVertices; i++) {
                for (int j = 0; j < quantidadeVertices; j++) {
                    matrizConexo[i][j] += matrizMultiplicadora[i][j];
                }
            }

            System.out.println("\nA" + comprimento + ":");
            mostrarMatriz(matrizMultiplicadora, quantidadeVertices);
        }

        System.out.println("\nMatriz acumuladora para ver se é conexo ou  nao:");
        mostrarMatriz(matrizConexo, quantidadeVertices);

        boolean grafoConexo = true;

        for (int i = 0; i < quantidadeVertices; i++) {
            for (int j = 0; j < quantidadeVertices; j++) {
                if (i != j && matrizConexo[i][j] == 0) {
                    grafoConexo = false;
                }
            }
        }

        if (grafoConexo) {
            System.out.println("\nO grafo eh conexo.");
        } else {
            System.out.println("\nO grafo eh desconexo.");
        }

        sc.close();
    }

    public static void mostrarMatriz(int[][] matriz, int quantidadeVertices) {
        for (int i = 0; i < quantidadeVertices; i++) {
            for (int j = 0; j < quantidadeVertices; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }
}