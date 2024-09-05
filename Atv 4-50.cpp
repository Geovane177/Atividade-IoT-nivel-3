#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fun��o para compress�o usando RLE
void compressaoRLE(const char *input, char *output) {
    int n = strlen(input);
    int j = 0; // �ndice para o array de sa�da

    for (int i = 0; i < n; i++) {
        // Contar o n�mero de ocorr�ncias consecutivas do caractere atual
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            i++;
            count++;
        }

        // Armazenar o caractere e a contagem na sa�da
        output[j++] = input[i];
        output[j++] = count + '0'; // Converter a contagem para caractere
    }
    output[j] = '\0'; // Terminar a string de sa�da
}

// Fun��o para descompress�o usando RLE
void descompressaoRLE(const char *input, char *output) {
    int n = strlen(input);
    int j = 0; // �ndice para o array de sa�da

    for (int i = 0; i < n; i += 2) {
        // O caractere atual � o caractere a ser repetido
        char caractere = input[i];
        // A contagem est� no pr�ximo caractere
        int count = input[i + 1] - '0'; // Converter o caractere para inteiro

        // Adicionar o caractere repetido na sa�da
        for (int k = 0; k < count; k++) {
            output[j++] = caractere;
        }
    }
    output[j] = '\0'; // Terminar a string de sa�da
}

int main() {
    const char textoOriginal[] = "aaabbbccccdd";
    char textoComprimido[100];
    char textoDescomprimido[100];

    // Compress�o
    compressaoRLE(textoOriginal, textoComprimido);
    printf("Texto original: %s\n", textoOriginal);
    printf("Texto comprimido: %s\n", textoComprimido);

    // Descompress�o
    descompressaoRLE(textoComprimido, textoDescomprimido);
    printf("Texto descomprimido: %s\n", textoDescomprimido);

    return 0;
}

