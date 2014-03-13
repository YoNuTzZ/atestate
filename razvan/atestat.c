#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "atestat.h"
 
 
int main() {
	float *vector;
	char stare[] = "da";
	char modDeSortare[15] = "crescator";
	size_t marime;
	

	printare_heading();
	do {
		printf("ce marime are vectorul?\n");
		scanf("%u", &marime);
		vector = malloc(marime);          
		
		printf("introduceti elementele vectorului:\n");
		citire_vector(vector, marime);
	

		printf("cum vrei sa sortez acest evctor?\n");
		printf("crescator sau descrescator?\n");
		scanf("%s", modDeSortare);

		if(!strcmp(modDeSortare, "crescator")) {
			sortare_prin_selectie(vector, marime, comparare_crescatoare);	
		}
		else if(!strcmp(modDeSortare, "descrescator")) {
			sortare_prin_selectie(vector, marime, comparare_descrescatoare);
		}
		else {
			printf("nu ati ales o optiune valida, programul av rula de la inceput\n");
			continue;
		}
		
		afisare_elemente_vector(vector, marime);
		printf("\n");
		
		printf("mai vrei sa sortezi si alt vector?\n");
		printf("scrie da daca da sau nu daca nu\n");
		
		scanf("%s", stare);
	} while(!strcmp(stare, "da"));
 
	printf("multumim penru folosirea programului\n");
 
	return 0;
}