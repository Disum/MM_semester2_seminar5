#include "solve.h"

/* a - матрица n*n */
void solve(double *a, int n)
{
	int i, j;

	for( i = 0; i<n; i++ )
		for( j = i + 1; j<n; j++ )
		{
			a[i*n + j] = (a[i*n + j] + a[j*n + i])/2;
			a[j*n + i] = a[i*n + j];
		}
}
