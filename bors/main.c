#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "error.h"

int main () {
	struct Matrix *a = create_matrix(4, 4);
	struct Matrix *minor;

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			a->value[i][j] = i*j;
		}
	}

	minor = get_minor(a, 1, 2);
	print_matrix(minor);



	
	return 0;
}