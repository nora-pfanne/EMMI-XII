#include <stdio.h>
#include <math.h>

double f(double x);
double f_prime(double x);
double newton(double x);
double newton_correction(double x);

int main(void){
	
	printf("%.15lf\n", newton(4));
	printf("%.15lf\n", newton_correction(4));
	
	return 0;
}

double f(double x){
	
	double y = x*x -2;
	
	return y;
}

double f_prime(double x){
	
	//double y = exp(log((1+x) * 0.5)) * (x/(2 * (1+x)) + 0.5 * log(1+x)) - exp(log(x * sqrt(1+x))) * (sqrt(1+x)/x + log(x) / (2*sqrt(1+x)))
	double y = 2*x;
	
	return y;
}

double newton_correction(double x){
	
	//double y = exp(log(sqrt(1+x) * x))- exp(log(x * sqrt(1+x)));
	
	double a_1 = 1 + x;
	double a_2 = sqrt(a_1);
	double a_3 = a_2 * x;
	double a_4 = log(a_3);
	double a_5 = exp(a_4);
	double a_6 = x * a_2;
	double a_7 = log(a_6);
	double a_8 = exp(a_7);
	double a_9 = a_5 - a_8;
	
	double b_1 = 1;
	double b_2 = b_1 / (2*(sqrt(a_1)));
	double b_3 = b_2*x + a_2;
	double b_4 = b_3 / a_4;
	double b_5 = b_4 * exp(a_4);
	double b_6 = a_2 + x * b_2;
	double b_7 = 1/b_6;
	double b_8 = b_7 * exp(a_7);
	double b_9 = b_5 - b_8;
	
	return a_9 / b_9;
}

double newton(double x){
	
	if(fabs(x - f(x)/f_prime(x)) > 0.000000001){
		
		return newton(fabs(x - f(x)/f_prime(x)));
	} 
	else {
		
		
		return fabs(x - f(x)/f_prime(x));
	}
}
