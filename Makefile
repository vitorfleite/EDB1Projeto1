CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = restaurante
SRCS = main.c FuncoesAuxiliares.c Cardapio.c 
HEADERS = FuncoesAuxiliares.h Cardapio.h
OBJS = $(SRCS:.c=.o)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) 
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
teste: $(TARGET)
	./$(TARGET)
clean:
	del $(OBJS) $(TARGET)
run: $(TARGET)
	./$(TARGET)
