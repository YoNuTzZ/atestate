#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"

struct Matrix *create_matrix(int rows, int columns) 
{
	struct Matrix *a = malloc(sizeof(struct Matrix));
	if(a == NULL) {
		return NULL;
	}

	// set matrix atributes
	a->rows        = rows;
	a->columns     = columns;
	a->determinant = 0.0;
	a->inverse 	   = NULL;

	// set matrix's value
	a->value = malloc(rows * sizeof(double));
	if(a->value == NULL) {
		return NULL;
	} 

	for(int i = 0; i < rows; i++) {
		a->value[i] = malloc(rows * sizeof(double));
		if(a->value == NULL) {
			return NULL;
		}
	}

	return a;
}
