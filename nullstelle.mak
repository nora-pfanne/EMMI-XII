OPTIONS = -std=c99 -pedantic -DNDEBUG -Wall -Wextra 
nullstelle.exe: nullstelle.o
	gcc -o nullstelle.exe nullstelle.o	
nullstelle.o: nullstelle.c
	gcc $(OPTIONS) -c nullstelle.c