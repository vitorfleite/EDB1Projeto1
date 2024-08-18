#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include "Cardapio.h"

typedef struct PedidoNode {
    Prato *pratos;
    int pratosCount;
    int id;
    struct PedidoNode *next;
} PedidoNode;

void imprimirmenu();
void adicionarPedido(PedidoNode **head, Prato *pratos, int pratosCount, int novoPedidoId);
int adicionarPratoAoPedido(PedidoNode *head, int pedidoId, Prato novoPrato);
void listarPedidosPendentes(PedidoNode *head);
void listarPedidosProcessamento(PedidoNode *head);
void processarPedidoMaisAntigo(PedidoNode **listaPedidos, PedidoNode **filaProcessamento);
int removerPratoDoPedido(PedidoNode **head, int pedidoId);
#endif