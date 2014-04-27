#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "error.h"

struct Matrix *create_matrix(int lines, int columns) 
{
	struct Matrix *a = malloc(sizeof(struct Matrix));
	if(a == NULL) {
		return NULL;
	}

	// set matrix atributes
	a->lines       = lines;
	a->columns     = columns;
	a->determinant = 0.0;
	a->trace       = 0.0;
	a->inverse     = NULL;

	// set matrix's value
	a->value = malloc(lines * sizeof(double));
	if(a->value == NULL) {
		return NULL;
	} 

	for(int i = 0; i < lines; i++) {
		a->value[i] = calloc(columns, sizeof(double));
		if(a->value == NULL) {
			return NULL;
		}
	}

	return a;
}

void distroy_matrix(struct Matrix *a) 
{
	int lines = a->lines;

	// free the value of matrix
	for(int i = 0; i < lines; i++) {
		free(a->value[i]);
	}
	free(a->value);

	if(a->inverse != NULL) {
		distroy_matrix(a->inverse);
	}
}

void copy_matrix(struct Matrix *a, struct Matrix **destination) 
{
	for(int i = 0; i < a->lines; i++) {
		for(int j = 0; j < a->columns; j++) {
			(*destination)->value[i][j] = a->value[i][j];
		}
	}
}

void read_matrix(struct Matrix *a) 
{
	int lines    = a->lines;
	int columns = a->columns;

	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < columns; j++) {
			printf("introduceti elementul a[%d][%d]: ", i + 1, j + 1);
			scanf("%lf", &a->value[i][j]);
		}
	}
}

int print_matrix(struct Matrix *a)
{
	if(a == NULL) {
		return MATRIX_NOT_EXISTS;
	}

	int lines    = a->lines;
	int columns = a->columns;
	
	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%g ", a->value[i][j]);
		}
		printf("\n");
	}

	return NO_ERROR;
}

