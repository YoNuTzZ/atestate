#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "error.h"

int main () {
	struct Matrix *a = create_matrix(3, 3);
	read_matrix(a);

	a->determinant   = get_determinant(a);

 	compute_inverse(a));

	print_matrix(a->inverse);

	return 0;
}