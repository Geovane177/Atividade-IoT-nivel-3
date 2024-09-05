#include <stdio.h>
#include <stdlib.h>

void findLIS(int arr[], int n) {
    // Criar um array para armazenar o comprimento da LIS até cada índice
    int *lis = (int *)malloc(n * sizeof(int));
    int i, j, max_length = 0, max_index = 0;

    // Inicializar o comprimento da LIS para cada posição como 1
    for (i = 0; i < n; i++) {
        lis[i] = 1;
    }

    // Preencher o array lis[] usando a abordagem de programação dinâmica
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Encontrar o comprimento máximo da LIS e o índice final
    for (i = 0; i < n; i++) {
        if (lis[i] > max_length) {
            max_length = lis[i];
            max_index = i;
        }
    }

    // Imprimir a maior subsequência crescente
    int *subsequence = (int *)malloc(max_length * sizeof(int));
    int length = max_length;
    for (i = max_index; i >= 0; i--) {
        if (lis[i] == length) {
            subsequence[length - 1] = arr[i];
            length--;
        }
    }

    printf("A maior subsequencia crescente e: ");
    for (i = 0; i < max_length; i++) {
        printf("%d ", subsequence[i]);
    }
    printf("\n");

    // Liberar a memória alocada
    free(lis);
    free(subsequence);
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLIS(arr, n);

    return 0;
}
