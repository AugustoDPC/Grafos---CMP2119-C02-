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

    for (int i = 0; i < quantidadeVertices; i++) {
        //verifica linha central
        if (matrizAdjacencia[i][i] != 0) {
            grafoEhSimples = 0;
        }

        for (int j = 0; j < quantidadeVertices; j++) {

            if (matrizAdjacencia[i][j] != matrizAdjacencia[j][i]) {
                grafoEhSimples = 0;
            }
        }
    }

    if (grafoEhSimples == 0) {
        cout << "O grafo informado nao e simples\n";
        return 0;
    }

    for (int i = 0; i < quantidadeVertices; i++) {
        grauDeCadaVertice[i] = 0;

        for (int j = 0; j < quantidadeVertices; j++) {
            grauDeCadaVertice[i] += matrizAdjacencia[i][j];
        }

        if (grauDeCadaVertice[i] % 2 != 0) {
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