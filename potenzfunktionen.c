#include <stdio.h>

double potenz1(double x, unsigned int n);
double potenz2(double x, unsigned int n);
double potenz3(double x, unsigned int n);
double potenz4(double x, unsigned int n);

int main(void){
	
	double b = 3.0;
	unsigned int n = 3;
	
	// User Input
	//printf("Gib eine Basis ein: \n");
	//b = scanf("%lf", &b);
	
	//printf("\nGib einen Exponenten ein: \n");
	//n = scanf("%u", &n);
	
	// Ergebnisausgabe
	printf("\npotenz1(%lf, %u) = %lf\n", b, n, potenz1(b,n));
	printf("\npotenz2(%lf, %u) = %lf\n", b, n, potenz2(b,n));
	printf("\npotenz3(%lf, %u) = %lf\n", b, n, potenz3(b,n));
	printf("\npotenz4(%lf, %u) = %lf\n", b, n, potenz4(b,n));
	
	return 0;
}

double potenz1(double x, unsigned int n){
	
	unsigned int i = 2;
	double p = x;
	
	if(n == 0){
		
		p = 1;
	}
	
	while(i < n){
		
		p *= p;
		
		i += 1;
	}
	
	return p;
}

double potenz2(double x, unsigned int n){
	
	if(n == 0){
		
		return 1;
		
	} else {
		
		return x * potenz2(x, n-1);
	}
}

double potenz3(double x, unsigned int n){
	
	if(n == 0){
		
		return 1;
		
	} else if(n == 1){
		
		return x;
		
	} else if(n%2 == 0){
		
		return potenz3(x,n/2) * potenz3(x,n/2);
		
	} else {
		
		return x * potenz3(x, (n-1)/2) * potenz3(x, (n-1)/2);
	}
}

double potenz4(double x, unsigned int n){
	
	unsigned int i = 1;
	double p = x;
	
	if(n == 0){
		
		return 1;
		
	} else if(n == 1){
		
		return x;
		
	}
	
	while(i < n){
		
		if(n%2 == 0){
			
			p *= x;
			n = n/2;
			
		} else {
			
			p *= x * x;
			n = (n-1)/2;
		}
	}
	
	return p;
}