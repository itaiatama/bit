EXEC   = bit
SRC    = $(wildcard src/*.c)
CFLAGS = -Wall -Wextra -ggdb -std=c11 -pedantic

$(EXEC):
	$(CC) -o $(EXEC) $(CFLAGS) $(SRC)

