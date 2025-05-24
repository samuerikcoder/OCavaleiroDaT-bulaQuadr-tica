# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g -MMD

# Bibliotecas
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf

# Fontes e objetos
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# Regra principal
all: $(TARGET)

# Linka todos os objetos
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Regra genérica para compilar .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Inclui automaticamente os arquivos .d (dependências de headers)
-include $(DEPS)

# Limpeza
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)
