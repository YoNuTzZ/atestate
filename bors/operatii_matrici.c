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
	for(int i = 0; i < a->lines - 1 ; i++) {
		if(i == line)
			x--;
		for(int j = 0; i < a->columns -1; j++) {
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