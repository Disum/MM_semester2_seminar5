#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../matrix/matrix.h"
#include "swap_columns.h"
enum RETURN_CODES
{
	ERR_INPUT,
	ERR_MEMORY,
	ERR_READ_MATR,
};

/* a - m*n матрица */
int main(int argc, char **argv)
{
	double *a;
	int m, n, i, j;
	char *name = 0;
	clock_t t_beg;

	if( !(argc==5 || argc==6 ) || (m = atoi(argv[1]))<=0 || (n = atoi(argv[2]))<=0 || sscanf(argv[3], "%d", &i)!=1 || i<0 || i>=n || sscanf(argv[4], "%d", &j)!=1 || j<0 || j>=n )
	{
		fprintf(stderr, "Usage: %s m n i j [file]\n", argv[0]);
		return ERR_INPUT;
	}

	if( argc==6 )
		name = argv[5];

	if( !(a = malloc(m*n*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		return ERR_MEMORY;
	}

	if( name )
	{
		int res_read;

		res_read = read_matrix(a, m, n, name);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(a, m, n);
	}

	print_matrix(a, m, n);
	t_beg = clock();
	swap_columns(a, m, n, i, j);
	printf("Elapsed:\t%.2lf sec\nResult:\n", (double)(clock() - t_beg)/CLOCKS_PER_SEC);
	print_matrix(a, m, n);

	free(a);
	return 0;
}
