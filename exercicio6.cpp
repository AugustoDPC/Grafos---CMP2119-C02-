#include <iostream>
using namespace std;

const int MAXIMO_VERTICES = 100;

// Função para calcular os graus de todos os vértices
void calcularGrausDosVertices(int matrizAdjacencia[MAXIMO_VERTICES][MAXIMO_VERTICES], int quantidadeVertices, int grausDosVertices[MAXIMO_VERTICES]) {
    for (int linhaVertice = 0; linhaVertice < quantidadeVertices; linhaVertice++) {
        grausDosVertices[linhaVertice] = 0;

        for (int colunaVertice = 0; colunaVertice < quantidadeVertices; colunaVertice++) {
            if (matrizAdjacencia[linhaVertice][colunaVertice] == 1) {
                grausDosVertices[linhaVertice]++;
            }
        }
    }
}

// Função para verificar se é grafo completo
int verificarSeEhCompleto(int grausDosVertices[MAXIMO_VERTICES], int quantidadeVertices) {
    for (int verticeAtual = 0; verticeAtual < quantidadeVertices; verticeAtual++) {
        if (grausDosVertices[verticeAtual] != quantidadeVertices - 1) {
            return 0;
        }
    }

    return 1;
}

// Função para verificar se é ciclo
int verificarSeEhCiclo(int grausDosVertices[MAXIMO_VERTICES], int quantidadeVertices) {
    if (quantidadeVertices < 3) {
        return 0;
    }

    for (int verticeAtual = 0; verticeAtual < quantidadeVertices; verticeAtual++) {
        if (grausDosVertices[verticeAtual] != 2) {
            return 0;
        }
    }

    return 1;
}

// Função para verificar se é roda
int verificarSeEhRoda(int grausDosVertices[MAXIMO_VERTICES], int quantidadeVertices) {
    if (quantidadeVertices < 4) {
        return 0;
    }

    int quantidadeVerticesComGrauMaximo = 0;
    int quantidadeVerticesComGrauTres = 0;

    for (int verticeAtual = 0; verticeAtual < quantidadeVertices; verticeAtual++) {
        if (grausDosVertices[verticeAtual] == quantidadeVertices - 1) {
            quantidadeVerticesComGrauMaximo++;
        }

        if (grausDosVertices[verticeAtual] == 3) {
            quantidadeVerticesComGrauTres++;
        }
    }

    if (quantidadeVerticesComGrauMaximo == 1 && quantidadeVerticesComGrauTres == quantidadeVertices - 1) {
        return 1;
    }

    return 0;
}

int main() {
    int quantidadeVertices;
    int matrizAdjacencia[MAXIMO_VERTICES][MAXIMO_VERTICES];
    int grausDosVertices[MAXIMO_VERTICES];

    cout << "Digite a quantidade de vertices: ";
    cin >> quantidadeVertices;

    cout << "Digite a matriz de adjacencia:" << endl;
    for (int linhaVertice = 0; linhaVertice < quantidadeVertices; linhaVertice++) {
        for (int colunaVertice = 0; colunaVertice < quantidadeVertices; colunaVertice++) {
            cin >> matrizAdjacencia[linhaVertice][colunaVertice];
        }
    }

    calcularGrausDosVertices(matrizAdjacencia, quantidadeVertices, grausDosVertices);

    if (verificarSeEhCompleto(grausDosVertices, quantidadeVertices) == 1) {
        cout << "O grafo eh COMPLETO." << endl;
    } else {
        cout << "O grafo nao eh COMPLETO." << endl;
    }

    if (verificarSeEhCiclo(grausDosVertices, quantidadeVertices) == 1) {
        cout << "O grafo eh CICLO." << endl;
    } else {
        cout << "O grafo nao eh CICLO." << endl;
    }

    if (verificarSeEhRoda(grausDosVertices, quantidadeVertices) == 1) {
        cout << "O grafo eh RODA." << endl;
    } else {
        cout << "O grafo nao eh RODA." << endl;
    }

    return 0;
}