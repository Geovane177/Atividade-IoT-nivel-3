#include <stdio.h>
#include <string.h>

// Fun��o para buscar a substring no texto
int buscarPadrao(const char *texto, const char *padrao) {
    int textoLen = strlen(texto);
    int padraoLen = strlen(padrao);

    for (int i = 0; i <= textoLen - padraoLen; i++) {
        int j;
        for (j = 0; j < padraoLen; j++) {
            if (texto[i + j] != padrao[j]) {
                break;
            }
        }
        if (j == padraoLen) {
            return i; // Retorna a posi��o inicial do padr�o encontrado
        }
    }
    return -1; // Retorna -1 se o padr�o n�o for encontrado
}

int main() {
    const char texto[] = "Esta e uma simples demonstracao de reconhecimento de padroes.";
    const char padrao[] = "demonstracao";

    int posicao = buscarPadrao(texto, padrao);

    if (posicao != -1) {
        printf("Padrao encontrado na posicao %d.\n", posicao);
    } else {
        printf("Padrao n�o encontrado.\n");
    }

    return 0;
}

