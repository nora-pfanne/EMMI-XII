#include <stdio.h>

// Funktionsprototypen
unsigned int ggT1(unsigned int m, unsigned int n);
unsigned int ggT2(unsigned int m, unsigned int n);

int main(void) {
	
	// Deklaration der Variablen m und n
	unsigned int m, n;
	
	// Eingabe vcn m und n durch den User
	printf("Gib hier die erste Zahl ein: \n");
	scanf("%u/n", &m);
	
	printf("Gib hier die zweite Zahl ein: \n");
	scanf("%u/n", &n);
	
	// Methodenaufruf und Ergebnisausgabe
	printf("Der ggT von %u und %u ist %u\n", m, n, ggT1(m,n));
	printf("Der verbesserte ggT von %u und %u ist %u\n", m, n, ggT2(m,n));
	
	return 0;	
}

// klassischer Euklid-Algorithmus
unsigned int ggT1(unsigned int m, unsigned int n) {
	
	// Überprüfung, ob es sich um die selbe Zahl handelt
	while(m != n) {
		
		// Ausnahme: Ein Paramater ist 0
		if(n == 0 || m == 0) {
			
			return 0;
	
		} else if(m > n) {
			
			m = m - n;
		} else {
			
			n = n - m;
		}
	}
	
	return m;
}	

// Verbesserter Algorithmus
unsigned int ggT2(unsigned int m, unsigned int n) {
	
	// Variabel für den Tausch von m und n
	unsigned int temp;
	
	// Ausnahme: Ein Paramater ist 0
	if(m == 0 || n == 0){
		
		return 0;
	}	
	
	while(n != 0) {
		
		temp = m;
		m = n;
		n = temp%n;
	}
	
	return m;
}	