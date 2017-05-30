CC=gcc
CFLAGS=-O2 -Wall -pedantic -std=c11
AR=ar
ARFLAGS=cr
OBJDIR=obj
BINDIR=bin
SRCDIR=src
LIBDIR=lib
LIBSO=$(LIBDIR)/dynamic
LIBA=$(LIBDIR)/static
EXEC=trigonometry
OBJ=sin.o
SRC=sin.c

make: $(EXEC)_dl $(EXEC)_a $(EXEC)_d
	@echo Creating all binaries in $(BINDIR)
	rm -rf ./$(OBJDIR)
	@echo Is necessary add the path $(shell pwd)/$(LIBSO) to library environment variable for correct execution of dynamic library
	@echo $ export LD_LIBRARY_PATH=$(shell pwd)/$(LIBSO)
	@echo $ export LIBPATH=$(shell pwd)/$(LIBSO)

$(EXEC)_dl: $(LIBSO)/libseno.so | $(BINDIR)
	@echo Creating dynamic execution with liseno.so
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -o $(BINDIR)/$(EXEC)_dl -L./$(LIBSO) -lseno

$(EXEC)_a: $(OBJDIR)/$(OBJ) $(LIBA)/libseno.a | $(BINDIR)
	@echo Creating static execution with libeno.a
	$(CC) $(CFLAGS) $(SRCDIR)/main.c -o $(BINDIR)/$(EXEC)_a -L./$(LIBA) -lseno

$(EXEC)_d: $(OBJDIR)/$(OBJ) $(LIBSO)/libseno.so | $(BINDIR)
	@echo Creating dynamic execution over demand with libseno.so
	$(CC) $(CFLAGS) $(SRCDIR)/main_demand.c -o $(BINDIR)/$(EXEC)_d -ldl

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
	rm -Rf ./$(BINDIR) ./$(OBJDIR)

libclean:
	rm -Rf ./$(LIBDIR)

fullclean: libclean clean

dist: fullclean make
