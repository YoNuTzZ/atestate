#include <stdio.h>

static void swap(float *vp, size_t i, size_t j) {
	float temp;
	
	temp = vp[i];
	vp[i] = vp[j];
	vp[j] = temp;
}
 
void sortare_prin_selectie(float *vp, size_t marime, int (*comp)(float, float)) {
 	size_t i;
 	size_t j;
 	size_t minimum;
 	
 	for(i = 0; i < marime - 1; i++) {
 		minimum = i;
 		for(j = i + 1; j < marime; j++) {
 			if((*comp)(vp[minimum], vp[j])) {
 				// avem un nou minim	
 				minimum = j;
 			}
 		}
 		if(minimum != vp[i]) {
 			swap(vp, minimum, i);
 		}
 	}

 }
