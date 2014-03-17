#ifndef MATRICI_H
#define MATRICI_H

struct Matrix {
	int lines;
	int columns;

	double determinant;
	double trace;
			
	double **value;
	struct Matrix *inverse;
};

struct Matrix *create_matrix(int rows, int columns);
void read_matrix(struct Matrix *a);
void print_matrix(struct Matrix *a);
struct Matrix *get_minor(struct Matrix *a, int line, int column);
void multiply_matrix_with_scalar(struct Matrix *a, double scalar); 
struct Matrix *get_transpose(struct Matrix *a); 




#endif 