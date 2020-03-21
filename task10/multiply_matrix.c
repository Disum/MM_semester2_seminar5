#include "multiply_matrix.h"

/* a - матрица m*n, b - матрица n*k, c - матрица m*k */
void multiply_matrix(double *a, double *b, double *c, int m, int n, int k)
{
	int i, j, l;
	double buffer;

	for( i = 0; i<m; i++ )
	{
		for( j = 0; j<k; j++ )
		{
			buffer = 0;
			for( l = 0; l<n; l++ )
				buffer += a[i*n + l]*b[l*k + j];

			c[i*k + j] = buffer;
		}
	}
}
