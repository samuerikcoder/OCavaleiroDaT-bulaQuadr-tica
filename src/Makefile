# Nome do executável
TARGET = main

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -g

# Bibliotecas
LIBS = -lSDL2 -lSDL2_image

# Fontes e objetos
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET) *.o
