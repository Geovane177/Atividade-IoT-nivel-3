#include <stdio.h>
#include <stdlib.h>

// Fun��o para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o para particionar o array e retornar o �ndice do piv�
int particionar(int arr[], int low, int high) {
    int pivo = arr[high]; // Piv� � o �ltimo elemento
    int i = (low - 1); // �ndice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual for menor ou igual ao piv�
        if (arr[j] <= pivo) {
            i++; // Incrementa o �ndice do menor elemento
            trocar(&arr[i], &arr[j]);
        }
    }

    // Troca o piv� com o elemento no �ndice i + 1
    trocar(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fun��o para implementar o algoritmo Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array e obt�m o �ndice do piv�
        int pi = particionar(arr, low, high);

        // Ordena as sublistas
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fun��o para imprimir um array
void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Solicita ao usu�rio o n�mero de elementos
    printf("Digite o n�mero de elementos: ");
    scanf("%d", &n);

    // Aloca mem�ria para o array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        return 1;
    }

    // Solicita ao usu�rio os elementos do array
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

    // Libera a mem�ria alocada
    free(arr);

    return 0;
}
