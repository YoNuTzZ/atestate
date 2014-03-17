#ifndef MATRICI_H
#define MATRICI_H

struct Matrix {
	int lines;
	int columns;

	double determinant;
	double trace;
			
	double **value;
	double **inverse;
};

struct Matrix *create_matrix(int rows, int columns);
void read_matrix(struct Matrix *a);
void print_matrix(struct Matrix *a);
struct Matrix *get_minor(struct Matrix *a, int line, int column);





#endif 