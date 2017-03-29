#include "io.h"
#include "sort.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int size_args = argc - 1;
	char * ordem = "-d";
	if(size_args > 0) {
		if(strcmp("-r", argv[1]) == 0) {
			ordem = "-r";
		}
	}
	Lista lista;
	lista.size = 1;
	lista.current_size = 0;
	lista.vector = (int*)malloc(sizeof(int) * lista.size);
	lista = input(lista);
	output(lista, ordem);
	printf("\n");
	free(lista.vector);
	return 0;
}