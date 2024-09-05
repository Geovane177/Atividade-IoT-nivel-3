#include <stdio.h>
#include <stdlib.h>

#define ANDARES 10 // Número de andares no prédio

// Estrutura para representar um pedido
typedef struct Pedido {
    int andar;
    struct Pedido *proximo;
} Pedido;

// Estrutura para representar o elevador
typedef struct Elevador {
    int andarAtual;
    int direcao; // 1 para cima, -1 para baixo, 0 para parado
    Pedido *pedidos;
} Elevador;

// Função para criar um novo pedido
Pedido* criarPedido(int andar) {
    Pedido *novoPedido = (Pedido*)malloc(sizeof(Pedido));
    novoPedido->andar = andar;
    novoPedido->proximo = NULL;
    return novoPedido;
}

// Função para adicionar um pedido à fila
void adicionarPedido(Elevador *elevador, int andar) {
    Pedido *novoPedido = criarPedido(andar);
    if (elevador->pedidos == NULL) {
        elevador->pedidos = novoPedido;
    } else {
        Pedido *temp = elevador->pedidos;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoPedido;
    }
}

// Função para remover o próximo pedido da fila
int proximoPedido(Elevador *elevador) {
    if (elevador->pedidos == NULL) {
        return -1; // Sem pedidos
    }
    int andar = elevador->pedidos->andar;
    Pedido *temp = elevador->pedidos;
    elevador->pedidos = elevador->pedidos->proximo;
    free(temp);
    return andar;
}

// Função para mover o elevador
void moverElevador(Elevador *elevador) {
    if (elevador->pedidos == NULL) {
        printf("Elevador esta parado. Sem pedidos.\n");
        return;
    }

    int proximo = proximoPedido(elevador);
    if (proximo == -1) return;

    if (elevador->andarAtual < proximo) {
        elevador->direcao = 1; // Subindo
        while (elevador->andarAtual < proximo) {
            printf("Elevador subindo. Andar atual: %d\n", ++elevador->andarAtual);
        }
    } else if (elevador->andarAtual > proximo) {
        elevador->direcao = -1; // Descendo
        while (elevador->andarAtual > proximo) {
            printf("Elevador descendo. Andar atual: %d\n", --elevador->andarAtual);
        }
    }

    printf("Elevador chegou ao andar %d.\n", elevador->andarAtual);
    elevador->direcao = 0; // Parado
}

// Função para exibir o estado do elevador
void exibirEstado(Elevador *elevador) {
    printf("Andar Atual: %d\n", elevador->andarAtual);
    printf("Direcao: %s\n", (elevador->direcao == 1) ? "Subindo" : (elevador->direcao == -1) ? "Descendo" : "Parado");
}

// Função principal
int main() {
    Elevador elevador = {0, 0, NULL}; // Elevador começa no andar 0, parado e sem pedidos

    adicionarPedido(&elevador, 5);
    adicionarPedido(&elevador, 2);
    adicionarPedido(&elevador, 7);

    while (elevador.pedidos != NULL) {
        exibirEstado(&elevador);
        moverElevador(&elevador);
    }

    exibirEstado(&elevador);
    return 0;
}

