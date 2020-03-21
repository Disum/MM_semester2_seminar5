#include "swap_rows.h"

/* a - матрица m*n */
void swap_rows(double *a, int m, int n, int i, int j)
{
	int k;
	double buffer;
	(void)m;

	for( k = 0; k<n; k++ )
	{
		buffer = a[i*n + k];
		a[i*n + k] = a[j*n + k];
		a[j*n + k] = buffer;
	}
}
