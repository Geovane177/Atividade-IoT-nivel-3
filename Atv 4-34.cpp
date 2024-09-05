#include <stdio.h>
#include <stdlib.h>

// Fun��o para mesclar dois subarrays do array principal
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Cria arrays tempor�rios
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }

    // Copia dados para os arrays tempor�rios L[] e R[]
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Mescla os arrays tempor�rios de volta para arr[l..r]
    int i = 0; // �ndice inicial do primeiro subarray
    int j = 0; // �ndice inicial do segundo subarray
    int k = l; // �ndice inicial do subarray mesclado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Libera a mem�ria alocada para os arrays tempor�rios
    free(L);
    free(R);
}

// Fun��o para ordenar o array usando Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mescla as duas metades ordenadas
        merge(arr, l, m, r);
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

    // Ordena o array usando o Merge Sort
    mergeSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    imprimirArray(arr, n);

    // Libera a mem�ria alocada
    free(arr);

    return 0;
}
