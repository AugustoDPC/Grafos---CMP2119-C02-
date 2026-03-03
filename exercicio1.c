#include <stdio.h>

#define MAX 10

int main() {
    int matriz[MAX][MAX];
    int n;

    printf("Digite o numero de vertices do grafo: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Numero invalido de vertices.\n");
        return 1;
    }

    printf("Digite a matriz de adjacencia (%dx%d)\n", n, n);
    printf("Use apenas 0 ou 1:\n");

    // Ler matriz + validar 0/1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);

            if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                printf("Erro: digite apenas 0 ou 1.\n");
                return 1;
            }
        }
    }

    // Verificar simetria (grafo não direcionado)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                printf("Erro: matriz nao e simetrica.\n");
                return 1;
            }
        }
    }

    // Calcular grau dos vertices
    printf("\nGraus dos vertices:\n");
    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++) {
            grau += matriz[i][j];
        }
        printf("Vertice %d - grau = %d\n", i, grau);
    }
    
    printf("\nResultado do grafo:\n");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}