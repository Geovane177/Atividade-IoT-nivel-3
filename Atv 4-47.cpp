#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura para representar uma aresta
typedef struct {
    int origem, destino, peso;
} Aresta;

// Estrutura para representar um subconjunto para o algoritmo de União-Find
typedef struct {
    int pai, rank;
} Subconjunto;

// Função para comparar duas arestas com base no peso
int comparar(const void *a, const void *b) {
    return ((Aresta *)a)->peso - ((Aresta *)b)->peso;
}

// Função para encontrar o representante de um subconjunto
int encontrar(Subconjunto subconjuntos[], int i) {
    if (subconjuntos[i].pai != i) {
        subconjuntos[i].pai = encontrar(subconjuntos, subconjuntos[i].pai);
    }
    return subconjuntos[i].pai;
}

// Função para unir dois subconjuntos
void unir(Subconjunto subconjuntos[], int x, int y) {
    int raizX = encontrar(subconjuntos, x);
    int raizY = encontrar(subconjuntos, y);

    if (subconjuntos[raizX].rank < subconjuntos[raizY].rank) {
        subconjuntos[raizX].pai = raizY;
    } else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank) {
        subconjuntos[raizY].pai = raizX;
    } else {
        subconjuntos[raizY].pai = raizX;
        subconjuntos[raizX].rank++;
    }
}

// Função principal que implementa o algoritmo de Kruskal
void kruskal(Aresta arestas[], int numVertices, int numArestas) {
    Aresta resultado[MAX]; // Array para armazenar a MST
    int e = 0; // Contador de arestas para a MST
    int i = 0; // Índice usado para as arestas classificadas
    Subconjunto subconjuntos[MAX];

    // Passo 1: Ordenar todas as arestas em ordem crescente de peso
    qsort(arestas, numArestas, sizeof(arestas[0]), comparar);

    // Inicializar subconjuntos
    for (int v = 0; v < numVertices; ++v) {
        subconjuntos[v].pai = v;
        subconjuntos[v].rank = 0;
    }

    // Passo 2: Processar as arestas ordenadas e construir a MST
    while (e < numVertices - 1 && i < numArestas) {
        Aresta proximaAresta = arestas[i++];

        int x = encontrar(subconjuntos, proximaAresta.origem);
        int y = encontrar(subconjuntos, proximaAresta.destino);

        // Se adicionar esta aresta não causar um ciclo
        if (x != y) {
            resultado[e++] = proximaAresta;
            unir(subconjuntos, x, y);
        }
    }

    // Imprimir a MST
    printf("Arestas na arvore geradora minima:\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", resultado[i].origem, resultado[i].destino, resultado[i].peso);
    }
}

int main() {
    int numVertices = 4; // Número de vértices
    int numArestas = 5;  // Número de arestas

    // Arestas do grafo
    Aresta arestas[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // Executar o algoritmo de Kruskal
    kruskal(arestas, numVertices, numArestas);

    return 0;
}

