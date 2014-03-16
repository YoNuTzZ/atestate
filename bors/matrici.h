#ifndef MATRICI_H
#define MATRICI_H

struct Matrix {
	int rows;
	int columns;

	double determinant;
	double trace;
			
	double **value;
	double **inverse;
};

struct Matrix *create_matrix(int rows, int columns);



#endif 