#include "transpose.h"

/* a - матрица n*n */
void transpose(double *a, int n)
{
	int i, j;
	double buffer;

	for( i = 0; i<n; i++ )
		for( j = i + 1; j<n; j++ )
		{
			buffer = a[i*n + j];
			a[i*n + j] = a[j*n + i];
			a[j*n + i] = buffer;
		}
}
