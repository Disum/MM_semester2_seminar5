#include "symmetric.h"

/* a - матрица n*n */
int symmetric(double *a, int n)
{
	int i, j;

	for( i = 0; i<n; i++ )
		for( j = i + 1; j<n; j++ )
			if( a[i*n + j]!=a[j*n + i] )
				return 0;

	return 1;
}
