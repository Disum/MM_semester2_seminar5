FLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wno-long-long -Wmissing-declarations

prog: main.o ../matrix/matrix.o swap_rows.o
	gcc $(FLAGS) main.o ../matrix/matrix.o swap_rows.o -o prog
main.o: main.c
	gcc $(FLAGS) -c main.c
../matrix/matrix.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -c ../matrix/matrix.c -o ../matrix/matrix.o
swap_rows.o: swap_rows.c swap_rows.h
	gcc $(FLAGS) -c swap_rows.c

prog_debug: main_debug.o ../matrix/matrix_debug.o swap_rows_debug.o
	gcc $(FLAGS) -g main_debug.o ../matrix/matrix_debug.o swap_rows_debug.o -o prog_debug
main_debug.o: main.c
	gcc $(FLAGS) -g -c main.c -o main_debug.o
../matrix/matrix_debug.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -g -c ../matrix/matrix.c -o ../matrix/matrix_debug.o
swap_rows_debug.o: swap_rows.c swap_rows.h
	gcc $(FLAGS) -g -c swap_rows.c -o swap_rows_debug.o

prog_optimize: main_optimize.o ../matrix/matrix_optimize.o swap_rows_optimize.o
	gcc $(FLAGS) -O3 main_optimize.o ../matrix/matrix_optimize.o swap_rows_optimize.o -o prog_optimize
main_optimize.o: main.c
	gcc $(FLAGS) -O3 -c main.c -o main_optimize.o
../matrix/matrix_optimize.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -O3 -c ../matrix/matrix.c -o ../matrix/matrix_optimize.o
swap_rows_optimize.o: swap_rows.c swap_rows.h
	gcc $(FLAGS) -O3 -c swap_rows.c -o swap_rows_optimize.o
