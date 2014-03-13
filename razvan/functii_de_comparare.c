#define TRUE  1
#define FALSE 0
 
// probabil ca vor fi adaugate mai multe criterii de comparare...

int comparare_crescatoare(float element1, float element2) {
	if(element1 > element2) {
		return TRUE;
	}
	return FALSE;
}
 
int comparare_descrescatoare(float element1, float element2) {
	if(element1 < element2) {
		return TRUE;
	}
	return FALSE;
}