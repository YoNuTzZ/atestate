#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "error.h"

int main () {
	struct Matrix *a = create_matrix(4, 4);
	struct Matrix *minor;

	read_matrix(a);

	minor = get_minor(a, 1, 2);
	print_matrix(minor);



	
	return 0;
}