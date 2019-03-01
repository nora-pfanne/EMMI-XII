#include <stdio.h>
#include <math.h>

struct Rational {
	
	unsigned char s;
	unsigned int p;
	unsigned int q;
};

typedef struct Rational Rational;

void Rational_Print(Rational);
Rational Rational_Sum(Rational, Rational);
Rational Rational_Diff(Rational, Rational);
Rational Rational_Mult(Rational, Rational);
Rational Rational_Div(Rational, Rational);
Rational Rational_Red(Rational);
unsigned int abs(int);
unsigned int ggT1(unsigned int m, unsigned int n);

int main(void){
	
	Rational x = {0, 1, 6};
	Rational y = {1, 4, 6};
		
	Rational_Print(x);
	Rational_Print(y);
	
	printf("Die Summe von x und y ist: ");
	Rational_Print(Rational_Sum(x, y));
	
	printf("Die Differenz von x und y ist: ");
	Rational_Print(Rational_Diff(x, y));
	
	printf("Das Produkt von x und y ist: ");
	Rational_Print(Rational_Mult(x, y));
	
	printf("Der Quotient von x und y ist: ");
	Rational_Print(Rational_Div(x, y));
	
	return 0;
}

void Rational_Print(Rational x){
	
	if(x.s == 0){
		
		printf("%u/%u\n", x.p, x.q);
		
	} else {
		
		printf("-%u/%u\n", x.p, x.q);
	}	
}

Rational Rational_Sum(Rational x, Rational y){
	
	unsigned char s;
	int p, v;
	unsigned int zaehler;
	
	
	if(x.s == 0){
		
		p = x.p*y.q;
		
	} else {
		
		p = -x.p*y.q;
	}	
	
	if(y.s == 0){
		
		v = y.p * x.q;
		
	} else {
		
		v = -y.p * x.q;
	}
	
	if(p+v > 0){
		
		s = 0;
		zaehler = p+v;
		
	} else if (p+v == 0){
		
		s = 0;
		p = 0;
		v = 0;
		
	} else {
		
		s = 1;
		zaehler = -(p+v);
	}
	
	Rational rational = {s, zaehler, x.q*y.q};
	
	Rational_Print(rational);
	
	Rational  rational_red = Rational_Red(rational);
	
	Rational_Print(rational_red);
	
	return rational_red;
}

Rational Rational_Diff(Rational x, Rational y){
	
	if(y.s == 1){
	
		Rational subtrahend = {0, y.p, y.q};
		return Rational_Sum(x, subtrahend);
		
	} else {
		
		Rational subtrahend = {1, y.p, y.q};
		return Rational_Sum(x, subtrahend);
	}
}

Rational Rational_Mult(Rational x, Rational y){
	
	unsigned char s = x.s * y.s;
	unsigned int p = x.p * y.p;
	unsigned int q = x.q * y.q;
	
	Rational rational = {s, p, q};
	
	Rational rational_red = Rational_Red(rational);
	
	return rational_red;
}

Rational Rational_Div(Rational x, Rational y){
	
	Rational divisor = {y.s, y.q, y.p};
	
	return Rational_Mult(x, divisor);
}

Rational Rational_Red(Rational x){
	
	unsigned int teiler = ggT1(x.p, x.q);
	
	unsigned int p = x.p/teiler;
	unsigned int q = x.q/teiler;
	
	Rational rational = {x.s, p, q};
	
	return rational;
}


// Klassischer Euklid-Algorithmus
unsigned int ggT1(unsigned int m, unsigned int n) {
	
	// Überprüfung, ob es sich um die selbe Zahl handelt
	while(m != n) {
	
		if(m > n) {
			
			m = m - n;
		} else {
			
			n = n - m;
		}
	}
	
	return m;
}	

unsigned int abs(int x){
	
	if(x < 0){
		
		return -x;
		
	} else {
		
		return x;
	}
}