#include "Cardapio.h"
#include <stdio.h>
#include <string.h>

#define MAX_CARDAPIO_SIZE 50

// Cardápio do restaurante
Prato cardapio[MAX_CARDAPIO_SIZE] = {
    {"Sopa de Cebola", 1, "Entrada"},
    {"Salada Caesar", 2, "Entrada"},
    {"Bruschetta", 3, "Entrada"},
    {"Carpaccio de Carne", 4, "Entrada"},
    {"Camarão ao Alho", 5, "Entrada"},
    {"Lasanha à Bolonhesa", 6, "Prato principal"},
    {"Filé Mignon com Fritas", 7, "Prato principal"},
    {"Frango Grelhado com Legumes", 8, "Prato principal"},
    {"Bacalhau à Gomes de Sá", 9, "Prato principal"},
    {"Risoto de Cogumelos", 10, "Prato principal"},
    {"Tiramisu", 11, "Sobremesa"},
    {"Cheesecake de Frutas Vermelhas", 12, "Sobremesa"},
    {"Mousse de Chocolate", 13, "Sobremesa"},
    {"Pudim de Leite", 14, "Sobremesa"},
    {"Sorvete de Baunilha com Calda de Morango", 15, "Sobremesa"}
};
int cardapioSize = 15;

void listarCardapio(Prato *cardapio, int tamanho) {
    printf("\nCardápio:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d. %s (%s)\n", cardapio[i].id, cardapio[i].nome, cardapio[i].categoria);
    }
}