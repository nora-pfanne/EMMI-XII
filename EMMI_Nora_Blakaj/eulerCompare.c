#include <math.h>
#include <complex.h>
#include <stdio.h>

double complex f_real1(double complex, unsigned int);
double complex f_real2(double complex, unsigned int);
double complex phi_horner(double complex, unsigned int);
double complex phi_evaluate(double complex, unsigned int);
unsigned int nOptimal_f1(double complex);
unsigned int nOptimal_f2(double complex);
unsigned int nOptimal_horner(double complex);

int main(void){

    double complex z = 0.1 + I*0.1;

    // Variantion von z
    for(unsigned int i = 1; i <=200; i+= 20){

        z *= i;
        printf("%lf + I*%lf", creal(z), cimag(z));
        
        printf(" %u", nOptimal_f1(z));
        printf(" %u", nOptimal_f2(z));
        printf(" %u", nOptimal_horner(z));

        z = 0.1 + I*0.1;
        printf("\n");
    }
    return 0;
}

// Vorwärtssummation
double complex f_real1(double complex z, unsigned int n){

    double complex sum = 1.0 + I*0.0;
	double complex summand = 1.0 + I*0.0;
	
	for(unsigned int i = 1; i <= n; i++){
		
		summand *= (z/i);
		sum += summand;
	}
	
	return sum;

}

// Rückwärtssummation
double complex f_real2(double complex z, unsigned int n){
	
	double complex sum = 1.0 + I*0.0;
	double complex summand = 1.0 + I*0.0;
	
	for(unsigned int i = n; i > 0; i--){
		
		for(unsigned int j = 1; j <= i; j++){
			
			summand *= (z/j);
		}
		
		sum += summand;
		summand = 1.0 + I*0.0;
	}
	return sum;
}

// Horner-Schema
double complex phi_horner(double complex z, unsigned int n){
	
	double complex erg;
	
	erg = z/n;
	
	for(unsigned int i = (n-1); i > 0; i--){
		
		erg = erg * z/i +1;
		
	}
	
	return erg;
}

double complex phi_evaluate(double complex z, unsigned int n){
	
	double abs;
	double complex erg, temp;
	
	abs = cabs(z);
	

	if(abs > 1.0){
	
		
		temp = phi_evaluate(z/2.0, n);
		erg = temp * temp;
	}
	else {
		
		erg = phi_horner(z, n);
	} 
	
	return erg;
} 

unsigned int nOptimal_f1(double complex z){
    
    // Anzahl der benötigten Summanden
        for(unsigned int n = 1; n < 100; n++){

            if (f_real1(z, n) == f_real1(z, n+1)){
               return n;
            }
        }
    
}

unsigned int nOptimal_f2(double complex z){
    
    // Anzahl der benötigten Summanden
        for(unsigned int n = 1; n < 100; n++){

            if (f_real2(z, n) == f_real2(z, n+1)){
               return n;
            }
        }
    
}

unsigned int nOptimal_horner(double complex z){
    
    // Anzahl der benötigten Summanden
        for(unsigned int n = 1; n < 100; n++){

            if (phi_evaluate(z, n) == phi_evaluate(z, n+1)){
               return n;
            }
        }
    
}