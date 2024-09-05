#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define o tamanho máximo da fila

typedef struct {
    int frente, tras, tamanho;
    int dados[MAX];
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

// Adiciona um elemento na fila
void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Erro: Fila cheia. Não é possível enfileirar %d\n", valor);
        return;
    }
    f->tras = (f->tras + 1) % MAX;
    f->dados[f->tras] = valor;
    f->tamanho++;
    printf("%d enfileirado com sucesso.\n", valor);
}

// Remove e retorna o elemento da frente da fila
int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia. Não é possível desenfileirar\n");
        return -1; // Valor indicando erro
    }
    int valor = f->dados[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return valor;
}

// Retorna o elemento da frente da fila sem removê-lo
int frenteFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Erro: Fila vazia.\n");
        return -1; // Valor indicando erro
    }
    return f->dados[f->frente];
}

// Imprime todos os elementos da fila
void imprimirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Elementos da fila:\n");
    for (int i = 0; i < f->tamanho; i++) {
        printf("%d\n", f->dados[(f->frente + i) % MAX]);
    }
}

int main() {
    Fila f;
    inicializarFila(&f);

    int escolha, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Mostrar frente\n");
        printf("4. Imprimir fila\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser enfileirado: ");
                scanf("%d", &valor);
                enfileirar(&f, valor);
                break;
            case 2:
                valor = desenfileirar(&f);
                if (valor != -1) {
                    printf("Desenfileirado: %d\n", valor);
                }
                break;
            case 3:
                valor = frenteFila(&f);
                if (valor != -1) {
                    printf("Frente da fila: %d\n", valor);
                }
                break;
            case 4:
                imprimirFila(&f);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao inválida.\n");
        }
    } while (escolha != 5);

    return 0;
}
