CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11






all : graphL.o data_ioL.o math_arrayL.o stackL.o data_processL.o
	$(CC)  $(CFLAGS) ./build/graph.o  ./build/data_io.o  ./build/math_array.o  ./build/stack.o  ./build/data_process.o  -o ./build/graph

graphL.o: ./src/graph.c
	$(CC)  $(CFLAGS) -c ./src/graph.c -o ./build/graph.o
data_ioL.o: ./src/data_io.c
	$(CC)  $(CFLAGS) -c ./src/data_io.c -o ./build/data_io.o
math_arrayL.o: ./src/math_array.c
	$(CC)  $(CFLAGS) -c ./src/math_array.c -o ./build/math_array.o
stackL.o: ./src/stack.c
	$(CC)  $(CFLAGS) -c ./src/stack.c -o ./build/stack.o
data_processL.o: ./src/data_process.c
	$(CC)  $(CFLAGS) -c ./src/data_process.c -o ./build/data_process.o

clean :
	rm  ./build/*.o
	rm  ./build/graph

rebuild :
	make clean
	make all


.PHONY : rebuild all
