#include "io.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Lista input(Lista l) {
	int value;
	while(1) {
		scanf("%d", &value);
		if(value == -1) {
			break;
		}
		insert_list(value, &l);
	}
	return l;
}

void output(Lista l, char * ordem) {
	int i;
	basc_sort(l, ordem);
	if(strcmp("-r", ordem) == 0) {
		printf("Ordem decrescente:\n");
	} else {
		printf("Ordem crescente:\n");
	}
	for(i = 0; i < l.current_size; i++) {
		printf("%d ", l.vector[i]);
	}
}