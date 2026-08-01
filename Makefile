CC = $(shell which clang 2>/dev/null || which gcc)
SRC = src/main.c
OUT = build/todofinder

all:
	$(CC) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)