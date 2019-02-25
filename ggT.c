#include <stdio.h>

unsigned int g, m, n;

int ggt(unsigned int m, unsigned int n) {
	
	while(m != n) {
	
		if(m > n) {
			
			m = m - n;
		} else {
			
			n = n - m;
		}
	}
	
	return m;
}	

int main(void) {
	
	m = 12;
	n = 6;
	
	printf("Der ggt von %u und %u ist %u", m, n, ggt(m,n));
	
	return 0;	
}