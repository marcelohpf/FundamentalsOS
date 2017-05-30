CC=gcc
CFLAGS=-O2 -Wall -pedantic
AR=ar
ARFLAGS=cr
OBJDIR=obj
BINDIR=bin
SRCDIR=src
LIBDIR=lib
LIBSO=$(LIBDIR)/dinamic
LIBA=$(LIBDIR)/static
EXEC=trigonometry
OBJ=sin.o
SRC=sin.c

make: $(OBJDIR)/$(OBJ) $(LIBA)/libseno.a $(LIBSO)/libseno.so | $(BINDIR)
	@echo Creating dinamic execution with liseno.so
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -o $(BINDIR)/$(EXEC)_dl -L./$(LIBSO) -lseno
	@echo Creating static execution with libeno.a
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -o $(BINDIR)/$(EXEC)_a -L./$(LIBA) -lseno

$(LIBA)/libseno.a: $(OBJDIR)/$(OBJ) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $<

$(LIBSO)/libseno.so: $(OBJDIR)/$(OBJ) | $(LIBDIR)
	$(CC) $(CFLAGS) -shared $< -o $@

$(OBJDIR)/$(OBJ): $(SRCDIR)/$(SRC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR) $(LIBSO) $(LIBA)

$(BINDIR):
	mkdir -p $(BINDIR)

.PHONY: clean dist libclean fullclean
clean:
	rm -Rf $(BINDIR) $(OBJDIR)

libclean:
	rm -Rf $(LIBDIR)

fullclean: libclean clean

dist: fullclean make
