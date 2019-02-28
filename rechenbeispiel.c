#include <stdio.h>

int main(void) {
	
	//Variablendeklarierung
	unsigned int m, n, k;
	
	// Initialisierung
	m = 42;
	n = 12;
	
	k = m + n;
	
	// while-Schleife
	
	l = 1;
	
	while(l<=15) {
		
		printf("l = %u",l);
		l = l + 2;
	}
	
	// Ausgabe in der Konsole
	// format specifier %u
	printf("k = %u", k); 
	//Ausgabe: k = 54
	
	return 0;
}