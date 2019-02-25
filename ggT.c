#include <stdio.h>


// klassischer Euklid-Algorithmus
int ggT1(unsigned int m, unsigned int n) {
	
	// Überprüfung, ob es sich um die selbe Zahl handelt
	while(m != n) {
		
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

int ggT2(unsigned int m, unsigned int n) {
	
	unsigned int temp;
	
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

int main(void) {
	
	unsigned int m, n;
	
	printf("Gib hier die erste Zahl ein: \n");
	m = getchar();
	
	printf("Gib hier die zweite Zahl ein: \n");
	n = getchar();
	
	printf("/nDer ggT von %u und %u ist %u\n", m, n, ggT1(m,n));
	printf("Der verbesserte ggT von %u und %u ist %u\n", m, n, ggT2(m,n));
	
	return 0;	
}