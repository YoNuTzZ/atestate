#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
#include "error.h"

int main () {
	struct Matrix *a = create_matrix(2, 2);
	struct Matrix *at;
	read_matrix(a);
	at = get_transpose(a);

	print_matrix(at);


	return 0;
}