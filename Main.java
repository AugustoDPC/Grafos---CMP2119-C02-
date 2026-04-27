import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class ListaAdjacencia {
    int[] vizinhos;
    int quantidade;
}

public class Main {

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

        boolean[] visitado = new boolean[vertices];
        int[] distancia = new int[vertices];

        for (int i = 0; i < vertices; i++) {
            distancia[i] = -1;
        }

        Queue<Integer> fila = new LinkedList<>();

        fila.add(verticeInicial);
        visitado[verticeInicial] = true;
        distancia[verticeInicial] = 0;

        System.out.print("\nOrdem de visita da BFS (Em niveis): ");

        while (!fila.isEmpty()) {
            int atual = fila.poll();

            System.out.print(atual + " ");

            for (int j = 0; j < lista[atual].quantidade; j++) {
                int vizinho = lista[atual].vizinhos[j];

                if (!visitado[vizinho]) {
                    visitado[vizinho] = true;
                    distancia[vizinho] = distancia[atual] + 1;
                    fila.add(vizinho);
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