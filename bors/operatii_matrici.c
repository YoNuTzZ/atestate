#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrici.h"
#include "error.h"

struct Matrix *get_minor(struct Matrix *a, int line, int columns)
{
	struct Matrix *minor = create_matrix(a->lines - 1, a->columns - 1);
	if(minor == NULL) {
		return NULL;
	}

	int x = 0, y = 0;
	for(int i = 0; i < a->lines; i++) {
		if(i == line)
			x--;
		for(int j = 0; j < a->columns; j++) {
			if(i != line && j != columns) {
				minor->value[x][y] = a->value[i][j];
				y++;
			}
		}
		x++;
		y = 0;
	}

	return minor;
}

double get_determinant(struct Matrix *a)                                            
{                                                                              
	if (a->lines == 1 && a->columns == 1) {                                     
		return a->value[0][0];              
	}                                    
	else {                                                                      
	  det = 0;                                                          
	  for (int i = 0; i < a->columns; i++) {                                  
	      struct Matrix *m = get_minor(a, 0, i);                              
	      det += (a->value[0][i]) * (pow(-1, 2 + i)) * (determinant(m));      
	      free(m);                                                            
	  }                                                                      
	  return det;                                                            
	}                                                                          
}


struct Matrix *get_transpose(struct Matrix *a) 
{
	struct Matrix *transpose = create_matrix(a->lines, a->columns);
	if(transpose == NULL) {
		return NULL;
	}

	for(int i = 0; i < a->lines; i++) {
		for(int j = 0; j < a->columns; j++) {
			transpose->value[i][j] = a->value[j][i];
		}
	}
	return transpose;
}

double **get_inverse_wrapee(struct Matrix *a)
{
	if(a->determinant == 0) {
		return NULL;
	}

	struct Matrix *inverse = create_matrix(a->lines, a->columns);
	struct Matrix *minor;

	if(inverse == NULL) {
		return NULL;
	}

	inverse->inverse = a->value;

	// A^*
	for(int i = 0; a->lines; i++) {
		for(int j = 0; j < a->columns; j++) {
			minor = get_minor(a, i, j);
			inverse->value[i][j] = get_determinant(minor);
		}
	}

	//  incomplete
	// ! finish it tomorrow

}

void get_inverse(struct Matrix *a) 
{
	// wrapper for get_inverse_wrapee
}


void multiply_matrix_with_scalar(struct Matrix *a, double scalar) 
{
	for(int i = 0; i < a->lines; i++) {
		for(int j = 0; j < a->columns; j++) {
			a->value[i][j] *= scalar; 
		}
	}
}

int compute_trace(struct Matrix *a)
{
	if(a->columns != a->lines) {
		return NOT_SQUARE_MATRIX; //error
	}

	for(int i = 0; i < a->columns; i++) {
		a->trace += a->value[i][i];
	}

	return NO_ERROR;
}