list_ab: list_ab.o
	gcc -g -ansi list_ab.o -o list_ab

list_ab.o: list_ab.c
	gcc -c -Wall -ansi -pedantic list_ab.c -o list_ab.o