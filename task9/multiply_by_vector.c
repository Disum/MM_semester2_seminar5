#include "multiply_by_vector.h"

/* a - матрица m*n, b - вектор длины n */
void multiply_by_vector(double *a, double *b, double *c, int m, int n)
{
	int i, j;
	double buffer;

	for( i = 0; i<m; i++ )
	{
		buffer = 0;
		for( j = 0; j<n; j++ )
		{
			buffer += a[i*n + j]*b[j];
		}
		c[i] = buffer;
	}
}
