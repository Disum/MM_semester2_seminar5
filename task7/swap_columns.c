#include "swap_columns.h"

/* a - матрица m*n */
void swap_columns(double *a, int m, int n, int i, int j)
{
	int k;
	double buffer;

	for( k = 0; k<m; k++ )
	{
		buffer = a[k*n + i];
		a[k*n + i] = a[k*n + j];
		a[k*n + j] = buffer;
	}
}
