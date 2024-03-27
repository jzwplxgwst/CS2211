CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =
SRC = main.c matrix.c bstree.c datatype.c
OBJ = $(SRC:.c=.o)
	TARGET = bst

all: $(TARGET)

$(TARGET): $(OBJ)
		$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJ) $(TARGET)

.PHONY: all clean

