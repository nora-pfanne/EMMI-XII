#include <stdio.h>
#include <assert.h>

double phi1(double x, unsigned int n);
double phi2(double x, unsigned int n);
double phi_horner(double x, unsigned int n);
double phi_evaluate(double x, unsigned int n);

int main(void){
	
	double x = 10;
	unsigned int n = 20;
	unsigned int i = 1;
	
	while(phi1(x,i-1) != phi1(x,i)){
		i++;
	}
	printf("Die %u-te Partialsumme ist %lf\n", i, phi1(x,i));
	printf("Die %u-te Partialsumme (rueckwaerts) ist %lf.\n", i, phi2(x,i));
	
	printf("Das Ergebnis des Honer-Schemas ist %lf", phi_evaluate(x,n));
	
	return 0;
}

double phi1(double x, unsigned int n){
	
	double sum = 1.0;
	double summand = 1.0;
	
	for(unsigned int i = 1; i <= n; i++){
		
		summand *= (x/i);
		sum += summand;
	}
	
	return sum;
}


double phi2(double x, unsigned int n){
	
	double sum = 1.0;
	double summand = 1.0;
	
	for(unsigned int i = n; i > 0; i--){
		
		for(unsigned int j = 1; j <= i; j++){
			
			summand *= (x/j);
		}
		
		sum += summand;
		summand = 1.0;
	}
	return sum;
}

double phi_horner(double x, unsigned int n){
	
	assert(x >= 0.0 && x <= 1.0);
	
	double erg = x/n;
	
	for(unsigned int i = (n-1); i > 0; i--){
		
		erg = erg * x/i +1;
		
	}
	
	return erg;
}

double phi_evaluate(double x, unsigned int n){
	
	double y, temp;
	
	if(x < 0.0){
		
		y = 1.0 / phi_evaluate(-x, n);
	} 
	else if(x > 1.0){
		
		temp = phi_evaluate(x/2.0, n);
		y = temp * temp;
	}
	else {
		
		y = phi_horner(x, n);
	}
	
	return y;
}