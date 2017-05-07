CC=gcc
CFLAGS=-O2 -Wall -lm -pedantic
OBJDIR=obj
BINDIR=bin
SRCDIR=src
EXEC=prod_cons

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o, $(SRC))

make: $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(BINDIR)/$(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: clean run
clean:
	rm -Rf $(BINDIR) $(OBJDIR)
run:
	./bin/$(EXEC)
