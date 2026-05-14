#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Quantos vertices o grafo tem? ";
    cin >> n;

    int grafo[n][n];

    cout << "\nDigite a matriz de adjacencia:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grafo[i][j];

            if (grafo[i][j] != 0 && grafo[i][j] != 1) {
                cout << "Valor invalido. Use apenas 0 ou 1.\n";
                return 0;
            }
        }
    }

    // Valida se e grafo simples
    for (int i = 0; i < n; i++) {
        if (grafo[i][i] != 0) {
            cout << "\nO grafo nao e simples, pois possui laco.\n";
            return 0;
        }

        for (int j = 0; j < n; j++) {
            if (grafo[i][j] != grafo[j][i]) {
                cout << "\nO grafo nao e simples, pois a matriz nao e simetrica.\n";
                return 0;
            }
        }
    }

    bool achouClique = false;

    // Testa todos os caminhos/subgrafos de 3 vertices
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {

                if (grafo[i][j] == 1 &&
                    grafo[i][k] == 1 &&
                    grafo[j][k] == 1) {

                    cout << "\nO grafo possui clique de tamanho 3.\n";
                    cout << "Clique encontrado: "
                         << i + 1 << " "
                         << j + 1 << " "
                         << k + 1 << "\n";

                    achouClique = true;
                }
            }
        }
    }

    if (!achouClique) {
        cout << "\nO grafo nao possui clique de tamanho 3.\n";
    }

    return 0;
}