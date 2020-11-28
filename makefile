CC = gcc
FLAGS = -Wall -g

all: MyBank.so main
MyBank.so: MyBank.o
	$(CC) -shared -o MyBank.so MyBank.o
MyBank.o: MyBank.c MyBank.h
	$(CC) $(FLAGS) -c MyBank.c
main: main.o
	$(CC) $(FLAGS) -o main main.o ./MyBank.so 
main.o: main.c MyBank.h
	$(CC) $(FLAGS) -c main.c
.PHONY: all clean

clean:
	rm -f *.o *.a *.so main
