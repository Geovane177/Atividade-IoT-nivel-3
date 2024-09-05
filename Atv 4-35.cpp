#include <stdio.h>
#include <stdlib.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para particionar o array e retornar o índice do pivô
int particionar(int arr[], int low, int high) {
    int pivo = arr[high]; // Pivô é o último elemento
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }

    // Troca o pivô com o elemento no índice i + 1
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função para implementar o algoritmo Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pi = particionar(arr, low, high);

        // Ordena as sublistas
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir um array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Solicita ao usuário o número de elementos
    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Aloca memória para o array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Solicita ao usuário os elementos do array
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original: \n");
    imprimirArray(arr, n);

    // Ordena o array usando o Quick Sort
    quickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    imprimirArray(arr, n);

    // Libera a memória alocada
    free(arr);

    return 0;
}
