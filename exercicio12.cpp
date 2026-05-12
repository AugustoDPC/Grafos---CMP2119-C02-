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

    int qtdSubgrafo;

    cout << "\nQuantos vertices tem o subgrafo? ";
    cin >> qtdSubgrafo;

    int subgrafo[qtdSubgrafo];

    cout << "Digite os vertices do subgrafo:\n";

    for (int i = 0; i < qtdSubgrafo; i++) {
        cin >> subgrafo[i];

        subgrafo[i]--; // transforma de 1..N para 0..N-1

        if (subgrafo[i] < 0 || subgrafo[i] >= n) {
            cout << "Vertice invalido.\n";
            return 0;
        }
    }

    bool clique = true;

    for (int i = 0; i < qtdSubgrafo; i++) {
        for (int j = i + 1; j < qtdSubgrafo; j++) {
            int v1 = subgrafo[i];
            int v2 = subgrafo[j];

            if (grafo[v1][v2] != 1) {
                clique = false;
            }
        }
    }

    if (clique) {
        cout << "\nO subgrafo informado e um clique.\n";
    } else {
        cout << "\nO subgrafo informado nao e um clique.\n";
    }

    return 0;
}