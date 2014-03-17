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

	for(int i = 0; i < a->lines; i++) {
		for(int j = 0; i < a->columns; j++) {
			if(i != line && j != columns) {
				minor->value[i][j] = a->value[i][j];
			}
		}
	}

	return minor;
}


/*
int compute_trace(struct Matrix *a)
{
	if(c->columns != a->lines) {
		return //error
	}

	for(int i = 0; i < a->columns; i++) {
		a->trace += a->value[i][i];
	}

	return NO_ERROR;
}*/