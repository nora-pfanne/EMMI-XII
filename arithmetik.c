#include <stdio.h>
#include <math.h>

const double PI = 3.1514;
double x;
double y;

int main(void){

	x = 0.5;
	
	y = (1+fabs(x))*sin(PI*x)/(PI*(1-x*x));
	
	printf("Das Ergebnis ist %d",y);
	
	return 0;
}