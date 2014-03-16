#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"

int main() {
	struct Matrix *a = create_matrix(2, 3);
	a->rows = 12;
	printf("%d", a->columns);

	return 0;
}