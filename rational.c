#include <stdio.h>
#include <math.h>
#include <assert.h>

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
Rational Rational_Zero(void);
Rational Rational_set(unsigned char, unsigned int, unsigned int);
unsigned int abs(int);
unsigned int ggT1(unsigned int m, unsigned int n);
Rational phi_horner(double x, unsigned int n);
double Rational_double(Rational rational);

int main(void){
	
	/*
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
	*/
	
	Rational_Print(phi_horner(1.0, 12));
	printf("\n %lf", Rational_double(phi_horner(1.0, 12)));
	
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

Rational Rational_set(unsigned char s, unsigned int p, unsigned int q){
  Rational z;
  unsigned int g;
  
  assert (q > 0);
  assert ((s == 1) || (s == 0));
  
  if (p == 0) {z = Rational_Zero();}
  else {
    g = ggT1(p, q);
    z.s = s; z.p = p/g; z.q = q/g;
  }
  return z;
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

Rational phi_horner(double x, unsigned int n){
	
	assert(x >= 0.0 && x <= 1.0);
	
	Rational erg = Rational_set(0, x, n);
	
	for(unsigned int i = (n-1); i > 0; i--){
		
		//erg = erg * x/i +1;
		erg = Rational_Sum((Rational_Mult(erg, Rational_set(0, x, i))), Rational_set(0, 1, 1));
		
	}
	
	return erg;
}

Rational Rational_Zero(void){  
  
  Rational z;
  z.s = 0; z.p = 0; z.q = 1;
  return z;
}

double Rational_double(Rational rational){
	
	return 1.0*rational.p / rational.q;
}