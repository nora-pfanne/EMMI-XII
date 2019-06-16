#include <stdio.h>

// Deklarierung und Initialisierung eines Arrays
int numarray[5] = {1,4,7,5,2};


// Prozedur: Bubblesort für ein Array aus Integer-Zahlen
void bubblesort(int *x) {
	
	//  temporaerer Speicherplatz für den Tausch
	int temp;
	
	
	// Das Array wird ausgehen von der Position i durchlaufen
	for(unsigned int i=0; i < 5; i++) {
		for(unsigned int j=i; j < 5; j++) {
	
			// Stimmt die Reihenfolge zweier benachbarter Zahlen nicht, werden diese vertauscht
			if(x[j]<x[i]) {
			
				temp = x[j];
				x[j] = x[i];
				x[i] = temp;
				
				printf("%d\n",x[i]);			
			}	
		}
	}	
}

// Main-Methode
int main(void) {
	
	// Aufruf der Prozedur mit numarray
	bubblesort(numarray);
	
	// Ausgabe des Ergebnisses: [1,2,4,5,7]
	printf("[");
	
	for(unsigned int i = 0; i < 4; i++) {
	
		printf("%d,",numarray[i]);
	}
	
	
	printf("%d]",numarray[4]);
	
	return 0;
}