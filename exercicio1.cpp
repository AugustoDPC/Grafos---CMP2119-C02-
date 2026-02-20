#include <iostream>
using namespace std;

const int MAX = 100; // limite máximo de vértices

int main() {
    int matriz[MAX][MAX];
    int n;

    cout << "Digite o numero de vertices do grafo: ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Numero invalido de vertices." << endl;
        return 1;
    }

    // Leitura da matriz
    cout << "Digite a matriz de adjacencia (" << n << "x" << n << ")\n";
    cout << "Use apenas 0 (sem aresta) ou 1 (com aresta):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];

            if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                cout << "Erro: digite apenas 0 ou 1." << endl;
                return 1;
            }
        }
    }

    // Verificar diagonal (sem laço)
    for (int i = 0; i < n; i++) {
        if (matriz[i][i] != 0) {
            cout << "Erro: diagonal deve ser zero (sem lacos)." << endl;
            return 1;
        }
    }

    // Verificar simetria (grafo não direcionado)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                cout << "Erro: matriz nao e simetrica." << endl;
                return 1;
            }
        }
    }

    // Calcular grau dos vértices
    cout << "\nGraus dos vertices:\n";
    for (int i = 0; i < n; i++) {
        int grau = 0;
        for (int j = 0; j < n; j++) {
            grau += matriz[i][j];
        }
        cout << "Vertice " << i << " -> grau = " << grau << endl;
    }

    return 0;
}