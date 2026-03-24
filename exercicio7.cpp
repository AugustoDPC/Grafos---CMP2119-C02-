#include <iostream>
using namespace std;

int main() {
    int quantidadeVertices;
    int matrizAdjacencia[100][100];
    int grauDeCadaVertice[100];
    int quantidadeVerticesImpares = 0;
    int grafoEhSimples = 1;

    cout << "Digite a quantidade de vertices: ";
    cin >> quantidadeVertices;

    cout << "Digite a matriz de adjacencia:\n";
    for (int linha = 0; linha < quantidadeVertices; linha++) {
        for (int coluna = 0; coluna < quantidadeVertices; coluna++) {
            cin >> matrizAdjacencia[linha][coluna];
        }
    }

    for (int linha = 0; linha < quantidadeVertices; linha++) {
        if (matrizAdjacencia[linha][linha] != 0) {
            grafoEhSimples = 0;
        }

        for (int coluna = 0; coluna < quantidadeVertices; coluna++) {
            if (matrizAdjacencia[linha][coluna] != 0 && matrizAdjacencia[linha][coluna] != 1) {
                grafoEhSimples = 0;
            }

            if (matrizAdjacencia[linha][coluna] != matrizAdjacencia[coluna][linha]) {
                grafoEhSimples = 0;
            }
        }
    }

    if (grafoEhSimples == 0) {
        cout << "O grafo informado nao e simples\n";
        return 0;
    }

    for (int linha = 0; linha < quantidadeVertices; linha++) {
        grauDeCadaVertice[linha] = 0;

        for (int coluna = 0; coluna < quantidadeVertices; coluna++) {
            grauDeCadaVertice[linha] = grauDeCadaVertice[linha] + matrizAdjacencia[linha][coluna];
        }

        if (grauDeCadaVertice[linha] % 2 != 0) {
            quantidadeVerticesImpares = quantidadeVerticesImpares + 1;
        }
    }

    if (quantidadeVerticesImpares == 0) {
        cout << "O grafo possui ciclo euleriano\n";
    } else if (quantidadeVerticesImpares == 2) {
        cout << "O grafo possui caminho euleriano\n";
    } else {
        cout << "O grafo nao possui caminho nem ciclo euleriano\n";
    }

    return 0;
}