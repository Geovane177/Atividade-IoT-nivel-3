#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Define o tamanho máximo da pilha

typedef struct {
    int topo; // Índice do topo da pilha
    int dados[MAX]; // Vetor para armazenar os dados
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1; // Pilha vazia
}

// Verifica se a pilha está cheia
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Verifica se a pilha está vazia
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// Adiciona um elemento na pilha
void empilhar(Pilha *p, int valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia. Não é possível empilhar %d\n", valor);
        return;
    }
    p->dados[++(p->topo)] = valor;
    printf("%d empilhado com sucesso.\n", valor);
}

// Remove e retorna o elemento do topo da pilha
int desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia. Não é possível desempilhar\n");
        return -1; // Valor indicando erro
    }
    return p->dados[(p->topo)--];
}

// Retorna o elemento do topo da pilha sem removê-lo
int topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia.\n");
        return -1; // Valor indicando erro
    }
    return p->dados[p->topo];
}

// Imprime todos os elementos da pilha
void imprimirPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Elementos da pilha:\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d\n", p->dados[i]);
    }
}

int main() {
    Pilha p;
    inicializarPilha(&p);

    int escolha, valor;

    do {
        printf("\nMenu:\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Mostrar topo\n");
        printf("4. Imprimir pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%d", &valor);
                empilhar(&p, valor);
                break;
            case 2:
                valor = desempilhar(&p);
                if (valor != -1) {
                    printf("Desempilhado: %d\n", valor);
                }
                break;
            case 3:
                valor = topoPilha(&p);
                if (valor != -1) {
                    printf("Topo da pilha: %d\n", valor);
                }
                break;
            case 4:
                imprimirPilha(&p);
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
