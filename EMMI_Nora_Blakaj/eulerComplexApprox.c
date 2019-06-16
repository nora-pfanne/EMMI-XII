#include <math.h>
#include <complex.h>

double f_real(double complex, unsigned int);

int main(void){

    double complex z = 0.1 + I*0.1;
    double complex w;
    double ex;

    for(unsigned int i=1; i<100; i++){
        z *= i;
        f_real(z, 16);
        w = cexp(z);

        ex = cabs(f_real(z,25)-creal(w))/cabs(creal(w));

        printf("|z| = %e  |z-w| / |w| %e \n", cabs(f_real(z, 25)), ex);
         z = 0.1 + I*0.1;
    }
    return 0;
}

double f_real(double complex z, unsigned int n){

    double complex sum = 1.0 + I*0.0;
	double complex summand = 1.0 + I*0.0;
	
	for(unsigned int i = 1; i <= n; i++){
		
		summand *= (z/i);
		sum += summand;
	}
	
	return creal(sum);

}
