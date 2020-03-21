FLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wno-long-long -Wmissing-declarations

prog: main.o ../matrix/matrix.o multiply_matrix.o
	gcc $(FLAGS) main.o ../matrix/matrix.o multiply_matrix.o -o prog
main.o: main.c
	gcc $(FLAGS) -c main.c
../matrix/matrix.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -c ../matrix/matrix.c -o ../matrix/matrix.o
multiply_matrix.o: multiply_matrix.c multiply_matrix.h
	gcc $(FLAGS) -c multiply_matrix.c

prog_debug: main_debug.o ../matrix/matrix_debug.o multiply_matrix_debug.o
	gcc $(FLAGS) -g main_debug.o ../matrix/matrix_debug.o multiply_matrix_debug.o -o prog_debug
main_debug.o: main.c
	gcc $(FLAGS) -g -c main.c -o main_debug.o
../matrix/matrix_debug.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -g -c ../matrix/matrix.c -o ../matrix/matrix_debug.o
multiply_matrix_debug.o: multiply_matrix.c multiply_matrix.h
	gcc $(FLAGS) -g -c multiply_matrix.c -o multiply_matrix_debug.o

prog_optimize: main_optimize.o ../matrix/matrix_optimize.o multiply_matrix_optimize.o
	gcc $(FLAGS) -O3 main_optimize.o ../matrix/matrix_optimize.o multiply_matrix_optimize.o -o prog_optimize
main_optimize.o: main.c
	gcc $(FLAGS) -O3 -c main.c -o main_optimize.o
../matrix/matrix_optimize.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -O3 -c ../matrix/matrix.c -o ../matrix/matrix_optimize.o
multiply_matrix_optimize.o: multiply_matrix.c multiply_matrix.h
	gcc $(FLAGS) -O3 -c multiply_matrix.c -o multiply_matrix_optimize.o
