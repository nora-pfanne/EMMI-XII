#include <stdio.h>

int numarray[5] = {1,4,7,5,2};

void bubblesort(int *x) {
	
	int temp;
	
	for(unsigned int i=0; i < 5; i++) {
		for(unsigned int j=i; j < 5; j++) {
	
			if(x[j]<x[i]) {
			
				temp = x[j];
				x[j] = x[i];
				x[i] = temp;
				
				printf("%d\n",x[i]);			}	
		}
	}	
}

int main(void) {

	bubblesort(numarray);
	
	printf("[");
	
	for(unsigned int i = 0; i < 4; i++) {
	
		printf("%d,",numarray[i]);
	}
	
	
	printf("%d]",numarray[4]);
	
	return 0;
}