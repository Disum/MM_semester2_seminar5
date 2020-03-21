#include "solve.h"

/* a - матрица m*n */
void solve(double *a, int m, int n, int i, int j, double b)
{
	int k;
	(void)m;

	for( k = 0; k<n; k++ )
	{
		a[j*n + k] += b*a[i*n + k];
	}
}
