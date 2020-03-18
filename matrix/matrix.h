#ifndef MATRIX_H
#define MATRIX_H

int read_matrix(double *a, int m, int n, const char *name);

enum MATR_RETURN_CODES
{
	MATR_SUCCESS,
	MATR_ERR_OPEN,
	MATR_ERR_READ,
};

double f(int n, int i, int j);
void init_matrix(double *a, int m, int n);
void print_matrix(double *a, int m, int n);

#endif
