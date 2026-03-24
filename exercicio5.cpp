#include <iostream>
using namespace std;

int main() {
    int n1, n2;
    int i, j, aux;
    int arestas1 = 0;
    int arestas2 = 0;

    cout << "Digite a quantidade de vertices do grafo 1: ";
    cin >> n1;

    cout << "Digite a quantidade de vertices do grafo 2: ";
    cin >> n2;

    if (n1 != n2) {
        cout << "NAO podem ser isomorfos.\n";
        cout << "Motivo: quantidade de vertices diferente.\n";
        return 0;
    }

    int g1[100][100];
    int g2[100][100];
    int graus1[100];
    int graus2[100];

    cout << "Digite a matriz do grafo 1:\n";
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n1; j++) {
            cin >> g1[i][j];
        }
    }

    cout << "Digite a matriz do grafo 2:\n";
    for (i = 0; i < n2; i++) {
        for (j = 0; j < n2; j++) {
            cin >> g2[i][j];
        }
    }

    // calcular graus do grafo 1
    for (i = 0; i < n1; i++) {
        graus1[i] = 0;
        for (j = 0; j < n1; j++) {
            graus1[i] = graus1[i] + g1[i][j];
        }
    }

    // calcular graus do grafo 2
    for (i = 0; i < n2; i++) {
        graus2[i] = 0;
        for (j = 0; j < n2; j++) {
            graus2[i] = graus2[i] + g2[i][j];
        }
    }

    // contar arestas do grafo 1
    for (i = 0; i < n1; i++) {
        for (j = i + 1; j < n1; j++) {
            if (g1[i][j] == 1) {
                arestas1++;
            }
        }
    }

    // contar arestas do grafo 2
    for (i = 0; i < n2; i++) {
        for (j = i + 1; j < n2; j++) {
            if (g2[i][j] == 1) {
                arestas2++;
            }
        }
    }

    if (arestas1 != arestas2) {
        cout << "NAO podem ser isomorfos.\n";
        cout << "Motivo: quantidade de arestas diferente.\n";
        return 0;
    }

    // ordenar graus1 manualmente
    for (i = 0; i < n1 - 1; i++) {
        for (j = i + 1; j < n1; j++) {
            if (graus1[i] > graus1[j]) {
                aux = graus1[i];
                graus1[i] = graus1[j];
                graus1[j] = aux;
            }
        }
    }

    // ordenar graus2 manualmente
    for (i = 0; i < n2 - 1; i++) {
        for (j = i + 1; j < n2; j++) {
            if (graus2[i] > graus2[j]) {
                aux = graus2[i];
                graus2[i] = graus2[j];
                graus2[j] = aux;
            }
        }
    }

    // comparar graus
    for (i = 0; i < n1; i++) {
        if (graus1[i] != graus2[i]) {
            cout << "NAO podem ser isomorfos.\n";
            cout << "Motivo: sequencia de graus diferente.\n";
            return 0;
        }
    }

    cout << "PODEM ser isomorfos.\n";

    return 0;
}