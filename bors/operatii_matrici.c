#include <stdio.h>
#include <math.h>
#include "matrici.h"
#include "error.h"

int compute_determinant(struct Matrix *a)
{
	int columns = a->columnns;
	int rows    = a->rows;

	if(columns != rows) {
		return NOT_SQUARE_MATRIX; //error
	}

	// compute determinant
	// god damn it, it should be recursive
} 

int compute_trace(struct Matrix *a)
{
	if(c->columns != a->rows) {
		return //error
	}

	for(int i = 0; i < a->columns; i++) {
		a->trace += a->value[i][i];
	}

	return NO_ERROR;
}