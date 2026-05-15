#include <stdio.h>

void mostrarMatriz(int quantidadeVertices, int matriz[quantidadeVertices][quantidadeVertices]) {
    for (int i = 0; i < quantidadeVertices; i++) {
        for (int j = 0; j < quantidadeVertices; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int quantidadeVertices;

    printf("Digite a quantidade de vertices: ");
    scanf("%d", &quantidadeVertices);

    while (quantidadeVertices <= 0) {
        printf("Quantidade invalida. Digite novamente: ");
        scanf("%d", &quantidadeVertices);
    }

    int matrizAdjacencia[quantidadeVertices][quantidadeVertices];
    int matrizMultiplicadora[quantidadeVertices][quantidadeVertices];
    int matrizConexo[quantidadeVertices][quantidadeVertices];

    printf("\nDigite a matriz de adjacencia:\n");

    for (int i = 0; i < quantidadeVertices; i++) {
        for (int j = 0; j < quantidadeVertices; j++) {
            scanf("%d", &matrizAdjacencia[i][j]);

            while (matrizAdjacencia[i][j] != 0 && matrizAdjacencia[i][j] != 1) {
                printf("Valor invalido. Digite apenas 0 ou 1: ");
                scanf("%d", &matrizAdjacencia[i][j]);
            }

            matrizMultiplicadora[i][j] = matrizAdjacencia[i][j];
            matrizConexo[i][j] = matrizAdjacencia[i][j];
        }
    }

    for (int i = 0; i < quantidadeVertices; i++) {

        if (matrizAdjacencia[i][i] != 0) {
            printf("\nO grafo nao eh simples, pois possui laco.\n");
            return 0;
        }

        for (int j = 0; j < quantidadeVertices; j++) {
            if (matrizAdjacencia[i][j] != matrizAdjacencia[j][i]) {
                printf("\nO grafo nao eh simples, pois a matriz nao eh simetrica.\n");
                return 0;
            }
        }
    }

    printf("\nA1:\n");
    mostrarMatriz(quantidadeVertices, matrizMultiplicadora);

    for (int potencia = 2; potencia <= quantidadeVertices - 1; potencia++) {
        int matrizResultado[quantidadeVertices][quantidadeVertices];

        for (int i = 0; i < quantidadeVertices; i++) {
            for (int j = 0; j < quantidadeVertices; j++) {
                matrizResultado[i][j] = 0;

                for (int k = 0; k < quantidadeVertices; k++) {
                    matrizResultado[i][j] += matrizMultiplicadora[i][k] * matrizAdjacencia[k][j];
                }
            }
        }

        for (int i = 0; i < quantidadeVertices; i++) {
            for (int j = 0; j < quantidadeVertices; j++) {
                matrizMultiplicadora[i][j] = matrizResultado[i][j];
                matrizConexo[i][j] += matrizMultiplicadora[i][j];
            }
        }

        printf("\nA%d:\n", potencia);
        mostrarMatriz(quantidadeVertices, matrizMultiplicadora);
    }

    printf("\nMatriz acumuladora para ver se eh conexo ou nao:\n");
    mostrarMatriz(quantidadeVertices, matrizConexo);

    int grafoConexo = 1;

    for (int i = 0; i < quantidadeVertices; i++) {
        for (int j = 0; j < quantidadeVertices; j++) {
            if (i != j && matrizConexo[i][j] == 0) {
                grafoConexo = 0;
            }
        }
    }

    if (grafoConexo == 1) {
        printf("\nO grafo eh conexo.\n");
    } else {
        printf("\nO grafo eh desconexo.\n");
    }

    return 0;
}