#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../matrix/matrix.h"
#include "symmetric.h"
enum RETURN_CODES
{
	ERR_INPUT,
	ERR_MEMORY,
	ERR_READ_MATR,
};

/* a - n*n матрица */
int main(int argc, char **argv)
{
	double *a;
	int n, res_symmetric;
	char *name = 0;
	clock_t t_beg;

	if( !(argc==2 || argc==3 ) || (n = atoi(argv[1]))<=0 )
	{
		fprintf(stderr, "Usage: %s n [file]\n", argv[0]);
		return ERR_INPUT;
	}

	if( argc==3 )
		name = argv[2];

	if( !(a = malloc(n*n*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		return ERR_MEMORY;
	}

	if( name )
	{
		int res_read;

		res_read = read_matrix(a, n, n, name);

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
		init_matrix(a, n, n);
	}

	print_matrix(a, n, n);
	t_beg = clock();
	res_symmetric = symmetric(a, n);
	printf("Elapsed:\t%.2lf sec\nResult:\t", (double)(clock() - t_beg)/CLOCKS_PER_SEC);
	if( res_symmetric )
		printf("symmetric\n");
	else
		printf("not symmetric\n");

	free(a);
	return 0;
}
