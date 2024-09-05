#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para compressão usando RLE
void compressaoRLE(const char *input, char *output) {
    int n = strlen(input);
    int j = 0; // Índice para o array de saída

    for (int i = 0; i < n; i++) {
        // Contar o número de ocorrências consecutivas do caractere atual
        int count = 1;
        while (i < n - 1 && input[i] == input[i + 1]) {
            i++;
            count++;
        }

        // Armazenar o caractere e a contagem na saída
        output[j++] = input[i];
        output[j++] = count + '0'; // Converter a contagem para caractere
    }
    output[j] = '\0'; // Terminar a string de saída
}

// Função para descompressão usando RLE
void descompressaoRLE(const char *input, char *output) {
    int n = strlen(input);
    int j = 0; // Índice para o array de saída

    for (int i = 0; i < n; i += 2) {
        // O caractere atual é o caractere a ser repetido
        char caractere = input[i];
        // A contagem está no próximo caractere
        int count = input[i + 1] - '0'; // Converter o caractere para inteiro

        // Adicionar o caractere repetido na saída
        for (int k = 0; k < count; k++) {
            output[j++] = caractere;
        }
    }
    output[j] = '\0'; // Terminar a string de saída
}

int main() {
    const char textoOriginal[] = "aaabbbccccdd";
    char textoComprimido[100];
    char textoDescomprimido[100];

    // Compressão
    compressaoRLE(textoOriginal, textoComprimido);
    printf("Texto original: %s\n", textoOriginal);
    printf("Texto comprimido: %s\n", textoComprimido);

    // Descompressão
    descompressaoRLE(textoComprimido, textoDescomprimido);
    printf("Texto descomprimido: %s\n", textoDescomprimido);

    return 0;
}

