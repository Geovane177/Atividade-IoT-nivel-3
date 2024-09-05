#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int topo;
    char itens[MAX];
} Pilha;

// Funções da pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

void empilhar(Pilha *p, char valor) {
    if (pilhaCheia(p)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

char desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia.\n");
        return '\0'; // Valor indicando erro
    }
    return p->itens[(p->topo)--];
}

char topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Erro: Pilha vazia.\n");
        return '\0'; // Valor indicando erro
    }
    return p->itens[p->topo];
}

// Funções auxiliares
int precedencia(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixaParaPosfixa(const char *expressao, char *resultado) {
    Pilha pilha;
    inicializarPilha(&pilha);

    int j = 0; // Índice para resultado
    for (int i = 0; expressao[i]; i++) {
        char c = expressao[i];

        if (isspace(c)) {
            continue;
        }

        if (isalnum(c)) {
            resultado[j++] = c;
        } else if (c == '(') {
            empilhar(&pilha, c);
        } else if (c == ')') {
            while (!pilhaVazia(&pilha) && topoPilha(&pilha) != '(') {
                resultado[j++] = desempilhar(&pilha);
            }
            if (!pilhaVazia(&pilha) && topoPilha(&pilha) == '(') {
                desempilhar(&pilha); // Remove o '(' da pilha
            }
        } else if (ehOperador(c)) {
            while (!pilhaVazia(&pilha) && precedencia(topoPilha(&pilha)) >= precedencia(c)) {
                resultado[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, c);
        }
    }

    // Desempilha todos os operadores restantes
    while (!pilhaVazia(&pilha)) {
        resultado[j++] = desempilhar(&pilha);
    }

    resultado[j] = '\0'; // Termina a string resultado
}

int main() {
    char expressao[MAX], resultado[MAX];

    printf("Digite a expressao infixa: ");
    fgets(expressao, MAX, stdin);

    // Remove o caractere de nova linha do final da string
    size_t len = strlen(expressao);
    if (len > 0 && expressao[len - 1] == '\n') {
        expressao[len - 1] = '\0';
    }

    infixaParaPosfixa(expressao, resultado);

    printf("Expressao pos-fixa: %s\n", resultado);

    return 0;
}
