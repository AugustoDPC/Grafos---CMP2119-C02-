import java.util.Scanner;

class ListaAdjacencia {
    int[] vizinhos;
    int quantidade;
}

public class MainS {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int vertices;

        System.out.print("Digite o numero de vertices do grafo: ");
        vertices = sc.nextInt();

        while (vertices <= 0) {
            System.out.print("Numero invalido. Digite novamente: ");
            vertices = sc.nextInt();
        }

        ListaAdjacencia[] lista = new ListaAdjacencia[vertices];

        // Entrada da lista de adjacência
        for (int i = 0; i < vertices; i++) {
            lista[i] = new ListaAdjacencia();

            System.out.print("\nQuantos vizinhos tem o vertice " + i + "? ");
            lista[i].quantidade = sc.nextInt();

            if (lista[i].quantidade > 0) {
                lista[i].vizinhos = new int[lista[i].quantidade];

                System.out.println("Digite os vizinhos do vertice " + i + ":");

                for (int j = 0; j < lista[i].quantidade; j++) {
                    lista[i].vizinhos[j] = sc.nextInt();
                }
            } else {
                lista[i].vizinhos = new int[0];
            }
        }

        int verticeInicial;

        System.out.print("\nDigite o vertice para iniciar a Busca em Largura (BFS): ");
        verticeInicial = sc.nextInt();

        while (verticeInicial < 0 || verticeInicial >= vertices) {
            System.out.print("Vertice invalido. Digite novamente: ");
            verticeInicial = sc.nextInt();
        }

        // Vetor para marcar os vértices visitados
        boolean[] visitado = new boolean[vertices];

        // Vetor para armazenar a distância em número de arestas
        int[] distancia = new int[vertices];

        for (int i = 0; i < vertices; i++) {
            distancia[i] = -1;
        }

        // Fila manual usando vetor
        int[] fila = new int[vertices];
        int inicioFila = 0;
        int fimFila = 0;

        // Coloca o vértice inicial na fila
        fila[fimFila] = verticeInicial;
        fimFila++;

        // Marca o vértice inicial como visitado
        visitado[verticeInicial] = true;

        // A distância do vértice inicial para ele mesmo é 0
        distancia[verticeInicial] = 0;

        System.out.print("\nOrdem de visita da BFS (Em niveis): ");

        // Enquanto a fila não estiver vazia
        while (inicioFila < fimFila) {

            // Remove o primeiro elemento da fila
            int atual = fila[inicioFila];
            inicioFila++;

            System.out.print(atual + " ");

            // Percorre todos os vizinhos do vértice atual
            for (int j = 0; j < lista[atual].quantidade; j++) {
                int vizinho = lista[atual].vizinhos[j];

                // Se o vizinho ainda não foi visitado
                if (!visitado[vizinho]) {
                    visitado[vizinho] = true;

                    // Calcula a distância do vizinho
                    distancia[vizinho] = distancia[atual] + 1;

                    // Coloca o vizinho no fim da fila
                    fila[fimFila] = vizinho;
                    fimFila++;
                }
            }
        }

        System.out.println("\n");

        System.out.println("Distancia do vertice inicial " + verticeInicial + " ate os demais:");

        for (int i = 0; i < vertices; i++) {
            if (distancia[i] == -1) {
                System.out.println("Vertice " + i + ": nao alcancado");
            } else {
                System.out.println("Vertice " + i + ": " + distancia[i] + " aresta(s)");
            }
        }

        sc.close();
    }
}