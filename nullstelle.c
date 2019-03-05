#include <stdio.h>
#include <math.h>

double nullstelle(double a, double b);
double f(double x);

int main(void){
	
	double a = 2.0;
	double b = 4.0;
	
	printf("Die Nullstelle der Funktion im Intervall [%.10lf, %.10lf] ist %.10lf", a, b, nullstelle(a,b));
	
	return 0;
}

double nullstelle(double a, double b){
	
	while(b-a > 0.00000001){
		
		if(f(a) * f(b) < 0){
			
			if(f(a) > 0){
				
				if(f((a+b)/2) > 0){
					
					a = (a+b)/2;
					
				} else {
					
					b = (a+b)/2;
				}
				
			} else {
				
				if(f((a+b)/2) < 0){
					
					a = (a+b)/2;
					
				} else {
					
					b = (a+b)/2;
				}
			}
		} else {
			
			printf("keine Nullstelle vorhanden");
			return 0;
		}
	}
	
	return a;
}

double f(double x){
	
	double y = pow(sqrt(1+x), x) - pow(x, sqrt(1+x));
	
	return y;
}