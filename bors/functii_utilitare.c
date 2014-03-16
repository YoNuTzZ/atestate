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
	a->trace       = 0.0;
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

void distroy_matrix(struct Matrix *a) 
{
	int rows = a->rows;

	// free the value of matrix
	for(int i = 0; i < rows; i++) {
		free(a->value[i]);
	}
	free(a->value);

	// free the memory occuped by it's inverse
	// ! after implement function to calculate inverse
}

void read_matrix(struct Matrix *a) 
{
	int rows    = a->rows;
	int columns = a->columns;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("introduceti elementul a[%d][%d]: ", i, j);
			scanf("%lf", a->value[i][j]);
		}
	}
}

void print_matrix(struct Matrixa *a)
{
	int rows    = a->rows;
	int columns = a->columns;
	
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%lf ", a->value[i][j]);
		}
		printf("\n");
	}
}

