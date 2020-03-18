prog: main.o ../matrix/matrix.o transpose.o
	gcc main.o ../matrix/matrix.o transpose.o -o prog
main.o: main.c
	gcc -c main.c
../matrix/matrix.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc -c ../matrix/matrix.c -o ../matrix/matrix.o
transpose.o: transpose.c transpose.h
	gcc -c transpose.c

prog_debug: main_debug.o ../matrix/matrix_debug.o transpose_debug.o
	gcc -g main_debug.o ../matrix/matrix_debug.o transpose_debug.o -o prog_debug
main_debug.o: main.c
	gcc -g -c main.c -o main_debug.o
../matrix/matrix_debug.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc -g -c ../matrix/matrix.c -o ../matrix/matrix_debug.o
transpose_debug.o: transpose.c transpose.h
	gcc -g -c transpose.c -o transpose_debug.o

prog_optimize: main_optimize.o ../matrix/matrix_optimize.o transpose_optimize.o
	gcc -O3 main_optimize.o ../matrix/matrix_optimize.o transpose_optimize.o -o prog_optimize
main_optimize.o: main.c
	gcc -O3 -c main.c -o main_optimize.o
../matrix/matrix_optimize.o: ../matrix/matrix.c ../matrix/matrix.h
	gcc -O3 -c ../matrix/matrix.c -o ../matrix/matrix_optimize.o
transpose_optimize.o: transpose.c transpose.h
	gcc -O3 -c transpose.c -o transpose_optimize.o