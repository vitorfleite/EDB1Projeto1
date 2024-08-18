#ifndef CARDAPIO_H
#define CARDAPIO_H
#define MAX_CARDAPIO_SIZE 50

typedef struct Prato {
    char nome[50];
    int id;
    char categoria[20];
} Prato;

extern Prato cardapio[MAX_CARDAPIO_SIZE];
extern int cardapioSize;

void listarCardapio(Prato *cardapio, int tamanho);

#endif