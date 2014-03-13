#include <stdio.h>

void citire_vector(float *vp, size_t marime) {
	while(marime--) {
		scanf("%f", vp);
		vp++;
	}
}
 
void afisare_elemente_vector(float *vp, size_t marime) {
	size_t i = 0;
	
	while(marime--) {
		printf("\t %.1f ", vp[i]);
		i++;
	}
}
 