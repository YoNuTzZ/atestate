#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libMatrix/matrici.h"

void referenceSwap(double *a, double *b) 
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
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
		minimum = i;
		for(j = i; j < lineSize; j++) {
			if((*cmp)(matrixLine[j], matrixLine[minimum])) {
				minimum = j;
			}
		}
		referenceSwap(&matrixLine[minimum], &matrixLine[i]);
	}
}

void sorteazaMatriceaDupaLinii(struct Matrix *A, int (*cmp)(double, double))
{
	for(int i = 0; i < A->lines; i++) {
		sortarePrinSelectie(A->value[i], A->lines, cmp);
	}
}

void sorteazaMatriceaDupaColoane(struct Matrix *A, int(*cmp)(double, double)) 
{
	size_t minimum;

	for(int i = 0; i < A->columns; i++) {
		// selection sort 
		for(int j = 0; j < A->lines; j++) {
			minimum = j;
			for(int k = j; k < A->lines; k++) {
				if((*cmp)(A->value[minimum][i], A->value[k][i])) {
					minimum = k;
				}
			}
			referenceSwap(&A->value[minimum][i], &A->value[j][i]);
		}
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
	char stare[3] = "nu";
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
		printf("\n");

		printf("ce operatie doriti sa faceti?\n");
		printf("puteti sorta o matrice dupa linii si coloane, ");
		printf("calcula inversa unei matrici si determinantul acesteia: ");

		scanf("%s", comanda);

		if(!strcmp(comanda, "sortare")) {
			printf("cum doriti sa sortati matricea? Dupa linii sau dupa coloane?: ");
			scanf("%s", comanda);
			
			if(!strcmp(comanda, "linii")) {
				printf("cum doriti sa o sortati? crescator sau descrescator: ");
				scanf("%s", comanda);

				if(!strcmp(comanda, "crescator")) {
					sorteazaMatriceaDupaLinii(A, comparaCrescator);
					print_matrix(A);
				}
				else if(!strcmp(comanda, "descrescator")) {
					sorteazaMatriceaDupaLinii(A, comparaDescrescator);
					print_matrix(A);
				}
				else {
					printf("nu v-am inteles comanda\n");
				}
			}
			else if(!strcmp(comanda, "coloane")) {
				printf("cum doriti sa o sortati? crescator sau descrescator: ");
				scanf("%s", comanda);

				if(!strcmp(comanda, "crescator")) {
					sorteazaMatriceaDupaColoane(A, comparaCrescator);
					print_matrix(A);
				}
				else if(!strcmp(comanda, "descrescator")) {
					sorteazaMatriceaDupaColoane(A, comparaDescrescator);
					print_matrix(A);
				}
				else {
					printf("nu v-am inteles comanda\n");
				}
			}
			else {
				printf("nu v-am inteles comanda");
			}
		}
		else if (!strcmp(comanda, "determinant")) {
			if(A->lines == A->columns) { 
				A->determinant = get_determinant(A);
				printf("determinantul este %g\n", A->determinant);
			}
			else {
				printf("doar matricile patratice au determiannt\n");
			}
		}
		else if(!strcmp(comanda, "inversa")) {
			if(A->lines == A->columns) {

				A->determinant = get_determinant(A);
				compute_inverse(A);

				printf("inversa matricii introduse de dumneavoastra este: \n");
				print_matrix(A->inverse);
			}
			else {
				printf("doar matricile patratice au inversa\n");
			}
		}
		else {
			printf("comanda dumneavoastra nu a fost inteleasa \n");
		}

		printf("doriti sa efectuati operatii si pe alta matrice?\n");
		printf("scrieti da daca da sau nu daca vreti sa inchideti programul: ");
		scanf("%s", stare);
		
		distroy_matrix(A);
	}
	while(!strcmp(stare, "da"));

	return 0;
}