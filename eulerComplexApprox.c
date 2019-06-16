#include <math.h>
#include <complex.h>

double f_real1(double complex, unsigned int);
double f_real2(double complex, unsigned int);

int main(void){

    double complex z = 0.1 + I*0.1;
    double complex w;
    double ex;

    // relativer Fehler der Vorwärtssummation
    for(unsigned int i=1; i<100; i++){
        z *= i;
        w = cexp(z);

        ex = cabs(f_real1(z,25)-creal(w))/cabs(creal(w));

        printf("|z| = %e  |z-w| / |w| %e \n", cabs(f_real1(z, 25)), ex);
         z = 0.1 + I*0.1;
    }

    // relativer Fehler der Rückwärtssummation
    for(unsigned int i=1; i<100; i++){
        z *= i;
        w = cexp(z);

        ex = cabs(f_real2(z,25)-creal(w))/cabs(creal(w));

        printf("|z| = %e  |z-w| / |w| %e \n", cabs(f_real2(z, 25)), ex);
         z = 0.1 + I*0.1;
    }
    return 0;
}

// Vorwärtssummation
double f_real1(double complex z, unsigned int n){

    double complex sum = 1.0 + I*0.0;
	double complex summand = 1.0 + I*0.0;
	
	for(unsigned int i = 1; i <= n; i++){
		
		summand *= (z/i);
		sum += summand;
	}
	
	return creal(sum);

}

// Rückwärtssummation
double f_real2(double complex z, unsigned int n){
	
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