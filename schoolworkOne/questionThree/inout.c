#include "inout.h"
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
		insert_list(value, l);
	}
	return l;
}

void output(Lista l, char * ordem) {
	int i;
	basc_sort(l, ordem);
	if(strcmp("-d", ordem)) {
		printf("Ordem crescente:\n");
	} else if(strcmp("-r", ordem)) {
		printf("Ordem decrescente:\n");
	}
	for(i = 0; i < l.current.size; i++) {
		printf("%d ", l.vector[i]);
	}
}