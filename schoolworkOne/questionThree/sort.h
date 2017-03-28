#ifndef SORT
#define SORT

typedef struct lista {
	unsigned int size;
	unsigned int current_size;
	int * vector
} Lista;

void basc_sort(Lista * lista, char * ordem);

int compare(int a, int b, char * ordem);

void insert_list(int a, Lista * lista);

int * grow(int * v, int * actual_size);

#endif