#include <iostream>
using namespace std;

const int MAXIMO_VERTICES = 100;

void calcularGrausDosVertices(int matrizAdjacencia[MAXIMO_VERTICES][MAXIMO_VERTICES], int quantidadeVertices, int grausDosVertices[MAXIMO_VERTICES]) {
    for (int i = 0; i < quantidadeVertices; i++) {
        grausDosVertices[i] = 0;

        for (int j = 0; j < quantidadeVertices; j++) {
            if (matrizAdjacencia[i][j] == 1) {
                grausDosVertices[i]++;
            }
        }
    }
}


int verificarSeEhCompleto(int grausDosVertices[MAXIMO_VERTICES], int quantidadeVertices) {
    for (int i = 0; i < quantidadeVertices; i++) {
        if (grausDosVertices[i] != quantidadeVertices - 1) {
            return 0;
        }
    }

    return 1;
}

int verificarSeEhCiclo(int grausDosVertices[MAXIMO_VERTICES], int quantidadeVertices) {
    if (quantidadeVertices < 3) {
        return 0;
    }

    for (int i = 0; i < quantidadeVertices; i++) {
        if (grausDosVertices[i] != 2) {
            return 0;
        }
    }

    return 1;
}


int verificarSeEhRoda(int grausDosVertices[MAXIMO_VERTICES], int quantidadeVertices) {
    if (quantidadeVertices < 4) {
        return 0;
    }

    int quantidadeVerticesComGrauMaximo = 0;
    int quantidadeVerticesComGrauTres = 0;

    for (int i = 0; i < quantidadeVertices; i++) {
        if (grausDosVertices[i] == quantidadeVertices - 1) {
            quantidadeVerticesComGrauMaximo++;
        }
	
tarefas
	
2 hours ago

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
    while(quantidadeVertices <= 0) {
        cout<<"Numero invalido, digite um valor maior que 0: ";
        cin>>quantidadeVertices;
    }

    cout << "Digite a matriz de adjacencia:" << endl;
    for (int i = 0; i < quantidadeVertices; i++) {
        for (int j = 0; j < quantidadeVertices; j++) {
            cin >> matrizAdjacencia[i][j];
            while(matrizAdjacencia[i][j] != 0 && matrizAdjacencia[i][j] != 1) {
                 cout<<"Valor invalido - digite 0 ou 1";
                 cin>>matrizAdjacencia[i][j];
             }
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