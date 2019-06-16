#include <assert.h>
#include <stdio.h>

struct Rational { /* (-1)^s p/q, p,q teilerfremd */
  unsigned char s; 
  unsigned int p;
  unsigned int q;
};
typedef struct Rational Rational;

Rational Rational_set(unsigned char, unsigned int, unsigned int); 
Rational Rational_Zero(void);
Rational Rational_One(void);
Rational Rational_setInteger(int);
Rational Rational_Sum (Rational, Rational);
Rational Rational_Diff (Rational, Rational);
Rational Rational_Mult (Rational, Rational);
Rational Rational_Div (Rational, Rational);

void Rational_print (Rational);
double Rational_asDouble (Rational x);

int main (void){
  
  Rational x = {1, 7,5};
  Rational y, z; 
  
  y =Rational_set (0, 3,5);
  
  z = Rational_Sum (x,y); Rational_print(z);
  z = Rational_Diff (x,y); Rational_print(z);
  z = Rational_Mult (x,y); Rational_print(z);
  z = Rational_Div (x,y); Rational_print(z);
  
  return 0;
}

unsigned int ggT (unsigned int m, unsigned int n) {

  unsigned int r;
  
  r = m % n;
  while (r > 0) {
  
    m = n;
    n = r;
    
    r = m % n;
  }
  
  return n;
}

Rational Rational_set(unsigned char s, unsigned int p, unsigned int q){
  Rational z;
  unsigned int g;
  
  assert (q > 0);
  assert ((s == 1) || (s == 0));
  
  if (p == 0) {z = Rational_Zero();}
  else {
    g = ggT(p, q);
    z.s = s; z.p = p/g; z.q = q/g;
  }
  return z;
}


Rational Rational_Zero(void){  
  
  Rational z;
  z.s = 0; z.p = 0; z.q = 1;
  return z;
}
Rational Rational_One(void){  
  
  Rational z = {0,1,1};
  
  return z;
}
Rational Rational_Sum (Rational x, Rational y){
	
  Rational z;	
  unsigned char s=x.s, t=y.s;
  unsigned int p=x.p, q=x.q, u=y.p, v=y.q, pv, qu, qv;

  pv = p * v;
  qu = q * u;
  qv = q * v;
  if (s == t) {
    
    z = Rational_set(s, pv + qu, qv);  
  } else if (s == 0) {
	  
    if (pv >= qu) {z = Rational_set(0, pv - qu, qv);} 
	           else {z = Rational_set(1, qu - pv, qv);} 
	  
    } else {
      
	    if (qu >= pv) {z = Rational_set(0, qu - pv, qv);} 
	             else {z = Rational_set(1, pv - qu, qv);}  
    }	  
 	
  return z;	
}

Rational Rational_Diff (Rational x, Rational y){
	
  y.s = (y.s + 1) % 2;
  
  return Rational_Sum (x,y);	
}

Rational Rational_Mult (Rational x, Rational y){
	
  Rational z;	
  unsigned char s=x.s, t=y.s;
  unsigned int p=x.p, q=x.q, u=y.p, v=y.q, g1, g2;

  if (p*u == 0) {
	   z =Rational_Zero(); 
  } else {
    g1 = ggT (p, v); 
    g2 = ggT (u, q); 
	  z.s = (s + t) % 2;
    z.p = (p/g1)*(u/g2);	
    z.q = (q/g2)*(v/g1);	
  }
  return z;
}

Rational Rational_Div (Rational x, Rational y){
	
   unsigned int tmp;

   assert (y.p != 0);
   tmp = y.p; y.p = y.q; y.q = tmp;
   return Rational_Mult (x,y);
}

void Rational_print (Rational z){
	
  if (z.s == 0) {printf ("+");}	else {printf ("-");}	  
	printf ("%" "u" "/%" "u" "\n", z.p, z.q);	  
}