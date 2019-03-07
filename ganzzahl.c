#include <stdio.h>

int main(void){
	
	unsigned char a,b;
	unsigned char c,d;
	
	a = 222;
	b = 50;
	
	c = a+b;
	d = a-b;
	
	printf("%u %u\n", c, d);

	return 0;
}