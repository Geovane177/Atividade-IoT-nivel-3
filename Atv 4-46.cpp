#include <stdio.h>
#include <limits.h>

#define V 9 // Número de vértices no grafo

// Função para encontrar o vértice com a distância mínima que ainda não foi incluído no conjunto de vértices finais
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

// Função para imprimir o array de distâncias
void printSolution(int dist[], int n) {
    printf("Vertice \t Distancia da Origem\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Função que implementa o algoritmo de Dijkstra para um grafo representado por uma matriz de adjacência
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // Array para armazenar a distância mais curta de src para cada vértice
    int sptSet[V]; // Conjunto de vértices para os quais a distância mínima foi encontrada

    // Inicializa todas as distâncias como infinito e sptSet[] como falso
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // A distância do vértice de origem para ele mesmo é sempre 0
    dist[src] = 0;

    // Encontrar o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolher o vértice com a distância mínima do conjunto de vértices não processados
        int u = minDistance(dist, sptSet);

        // Marcar o vértice escolhido como processado
        sptSet[u] = 1;

        // Atualizar o valor das distâncias dos vértices adjacentes
        for (int v = 0; v < V; v++) {
            // Atualizar dist[v] se e somente se houver uma aresta de u para v, a distância total para v for menor que a distância atual e v ainda não estiver no conjunto de vértices finais
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Imprimir a solução
    printSolution(dist, V);
}

int main() {
    // Grafo representado por uma matriz de adjacência
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

