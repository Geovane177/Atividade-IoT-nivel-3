#include <stdio.h>
#include <limits.h>

#define V 9 // N�mero de v�rtices no grafo

// Fun��o para encontrar o v�rtice com a dist�ncia m�nima que ainda n�o foi inclu�do no conjunto de v�rtices finais
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Fun��o para imprimir o array de dist�ncias
void printSolution(int dist[], int n) {
    printf("Vertice \t Distancia da Origem\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Fun��o que implementa o algoritmo de Dijkstra para um grafo representado por uma matriz de adjac�ncia
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para armazenar a dist�ncia mais curta de src para cada v�rtice
    int sptSet[V]; // Conjunto de v�rtices para os quais a dist�ncia m�nima foi encontrada

    // Inicializa todas as dist�ncias como infinito e sptSet[] como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // A dist�ncia do v�rtice de origem para ele mesmo � sempre 0
    dist[src] = 0;

    // Encontrar o caminho mais curto para todos os v�rtices
    for (int count = 0; count < V - 1; count++) {
        // Escolher o v�rtice com a dist�ncia m�nima do conjunto de v�rtices n�o processados
        int u = minDistance(dist, sptSet);

        // Marcar o v�rtice escolhido como processado
        sptSet[u] = 1;

        // Atualizar o valor das dist�ncias dos v�rtices adjacentes
        for (int v = 0; v < V; v++) {
            // Atualizar dist[v] se e somente se houver uma aresta de u para v, a dist�ncia total para v for menor que a dist�ncia atual e v ainda n�o estiver no conjunto de v�rtices finais
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Imprimir a solu��o
    printSolution(dist, V);
}

int main() {
    // Grafo representado por uma matriz de adjac�ncia
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    // A origem para a qual encontrar o caminho mais curto
    int src = 0;

    dijkstra(graph, src);

    return 0;
}

