#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Função para criptografar uma mensagem usando a cifra de César
void cipher(char *text, int shift) {
    while (*text) {
        if (isalpha(*text)) {
            char base = islower(*text) ? 'a' : 'A';
            *text = (char)(((*text - base + shift) % ALPHABET_SIZE + ALPHABET_SIZE) % ALPHABET_SIZE + base);
        }
        text++;
    }
}

int main() {
    char text[256];
    int shift;

    printf("Digite a mensagem (max 255 caracteres): ");
    fgets(text, sizeof(text), stdin);

    // Remove o caractere de nova linha se presente
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    printf("Digite o valor do deslocamento (inteiro): ");
    scanf("%d", &shift);

    // Garantir que o deslocamento esteja no intervalo de 0 a 25
    shift = (shift % ALPHABET_SIZE + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Sempre criptografa a mensagem
    cipher(text, shift);
    printf("Mensagem criptografada: %s\n", text);

    return 0;
}
