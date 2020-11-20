.PHONY:clean
CC=gcc
CFLAGS=-Wall -g
BIN=myshell
OBJS=main.o parse.o init.o
$(BIN):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c
	$(CC) $(CSLAGS) -c $< -o $@
clean:
	rm -f *.0 $(BIN)


