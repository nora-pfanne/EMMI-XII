OPTIONS = -std=c99 -pedantic -DNDEBUG -Wall -Wextra 
complexCompare.exe: complexCompare.o
	gcc -o complexCompare.exe complexCompare.o	
complexCompare.o: complexCompare.c
	gcc $(OPTIONS) -c complexCompare.c