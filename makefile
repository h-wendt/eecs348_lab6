prog: matrix_lab.o
	g++ -g -std=c++11 -Wall matrix_lab.o -o prog

matrix_lab: main.cpp matrix.h
	g++ -g -std=c++11 -Wall -c matrix_lab.cpp



clean:
	rm *.o prog
