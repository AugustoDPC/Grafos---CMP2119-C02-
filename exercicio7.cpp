#include <iostream>
using namespace std;

int main() {
    int quantidadeVertices;
    int quantidadeVerticesImpares = 0;
    int grafoEhSimples = 1;

    cout << "Digite a quantidade de vertices: ";
    cin >> quantidadeVertices;
    while(quantidadeVertices <= 0) {
        cout<<"Numero invalido, digite um valor maior que 0: ";
        cin>>quantidadeVertices;
    }

    int matrizAdjacencia[quantidadeVertices][quantidadeVertices];
    int grauDeCadaVertice[quantidadeVertices];

    cout << "Digite a matriz de adjacencia:\n";
    for (int i = 0; i < quantidadeVertices; i++) {
        for (int j = 0; j < quantidadeVertices; j++) {
            cin >> matrizAdjacencia[i][j];
            while(matrizAdjacencia[i][j] != 0 && matrizAdjacencia[i][j] != 1) {
                 cout<<"Valor invalido - digite 0 ou 1";
                 cin>>matrizAdjacencia[i][j];
             }
        }
    }

    for (int linha = 0; linha < quantidadeVertices; linha++) {
        //verifica linha central
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
            grauDeCadaVertice[linha] += matrizAdjacencia[linha][coluna];
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