#include <stdio.h>

int main() {
    int vertices, arestas;

    printf("Digite o numero de vertices: ");
    scanf("%d", &vertices);

    printf("Digite o numero de arestas: ");
    scanf("%d", &arestas);

    if (vertices <= 0 || arestas < 0) {
        printf("Valores invalidos.\n");
        return 1;
    }

    int incidencia[vertices][arestas];
    int adjacencia[vertices][vertices];
    int grauEntrada[vertices], grauSaida[vertices];

    printf("Digite a matriz de incidencia (%dx%d)\n", vertices, arestas);
    printf("Use 1 (origem), 0 (nada), -1 (destino):\n");

    // Ler e validar valores
    for (int v = 0; v < vertices; v++) {
        for (int a = 0; a < arestas; a++) {
            scanf("%d", &incidencia[v][a]);
            if (incidencia[v][a] != -1 && incidencia[v][a] != 0 && incidencia[v][a] != 1) {
                printf("Erro: use apenas -1, 0 ou 1.\n");
                return 1;
            }
        }
    }

    // Zerar graus e adjacencia
    for (int v = 0; v < vertices; v++) {
        grauEntrada[v] = 0;
        grauSaida[v] = 0;
        for (int u = 0; u < vertices; u++) {
            adjacencia[v][u] = 0;
        }
    }

    // Validar colunas (arestas) e calcular graus
    for (int a = 0; a < arestas; a++) {
        int qtdOrigem = 0, qtdDestino = 0;

        for (int v = 0; v < vertices; v++) {
            if (incidencia[v][a] == 1)  { qtdOrigem++;  grauSaida[v]++; }
            if (incidencia[v][a] == -1) { qtdDestino++; grauEntrada[v]++; }
        }

        if (qtdOrigem != 1 || qtdDestino != 1) {
            printf("Erro: aresta (coluna) %d invalida. Deve ter 1 origem (1) e 1 destino (-1).\n", a);
            return 1;
        }
    }

    printf("\nGraus dos vertices:\n");
    for (int v = 0; v < vertices; v++) {
        printf("Vertice %d - entrada = %d, saida = %d\n", v, grauEntrada[v], grauSaida[v]);
    }

    // Converter incidencia -> adjacencia
    for (int a = 0; a < arestas; a++) {
        int origem = -1, destino = -1;

        for (int v = 0; v < vertices; v++) {
            if (incidencia[v][a] == 1)  origem = v;
            if (incidencia[v][a] == -1) destino = v;
        }

        // (Se quiser 0/1 em vez de contar, troque += 1 por = 1)
        adjacencia[origem][destino] += 1;
    }

    printf("\nMatriz de adjacencia (%dx%d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencia[i][j]);
        }
        printf("\n");
    }

    return 0;
}