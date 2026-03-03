#include <stdio.h>

int main() {
    int V, E;

    printf("Digite o numero de vertices (V): ");
    scanf("%d", &V);

    printf("Digite o numero de arestas (E): ");
    scanf("%d", &E);

    if (V <= 0 || E < 0) {
        printf("Valores invalidos. V deve ser > 0 e E deve ser >= 0.\n");
        return 1;
    }

    int inc[V][E];
    int adj[V][V];
    int grauEntrada[V], grauSaida[V];

    // Zerar graus e adjacencia
    for (int i = 0; i < V; i++) {
        grauEntrada[i] = 0;
        grauSaida[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Digite a matriz de incidencia (%dx%d)\n", V, E);
    printf("Use +1 (origem), 0 (nada), -1 (destino):\n");

    // Ler matriz + validar -1/0/1
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            scanf("%d", &inc[i][j]);
            if (inc[i][j] != -1 && inc[i][j] != 0 && inc[i][j] != 1) {
                printf("Erro: digite apenas -1, 0 ou 1.\n");
                return 1;
            }
        }
    }

    // Validar colunas e calcular graus (tudo junto)
    for (int i = 0; i < E; i++) {
        int quantidadeOrigem = 0, quantidadeDestino = 0;

        for (int j = 0; j < V; j++) {
            if (inc[j][i] ==  1) { quantidadeOrigem++;  grauSaida[j]++; }
            if (inc[j][i] == -1) { quantidadeDestino++; grauEntrada[j]++; }
        }

        if (quantidadeOrigem != 1 || quantidadeDestino != 1) {
            printf("Erro: Coluna %d invalida. Deve ter 1 origem (+1) e 1 destino (-1).\n", i);
            return 1;
        }
    }

    printf("\nGraus dos vertices:\n");
    for (int v = 0; v < V; v++) {
        printf("Vertice %d - entrada = %d, saida = %d\n", v, grauEntrada[v], grauSaida[v]);
    }

    // Converter incidencia -> adjacencia
    for (int a = 0; a < E; a++) {
        int origem = -1, destino = -1;

        for (int v = 0; v < V; v++) {
            if (inc[v][a] ==  1) origem = v;
            if (inc[v][a] == -1) destino = v;
        }

        adj[origem][destino] += 1; // ou = 1 se quiser só 0/1
    }

    printf("\nMatriz de adjacencia (%dx%d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}