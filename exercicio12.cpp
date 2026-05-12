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

    for (int i = 0; i < n; i++) {
        if (grafo[i][i] != 0) {
            cout << "\nO grafo nao eh simples, pois possui laco.\n";
            return 0;
        }

        for (int j = 0; j < n; j++) {
            if (grafo[i][j] != grafo[j][i]) {
                cout << "\nO grafo nao eh simples, pois a matriz nao eh simetrica.\n";
                return 0;
            }
        }
    }

    int qtdSubgrafo;

    cout << "\n Digite a quantidade de vertices que o subgrafo tem: ";
    cin >> qtdSubgrafo;

    int subgrafo[qtdSubgrafo];

    while (qtdSubgrafo < 3 || qtdSubgrafo > n) {
            cout << "Vertice invalido. Digite novamente: ";
            cin >> qtdSubgrafo;
    }

    cout << "Digite os vertices do subgrafo:\n";

    for (int i = 0; i < qtdSubgrafo; i++) {
        cin >> subgrafo[i];

        while (subgrafo[i] < 0 || subgrafo[i] > n) {
            cout << "Vertice invalido. Digite novamente: ";
            cin >> subgrafo[i];
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
        cout << "\nO subgrafo informado eh um clique.\n";
    } else {
        cout << "\nO subgrafo informado nao eh um clique.\n";
    }

    return 0;
}