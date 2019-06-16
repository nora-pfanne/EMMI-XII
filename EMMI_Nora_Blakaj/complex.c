#include <stdio.h>
#include <complex.h>
#include <math.h>


double complex phi_horner(double complex z);
double complex phi_evaluate(double complex z);

int main(void){
	
	double a,b, abschnitt;
	unsigned int h;
	double complex z;
	double pi = 3.1415926535897932;
	unsigned int r = 140;
	
	a = 4;
	b = -4;
	h = 40000;
	
	// Abtasten des Quadrats für den Realteil
	for(unsigned int i = 0; i <= h; i = i + 1){
		
		for(unsigned int j = 0; j <= h; j = j + 1){
			
			z = -4.0 + (i*(a-b)/h) + I*(-4.0+(j*(a-b)/h));
		
			//printf("%lf %lf %lf\n", -4.0 + (i*(a-b)/h), -4.0+(j*(a-b)/h), creal(phi_evaluate(z)));
		}
		//printf("\n");
	}
	
	// Abtasten des Quadrats für den Imaginaerteil
	for(unsigned int i = 0; i <= h; i = i + 1){
		
		for(unsigned int j = 0; j <= h; j = j + 1){
			
			z = -4.0 + (i*(a-b)/h) + I*(-4.0+(j*(a-b)/h));
		
			//printf("%lf %lf %lf\n", -4.0 + (i*(a-b)/h), -4.0+(j*(a-b)/h), cimg(phi_evaluate(z)));
		}
		//printf("\n");
	}
	
	
	// Abtasten des Kreises mit dem Radius r für den Imaginaerteil
	for(unsigned int i = 0; i <= h; i = i + 1){
		
		abschnitt = 1.0*i/h;
		double x = 1.0*r*cos(2.0*pi*abschnitt);
		double y = 1.0*r*sin(2.0*pi*abschnitt);
		
		z = x + I*y;
		
		printf("%lf %lf\n", creal(phi_evaluate(z)), cimag(phi_evaluate(z)));
	}
	
	return 0;
}

double complex phi_horner(double complex z){
	
	unsigned int n = 18;
	double complex erg;
	
	erg = z/n;
	
	for(unsigned int i = (n-1); i > 0; i--){
		
		erg = erg * z/i +1;
		
	}
	
	return erg;
}



double complex phi_evaluate(double complex z){
	
	double abs;
	double complex erg, temp;
	
	abs = cabs(z);
	

	if(abs > 1.0){
	
		
		temp = phi_evaluate(z/2.0);
		erg = temp * temp;
	}
	else {
		
		erg = phi_horner(z);
	} 
	
	return erg;
} 
