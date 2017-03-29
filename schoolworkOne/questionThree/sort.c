#include "sort.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compare(int a, int b, char * ordem) {
	if(strcmp("-d", ordem) == 0) {
		return a < b;
	} else if(strcmp("-r", ordem)==0) {
		return a > b;
	}
	return 0;
}

void basc_sort(Lista l, char * ordem) {
	int d, e;
	for(d = 0; d < l.current_size; d++) {
		for(e = 0; e < l.current_size; e++) {
			if(compare(l.vector[d], l.vector[e], ordem)) {
				int temp = l.vector[e];
				l.vector[e] = l.vector[d];
                l.vector[d]=temp;
			}
		}
	}
}

int * grow(int * v, int * actual_size) {
	int n_size = *actual_size * 2;
	int * new_v = (int*)malloc(sizeof(int) * n_size);
	int i;
	for(i = 0; i < *actual_size; i++) {
		new_v[i] = v[i];	
	}
	*actual_size = n_size;
	free(v);
	return new_v;
}

void insert_list(int a, Lista * l) {
	if(l->size == l->current_size) {
		l->vector = grow(l->vector, &l->size);
	}
	l->vector[l->current_size++] = a;

}