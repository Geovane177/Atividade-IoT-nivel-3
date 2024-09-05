#include <stdio.h>

// Fun��o para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fun��o para implementar o algoritmo Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Flag para otimizar o algoritmo
        int trocou = 0;

        // Percorre a lista n�o ordenada
        for (int j = 0; j < n - i - 1; j++) {
            // Troca se o elemento atual � maior que o pr�ximo
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
                trocou = 1;
            }
        }

        // Se n�o houve trocas, a lista j� est� ordenada
        if (!trocou) {
            break;
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    imprimirArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado: \n");
    imprimirArray(arr, n);

    return 0;
}
