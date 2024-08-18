#include "Cardapio.h"
#include "FuncoesAuxiliares.h"
#include <string.h>
#include <stdio.h>

int main() {
    PedidoNode *pedidosPendentes = NULL;
    PedidoNode *filaProcessamento = NULL;

    int pedidoContador = 1;
    int opcao;
    int pratoId;
    int pedidoId;
    int verificador;

    do {
        imprimirmenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarCardapio(cardapio, cardapioSize);
                break;
            case 2:
                printf("Digite o ID do prato para adicionar ao pedido: ");  
                scanf("%d", &pratoId);  
                if (pratoId > 0 && pratoId <= cardapioSize) {  
                    adicionarPedido(&pedidosPendentes, &cardapio[pratoId - 1], 1, pedidoContador);
                    ++pedidoContador;  
                } else {  
                    printf("ID de prato inválido.\n");  
                }  
                break;
            case 3: 
                printf("Digite o ID do pedido ao qual deseja adicionar um prato: ");
                scanf("%d", &pedidoId);

                printf("Digite o ID do prato do cardápio a ser adicionado ao pedido: ");
                scanf("%d", &pratoId);

                Prato pratoParaAdicionar;
                // Encontrar o prato no cardápio pelo ID
                for (int i = 0; i < cardapioSize; i++) {
                    if (cardapio[i].id == pratoId) {
                        pratoParaAdicionar = cardapio[i];
                        verificador = 1;
                        break;
                    }
                }

                if (!verificador) {
                    printf("Prato com ID %d não encontrado no cardápio.\n", pratoId);
                    break;
                }

                if (adicionarPratoAoPedido(pedidosPendentes, pedidoId, pratoParaAdicionar)) {
                    printf("Prato '%s' adicionado com sucesso ao pedido ID %d.\n", pratoParaAdicionar.nome, pedidoId);
                } else {
                    printf("Falha ao adicionar o prato ao pedido.\n");
                }
                break;  
            case 4: {
                printf("Digite o ID do pedido: ");
                scanf("%d", &pedidoId);
                verificador = removerPratoDoPedido(&pedidosPendentes, pedidoId);
                if (verificador) {
                    printf("Pedido removido com sucesso.\n");
                } else {
                    printf("Falha ao remover o pedido.\n");
                }
                break;
            }
            case 5:
                processarPedidoMaisAntigo(&pedidosPendentes, &filaProcessamento);
                break;
            case 6:
                listarPedidosPendentes(pedidosPendentes);
                break;
            case 7:
                listarPedidosProcessamento(filaProcessamento);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}