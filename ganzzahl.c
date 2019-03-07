#include <stdio.h>
#include <stdint.h>

void binary(uint8_t , uint8_t []);
void add(uint8_t [], uint8_t [], uint8_t []);
void sub(uint8_t [], uint8_t [], uint8_t []);
uint8_t dec(uint8_t [], uint8_t);

int main(void){
	
	uint8_t m = 8;
	uint8_t a_2[8],b_2[8];
	uint8_t c_2[8],d_2[8];
	
	uint8_t a = 222;
	uint8_t b = 50;
	
	binary(a, a_2);
	binary(b, b_2);
	
	c = a+b;
	d = a-b;
	
	printf("%u %u\n", c, d);

	return 0;
}

void binary(uint8_t a, uint8_t a_2[8]){
	
	for(uint32_t i = 7; i >= 0; i++){
		
		a_2[i] = a%2;
		a = a/2;
	}
}

void add(uint8_t c[8], uint8_t a[8], uint8_t b[8]){
	
	uint8_t carry = 0;
	
	for(uint32_t i = 7; i >= 0; i++){
		
		c[i] = (a[i]+b[i]+carry) % 2;
		carry = (a[i]+b[i]) / 2;
	}
}

void sub(uint8_t d[], uint8_t a[], uint8_t b[]){
	
	uint8_t b_1k[8];
	
	for(uint32_t i = 0; i < 8; i++){
		
		if(b[i] == 1){
			
			b_1k[i] = 0;
		}
		else {
			
			b_1k[i] = 1;
		}
	}
	
	uint8_t eins[8] = {0,0,0,0,0,0,0,1};
	add(b_2k, b_1k, eins);
	
	add(d, a, b_2k);
}

uint8_t dec(uint8_t a_2[], uint8_t a){
	
	for(uint32_t i = 7; i >= 0; i--)
	
	return a;
}