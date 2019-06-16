#include <stdio.h>
#include <math.h>

unsigned int fibunacci_rekursiv(unsigned int n);
unsigned int fibunacci(unsigned int n);
double fibunacci_quotient(unsigned int n);
double fibunacci_grenzwert(unsigned int n);

int main(void){
	
	unsigned int n = 0;
	
	// Eingabe von n
	printf("Gib hier ein n ein \n");
	scanf("%u",&n);
	
	// Ergebnisausgabe
	printf("Die %u-te Fibunacci-Zahl (rekursiv) ist %u \n", n, fibunacci_rekursiv(n));
	printf("Die %u-te Fibunacci-Zahl ist %u \n", n, fibunacci(n));
	printf("Der Quotient der %u-ten Fibunacci-Zahl und ihrem Vorgaenger ist %lf \n", n, fibunacci_quotient(n));
	printf("Die Summe bis zum %u-ten Quotienten ist %lf \n", n, fibunacci_grenzwert(n));
	
	return 0;
}

unsigned int fibunacci_rekursiv(unsigned int n){
	
	if(n == 1){
		
		return 1;
		
	} else if(n == 2){
		
		return 1;
		
	} else {
		
		return fibunacci_rekursiv(n-1) + fibunacci_rekursiv(n-2);
	}	
}

unsigned int fibunacci(unsigned int n){
	
	double fib = ((1+sqrt(5))/2);
	double fib_negativ = ((1-sqrt(5))/2);
	
	n = (double)n;
	
	return (int)((1-(1/sqrt(5)))*pow(fib, n) + (1/sqrt(5))*pow(fib_negativ, n));
}

double fibunacci_quotient(unsigned int n){
	
	if(n == 1){
		
		return 1;
		
	} else if(n == 2) {
		
		return 1;
		
	} else {
		
		return fibunacci(n)/fibunacci(n-1);
	}
}

double fibunacci_grenzwert(unsigned int n){
	
	if(n == 1){
		
		return 0;
		
	}else if(n == 2){
		
		return 0;
		
	} else {
		
		return fibunacci_quotient(n)+fibunacci_grenzwert(n-1);
	}
}