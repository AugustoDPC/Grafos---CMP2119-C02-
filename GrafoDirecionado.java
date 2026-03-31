import java.util.Scanner;

class ListaAdjacencia {
    int[] vizinhos;
    int quantidade;
}

public class GrafoDirecionado {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int vertices;

        System.out.print("Digite o numero de vertices do grafo direcionado: ");
        vertices = scanner.nextInt();
        while (vertices <= 0) {
            System.out.print("Numero invalido. Digite novamente: ");
            vertices = scanner.nextInt();
        }

        // Criando o array de listas de adjacência
        ListaAdjacencia[] lista = new ListaAdjacencia[vertices];
        for (int i = 0; i < vertices; i++) {
            lista[i] = new ListaAdjacencia();
        }

        // Entrada da Lista
        for (int i = 0; i < vertices; i++) {
            System.out.print("\nQuantos vertices estao ligados ao vertice " + i + "? ");
            lista[i].quantidade = scanner.nextInt();

            while (lista[i].quantidade < 0 || lista[i].quantidade > vertices -1) {
                System.out.print("Quantidade invalida. Tente novamente: ");
                lista[i].quantidade = scanner.nextInt();
            }

            if (lista[i].quantidade > 0) {
                lista[i].vizinhos = new int[lista[i].quantidade];

                System.out.println("Digite os vertices ligados ao vertice " + i + ":");
                for (int j = 0; j < lista[i].quantidade; j++) {
                    lista[i].vizinhos[j] = scanner.nextInt();

                    while (lista[i].vizinhos[j] < 0 || lista[i].vizinhos[j] >= vertices -1) {
                        System.out.print("Vertice invalido. Digite novamente: ");
                        lista[i].vizinhos[j] = scanner.nextInt();
                    }
                }
            }
        }

        int verticesInicial = 0;

        System.out.print("Digite o numero de vertices do que comeca o dfs: ");
        verticesInicial = scanner.nextInt();
        while (verticesInicial <= 0) {
            System.out.print("Numero invalido. Digite novamente: ");
            verticesInicial = scanner.nextInt();
        }


        //DFS 
        int[] visitado = new int[vertices];
        int[] na_trilha = new int[vertices];
        
        int tem_ciclo = 0;
        int[] pilha = new int[vertices * 2];
        int[] acoes = new int[vertices * 2];
        int topo = 0;

        for (int inicio = 0; inicio < vertices; inicio++) {
            if (visitado[inicio] == 0 && tem_ciclo == 0) {
                
                pilha[topo] = verticesInicial;
                acoes[topo] = 0; 
                topo++;

                while (topo > 0) {
                    topo--;
                    int atual = pilha[topo];
                    int acao = acoes[topo];

                    if (acao == 1) {
                        na_trilha[atual] = 0; // sai da trilha
                    } 
                    else if (visitado[atual] == 0) {
                        visitado[atual] = 1;  
                        na_trilha[atual] = 1;

                        pilha[topo] = atual;
                        acoes[topo] = 1;
                        topo++;

                        // Percorre os vizinhos
                        for (int j = 0; j < lista[atual].quantidade; j++) {
                            int vizinho = lista[atual].vizinhos[j];
                            
                            if (na_trilha[vizinho] == 1) {
                                tem_ciclo = 1; 
                                topo = 0; 
                                break;
                            }
                            
                            if (visitado[vizinho] == 0) {
                                pilha[topo] = vizinho;
                                acoes[topo] = 0;
                                topo++;
                            }
                        }
                    }
                }
            }
        }

        System.out.println("\n--- Resultado DFS ---");
        if (tem_ciclo == 1) System.out.println("O grafo direcionado POSSUI um ciclo.");
        else System.out.println("O grafo direcionado NAO possui ciclos.");

        scanner.close();
    }
}