FLAGS = -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wno-long-long -Wmissing-declarations

prog: main.o ../matrix/matrix.o solve.o
	gcc $(FLAGS) main.o ../matrix/matrix.o solve.o -o prog
main.o: main.c
	gcc $(FLAGS) -c main.c
../matrix/matrix.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -c ../matrix/matrix.c -o ../matrix/matrix.o
solve.o: solve.c solve.h
	gcc $(FLAGS) -c solve.c

prog_debug: main_debug.o ../matrix/matrix_debug.o solve_debug.o
	gcc $(FLAGS) -g main_debug.o ../matrix/matrix_debug.o solve_debug.o -o prog_debug
main_debug.o: main.c
	gcc $(FLAGS) -g -c main.c -o main_debug.o
../matrix/matrix_debug.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -g -c ../matrix/matrix.c -o ../matrix/matrix_debug.o
solve_debug.o: solve.c solve.h
	gcc $(FLAGS) -g -c solve.c -o solve_debug.o

prog_optimize: main_optimize.o ../matrix/matrix_optimize.o solve_optimize.o
	gcc $(FLAGS) -O3 main_optimize.o ../matrix/matrix_optimize.o solve_optimize.o -o prog_optimize
main_optimize.o: main.c
	gcc $(FLAGS) -O3 -c main.c -o main_optimize.o
../matrix/matrix_optimize.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc $(FLAGS) -O3 -c ../matrix/matrix.c -o ../matrix/matrix_optimize.o
solve_optimize.o: solve.c solve.h
	gcc $(FLAGS) -O3 -c solve.c -o solve_optimize.o
