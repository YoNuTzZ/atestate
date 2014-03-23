#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libMatrix/matrici.h"

void swap(double *matrixLine, size_t a, size_t b)
{
	double tmp = matrixLine[a];
	matrixLine[a] = matrixLine[b];
	matrixLine[b] = tmp;
}

int comparaCrescator(double a, double b) 
{	
	if(a > b) {
		return 1;
	}
	return 0;
}

int comparaDescrescator(double a, double b) 
{	
	if(a > b) {
		return 0;
	}
	return 1;
}

void sortarePrinSelectie(double *matrixLine, size_t lineSize, int (*cmp)(double, double))
{
	size_t minimum;

	for(size_t j, i = 0; i < lineSize - 1; i++) {
		minimum = matrixLine[i];
		for(j = i; j < lineSize; j++) {
			if((*cmp)(matrixLine[j], matrixLine[minimum])) {
				minimum = j;
			}
		}
		swap(matrixLine, minimum, j);
	}
}

void sorteazaMatriceaDupaLinii(struct Matrix *A, int (*cmp)(double, double))
{
	for(int i = 0; i < A->lines; i++) {
		sortarePrinSelectie(A->value[i], A->lines, cmp);
	}
}

void printHeading() 
{
	printf("*******************\n\n");
	printf("Numle elevului\n");
	printf("Numele Profesorului \n");
	printf("Clasa elevului\n\n");
	printf("*******************\n\n");
}

int main() 
{
	struct Matrix *A;
	char stare[2] = "nu";
	char comanda[20];
	int lines;
	int columns;

	printHeading();
	do {
		printf("introduceti numarul de linii ale matricii: ");
		scanf("%d", &lines);
		printf("\n");

		printf("introduceti numarul de coloane ale matricii: ");
		scanf("%d", &columns);
		printf("\n");

		A = create_matrix(lines, columns);
		read_matrix(A);

		printf("ce operatie doriti s afaceti?\n");
		printf("puteti sorta o matrice supa linii si colaone");
		printf("calcula inversa unei matrici si determinantul acesteia: ");

		scanf("%s", comanda);

		if(!strcmp(comanda, "sorteaza")) {
			printf("cum doriti sa sortati matricea? Dupa linii sau dupa coloane?: ");
			scanf("%s", comanda);
			
			if(!strcmp(comanda, "linii")) {
				printf("cum doriti sa o sortati? Crescator sau descrescator: ");
				scanf("%s", comanda);

				if(!strcmp(comanda, "crescator")) {
					//sorteazaMatriceaDupaLinii(A, comparaCrescator);
				}
				else if(!strcmp(comanda, "descrescator")) {
					sorteazaMatriceaDupaLinii(A, comparaDescrescator);
				}
				else {
					printf("nu v-am inteles comanda\n");
				}
			}
			else if(!strcmp(comanda, "coloane")) {
				// sorteaza dupa coloane test 
			}
			else {
				printf("nu v-am inteles comanda");
			}
		}
		else if (!strcmp(comanda, "determiant")) {
			// determinant rules
		}
		else if(!strcmp(comanda, "inversa")) {
			// inverse rules
		}
		else {
			printf("comanda dumneavoastra nu a fost inteleasa \n");
		}


		print_matrix(A);
		distroy_matrix(A);

	}
	while(!strcmp(stare, "da"));

	return 0;
}