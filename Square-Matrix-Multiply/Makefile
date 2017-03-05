all: main

main: utils.o main.o
	g++ -o main utils.o main.o 

main.o: main.cpp ../common/utils.h
	g++ -c -O2 -I../common main.cpp 

utils.o: ../common/utils.cpp ../common/utils.h
	g++ -c -I../common ../common/utils.cpp
