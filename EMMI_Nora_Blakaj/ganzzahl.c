#include <stdio.h>
#include <stdint.h>

void binary(uint8_t , uint8_t []);
void add(uint8_t [], uint8_t [], uint8_t []);
void sub(uint8_t [], uint8_t [], uint8_t []);
uint8_t dec(uint8_t []);

int main(void){
	
	uint8_t a_2[8],b_2[8];
	uint8_t c_2[8],d_2[8];
	
	uint8_t a = 222;
	uint8_t b = 50;
	
	binary(a, a_2);
	binary(b, b_2);
	
	add(c_2, a_2, b_2);
	sub(d_2, a_2, b_2);
	
	printf("a = %u\n", dec(a_2));
	printf("b = %u\n", dec(b_2));
	printf("c = %u\n", dec(c_2));
	printf("d = %u\n", dec(d_2));
	
	printf("a = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",a_2[i]);
	}
	
	printf("\n");
	printf("b = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",b_2[i]);
	}
	
	printf("\n");
	printf("c = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",c_2[i]);
	}
	
	printf("\n");
	printf("d = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",d_2[i]);
	}
	
	printf("\n");

	return 0;
}

void binary(uint8_t a, uint8_t a_2[8]){
	
	for(uint32_t ii = 0; ii < 8; ii++){
		
		uint8_t i = 7-ii;
		
		a_2[i] = a%2;
		a = a/2;
	}
}

void add(uint8_t c[8], uint8_t a[8], uint8_t b[8]){
	
	uint8_t carry = 0;
	
	for(uint32_t ii = 0; ii < 8; ii++){
		
		uint32_t i = 7-ii;
		
		c[i] = a[i]+b[i]+carry;
		carry = (a[i]+b[i]+carry) / 2;
		c[i] = c[i]%2;
	}
}

void sub(uint8_t d[], uint8_t a[], uint8_t b[]){
	
	uint8_t b_1k[8];
	uint8_t b_2k[8];
	
	for(uint32_t ii = 0; ii < 8; ii++){
		
		uint32_t i = 7-ii;
		
		if(b[i] == 1){
			
			b_1k[i] = 0;
		}
		else {
			
			b_1k[i] = 1;
		}
	}
	
	uint8_t eins[8] = {0,0,0,0,0,0,0,1};
	add(b_2k, b_1k, eins);
	
	printf("b    = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",b[i]);
	}
	
	printf("\n");
	
	printf("b_1k = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",b_1k[i]);
	}
	
	printf("\n");
	
	printf("b_2k = ");
	
	for(uint32_t i = 0; i < 8; i++){
		printf("%u ",b_2k[i]);
	}
	
	printf("\n\n");
	
	
	add(d, a, b_2k);
}

uint8_t dec(uint8_t a_2[]){
	
	uint8_t zwei = 128;
	uint8_t a = 0;
	
	for(uint32_t i = 0; i < 8; i++){
		
		a += a_2[i] * zwei;
		zwei = zwei/2;
	}
	
	return a;
}