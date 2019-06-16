OPTIONS = -std=c99 -pedantic -DNDEBUG -Wall -Wextra 
euler.exe: euler.o
	gcc -o euler.exe euler.o	
euler.o: euler.c
	gcc $(OPTIONS) -c euler.c