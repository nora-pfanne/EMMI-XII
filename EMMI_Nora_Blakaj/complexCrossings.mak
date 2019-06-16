OPTIONS = -std=c99 -pedantic -DNDEBUG -Wall -Wextra 
complexCrossings.exe: complexCrossings.o
	gcc -o complexCrossings.exe complexCrossings.o	
complexCrossings.o: complexCrossings.c
	gcc $(OPTIONS) -c complexCrossings.c