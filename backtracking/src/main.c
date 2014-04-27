#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STRING_SIZE 80

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int i, int n) 
{
   int j; 
   if (i == n) { 
       printf("%s\n", a);
   } else {
        for (j = i; j <= n; j++) {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 

void readString(char *string)
{
	int c = getchar();
	int i;
	int j; // folosit la contorizarea lui string
	for(i = 0, j = 0; c != '\n' && c != EOF; i++, c = getchar()) {
		if(!isspace(c)) {
			string[j] = c;
			j++;
		}
	}
	string[j] = '\0';
}

void author() 
{
	printf("*********************\n");
	printf("Autor....\n");
	printf("Scoala...\n");
	printf("Profesor...\n");
	printf("*********************\n");
}

int main()
{
	char message[] = "da";
	char a[MAX_STRING_SIZE]; // numarul maxim de caractere permise intr-un 
	// terminal obisnuit
	author();
	do { 
	
		printf("scrie sirul de numere si apasa [enter]\n");
	   	readString(a);  

	   	permute(a, 0, strlen(a) - 1);
	   	
		printf("Daca doresti sa generezi permutarile altui numara scrie da: "); 		
 		scanf("%s", message);
 		getchar(); // ramane un line-feed in stdin, si rebuie curatat 
 		printf("\n");
    } while(!strcmp(message, "da"));
   
   return 0;
}