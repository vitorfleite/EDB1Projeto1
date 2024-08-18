#include "FuncoesAuxiliares.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirmenu() {
    printf("\n-------  Restaurante X Lista de opções :     ----------\n");
    printf("1 - Listar pratos do menu\n");
    printf("2 - Adicionar pedido\n");
    printf("3 - Adicionar prato em um pedido\n");
    printf("4 - Remover pedido\n");
    printf("5 - Processar pedido\n");
    printf("6 - Listar Pedidos Pendentes\n");
    printf("7 - Listar Pedidos em Processamento\n");
    printf("8 - Sair\n");
    printf("Escolha uma opção: ");
}

void adicionarPedido(PedidoNode **head, Prato *pratos, int pratosCount, int novoPedidoId) {
    PedidoNode *novoPedido = malloc(sizeof(PedidoNode));
    if (novoPedido == NULL) {
        printf("Erro ao alocar memória para novo pedido.\n");
        return;
    }
    novoPedido->id = novoPedidoId;
    novoPedido->pratos = malloc(sizeof(Prato) * pratosCount);
    if (novoPedido->pratos == NULL) {
        printf("Erro ao alocar memória para os pratos do pedido.\n");
        free(novoPedido);
        return;
    }
    for (int i = 0; i < pratosCount; i++) {
        novoPedido->pratos[i] = pratos[i];
    }
    novoPedido->pratosCount = pratosCount;
    novoPedido->next = *head;
    *head = novoPedido;
    printf("Pedido adicionado: %s\n", pratos[0].nome);
}


void listarPedidosPendentes(PedidoNode *head) {
    if (head == NULL) {
        printf("Não há pedidos pendentes.\n");
        return;
    }
    printf("\nPedidos Pendentes:\n");
    PedidoNode *current = head;
    int pedidoId = 1;
    while (current != NULL) {
        printf("Pedido %d:\n", current->id);
        for (int i = 0; i < current->pratosCount; i++) {
            printf(" Prato: %s\n", current->pratos[i].nome);
        }
        current = current->next;
        pedidoId++;
    }
}

void listarPedidosProcessamento(PedidoNode *head) {
    if (head == NULL) {
        printf("Não há pedidos em processamento.\n");
    return;
    }
    printf("\nPedidos em processamento:\n");
    PedidoNode *current = head;
    int pedidoId = 1;
    while (current != NULL) {
        printf("Pedido %d:\n", pedidoId);
        for (int i = 0; i < current->pratosCount; i++) {
            printf(" Prato: %s", current->pratos[i].nome);
        }
        current = current->next;
        pedidoId++;
    }
}

void processarPedidoMaisAntigo(PedidoNode **listaPedidos, PedidoNode **filaProcessamento) {
    if (*listaPedidos == NULL) {
        printf("Não há pedidos para processar.\n");
        return;
    }

    PedidoNode *pedidoParaProcessar = *listaPedidos;
    *listaPedidos = (*listaPedidos)->next;

    if (*filaProcessamento == NULL) {
        *filaProcessamento = pedidoParaProcessar;
    } else {
        PedidoNode *atual = *filaProcessamento;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = pedidoParaProcessar;
    }

    pedidoParaProcessar->next = NULL;
    printf("Pedido processado e movido para a fila de processamento.\n");
}

PedidoNode* encontrarPedidoPorPosicao(PedidoNode *head, int pedidoId) {
    PedidoNode *current = head;
    while (current != NULL) {
        if (current->id == pedidoId) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

int removerPratoDoPedido(PedidoNode **head, int pedidoId) {
    if (head == NULL || *head == NULL) {
        printf("Lista de pedidos vazia ou não encontrada.\n");
        return 0; 
    }

    PedidoNode *temp = *head;
    PedidoNode *prev = NULL;

    while (temp != NULL && temp->id != pedidoId) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Pedido ID %d não encontrado.\n", pedidoId);
        return 0;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp->pratos);
    free(temp);

    printf("Pedido ID %d removido com sucesso.\n", pedidoId);
    return 1;
}

int adicionarPratoAoPedido(PedidoNode *head, int pedidoId, Prato novoPrato) {

    PedidoNode *pedido = encontrarPedidoPorPosicao(head, pedidoId);
    if (pedido == NULL) {
        printf("Pedido não encontrado.\n");
        return 0;
    }

    Prato *pratosAtualizados = realloc(pedido->pratos, (pedido->pratosCount + 1) * sizeof(Prato));
    if (pratosAtualizados == NULL) {
        printf("Erro ao alocar memória para o novo prato.\n");
        return 0;
    }

    pratosAtualizados[pedido->pratosCount] = novoPrato;
    pedido->pratos = pratosAtualizados;
    pedido->pratosCount++;

    printf("Prato '%s' adicionado ao pedido ID %d.\n", novoPrato.nome, pedidoId);
    return 1;
}