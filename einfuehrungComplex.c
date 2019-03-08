#include <complex.h>
#include <stdio.h>

int main(void){

	double complex z = 5.0 + I*4.0;
	double complex w, y;
	double n;
	
	
	w = z * z;
	
	y = exp(z);
	
	n = cabs(z);
	
	printf("z     : Re = %lf, Im = %lf\n", creal(z), cimag(z));
	printf("z * z : Re = %lf, Im = %lf\n", creal(w), cimag(w));
	printf("exp(z): Re = %lf, Im = %lf\n", creal(y), cimag(y));
	
	printf("Absoutbetrag von z: %lf\n", n);
	
	return 0;
}