OPTIONS = -std=c99 -pedantic -DNDEBUG -Wall -Wextra 
complex.exe: complex.o
	gcc -o complex.exe complex.o	
complex.o: complex.c
	gcc $(OPTIONS) -c complex.c