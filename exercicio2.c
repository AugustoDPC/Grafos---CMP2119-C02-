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

    // Zerar graus e adjacencia
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Digite a matriz de incidencia (%dx%d)\n", V, E);
    printf("Use +1 (origem), 0 (nada), -1 (destino):\n");

    // Le matriz e validar
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            scanf("%d", &inc[i][j]);
            if (inc[i][j] != -1 && inc[i][j] != 0 && inc[i][j] != 1) {
                printf("Deu erro: digite apenas -1, 0 ou 1.\n");
                return 1;
            }
        }
    }

    // Validar colunas e calcular graus
    for (int i = 0; i < E; i++) {
        int quantidadeOrigem = 0, quantidadeDestino = 0;

        for (int j = 0; j < V; j++) {
            if (inc[j][i] ==  1) { quantidadeOrigem++; }
            if (inc[j][i] == -1) { quantidadeDestino++;}
        }

        if (quantidadeOrigem != 1 || quantidadeDestino != 1) {
            printf("Deu erro: Coluna %d invalida. Deve ter 1 origem (+1) e 1 destino (-1).\n", i);
            return 1;
        }
    }

    printf("\nGraus dos Vertices\n");
    for(int i = 0; i < V; i++) {
        int grau_entrada = 0, grau_saida = 0;
        for(int j = 0; j < E; j++) {
            if(inc[i][j] == -1) grau_entrada++;
            if(inc[i][j] == 1) grau_saida++;
        }
        printf("Vertice %d = Grau Entrada: %d | Grau Saida: %d\n", i, grau_entrada, grau_saida);
    }

    for (int a = 0; a < E; a++) {
        int origem = -1, destino = -1;

        for (int v = 0; v < V; v++) {
            if (inc[v][a] ==  1) origem = v;
            if (inc[v][a] == -1) destino = v;
        }

        adj[origem][destino] = 1;
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