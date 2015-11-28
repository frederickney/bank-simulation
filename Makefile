include Makefile.inc

CFLAGS=-Wall -pedantic -std=c11 -D_POSIX_C_SOURCE=199309L
LDFLAGS=-lrt -lpthread
EXE=simulate_bank
OBJ=src/bank.o src/clients.o src/tickets.o src/functions.o

.PHONY: clean

all: CFLAGS += -g
all: $(EXE)

release: CFLAGS += -O3
release: $(EXE)
$(EXE): src/main.o $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(EXE) $(OBJ) src/main.o
