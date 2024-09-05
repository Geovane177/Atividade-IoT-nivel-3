#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Pilha;

// Funcoes da pilha
void init(Pilha *p) {
    p->top = -1;
}

int isEmpty(Pilha *p) {
    return p->top == -1;
}

int isFull(Pilha *p) {
    return p->top == MAX_SIZE - 1;
}

void push(Pilha *p, int valor) {
    if (isFull(p)) {
        printf("Pilha cheia\n");
        exit(1);
    }
    p->items[++(p->top)] = valor;
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha vazia\n");
        exit(1);
    }
    return p->items[(p->top)--];
}

// Funcao para avaliar a expressao pos-fixa
int avaliarPosfixa(char *expressao) {
    Pilha p;
    init(&p);
    char *c = expressao;
    int a, b;

    while (*c) {
        if (isspace(*c)) {
            c++;
            continue;
        }

        if (isdigit(*c)) {
            int num = 0;
            while (isdigit(*c)) {
                num = num * 10 + (*c - '0');
                c++;
            }
            push(&p, num);
        } else {
            b = pop(&p);
            a = pop(&p);

            switch (*c) {
                case '+': push(&p, a + b); break;
                case '-': push(&p, a - b); break;
                case '*': push(&p, a * b); break;
                case '/': push(&p, a / b); break;
                default:
                    printf("Operador nao suportado: %c\n", *c);
                    exit(1);
            }
            c++;
        }
    }

    if (p.top != 0) {
        printf("Erro na expressao\n");
        exit(1);
    }

    return pop(&p);
}

int main() {
    char expressao[MAX_SIZE];

    printf("Digite uma expressao pos-fixa: ");
    fgets(expressao, sizeof(expressao), stdin);

    int resultado = avaliarPosfixa(expressao);
    printf("Resultado: %d\n", resultado);

    return 0;
}

