#include <stdio.h>

unsigned int fibunacci_rekursiv(unsigned int n);
unsigned int fibunacci(unsigned int n);
double fibunacci_quotient(unsigned int n);
double fibunacci_grenzwert(void);

int main(void){
	
	unsigned int n;
	
	// Eingabe von n
	printf("Gib hier ein n ein \n");
	scanf("%u/n",n);
	
	// Ergebnisausgabe
	printf("Die %u-te Fibunacci-Zahl (rekursiv) ist %u", n, fibunacci_rekursiv(n));
	printf("Der Quotient der %u-ten Fibunacci-Zahl und ihrem Vorgänger ist %lf \n", n, fibunacci_quotient(n));
	
	return 0;
}

unsigned int fibunacci_rekursiv(unsigned int n){
	
	if(n == 0){
		
		return 1;
		
	} else if(n == 1){
		
		return 1;
		
	} else {
		
		return fibunacci(n-1) + fibunacci(n-2);
	}	
}

double fibunacci_quotient(unsigned int n){
	
	if(n == 0){
		
		return 1;
		
	} else if(n == 1){
		
		return 1;
		
	} else {
		
		return fibunacci(n-1) / fibunacci(n-2);
	}
}