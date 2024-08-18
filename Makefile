# Nome do compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -g

# Nome do executável
TARGET = restaurante

# Arquivos de origem
SRCS = main.c FuncoesAuxiliares.c Cardapio.c 

# Arquivos de cabeçalho
HEADERS = FuncoesAuxiliares.h Cardapio.h

# Arquivos objetos (gerados a partir dos arquivos de origem)
OBJS = $(SRCS:.c=.o)

# Regra padrão, gera o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 

# Regra para compilar os arquivos .c em .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

teste: $(TARGET)
	./$(TARGET)
# Regra para limpar os arquivos gerados
clean:
	del $(OBJS) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)
