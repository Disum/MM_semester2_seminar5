#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../matrix/matrix.h"
#include "multiply_matrix.h"
enum RETURN_CODES
{
	ERR_INPUT,
	ERR_MEMORY,
	ERR_READ_MATR,
};

/* a - m*n матрица */
int main(int argc, char **argv)
{
	double *a, *b, *c;
	int m, n, k;
	char *name_a = 0, *name_b = 0;
	clock_t t_beg;

	if( !(argc==4 || argc==5 || argc==6 ) || (m = atoi(argv[1]))<=0 || (n = atoi(argv[2]))<=0 || (k = atoi(argv[3]))<=0 )
	{
		fprintf(stderr, "Usage: %s m n k [file_b] [file_a]\n", argv[0]);
		return ERR_INPUT;
	}

	if( argc>4 )
	{
		name_b = argv[4];
	}
	if( argc>5 )
	{
		name_a = argv[5];
	}

	if( !(a = malloc(m*n*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		return ERR_MEMORY;
	}
	if( !(b = malloc(n*k*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		free(a);
		return ERR_MEMORY;
	}
	if( !(c = malloc(m*k*sizeof(double))) )
	{
		fprintf(stderr, "Not enugh memory!\n");
		free(a);
		free(b);
		return ERR_MEMORY;
	}

	if( name_a )
	{
		int res_read;

		res_read = read_matrix(a, m, n, name_a);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name_a);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name_a);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			free(b);
			free(c);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(a, m, n);
	}

	if( name_b )
	{
		int res_read;

		res_read = read_matrix(b, n, k, name_b);

		if( res_read!=MATR_SUCCESS )
		{
			switch( res_read )
			{
				case MATR_ERR_OPEN:
					fprintf(stderr, "Can not open %s\n", name_b);
					break;
				case MATR_ERR_READ:
					fprintf(stderr, "Can not read from %s\n", name_b);
					break;
				default:
					fprintf(stderr, "Unknown error, code: %d\n", res_read);
			}

			free(a);
			free(b);
			free(c);
			return ERR_READ_MATR;
		}
	} else
	{
		init_matrix(b, n, k);
	}

	printf("Matrix A:\n");
	print_matrix(a, m, n);
	printf("Matrix B:\n");
	print_matrix(b, n, k);
	t_beg = clock();
	multiply_matrix(a, b, c, m, n, k);
	printf("Elapsed:\t%.2lf sec\nResult, matrix C:\n", (double)(clock() - t_beg)/CLOCKS_PER_SEC);
	print_matrix(c, m, k);

	free(a);
	free(b);
	free(c);
	return 0;
}
