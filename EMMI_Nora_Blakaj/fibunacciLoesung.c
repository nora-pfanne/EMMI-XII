#include <stdio.h>

unsigned int fibunacci(unsigned int n);
unsigned int fibunacci_recursive(unsigned int n);
int counter(int counter);

int main(void){
	
	unsigned int n;
	
	n = 15;
	
	// Ergebnisausgabe
	printf("Die %u-te Fibunacci-Zahl ist %u\n", n, fibunacci(n));
	printf("Die %u-te Fibunacci-Zahl (rekursiv) ist %u\n", n, fibunacci_recursive(n));
	printf("Die rekursive Funktion wurde %d mal durchlaufen\n", counter(0));
	
	for(unsigned int i = 1; i <= n; i = i + 1){
		for(unsigned int j = 1; j <= n; j = j + 1){
			printf("%3u ", i+j);
		}
		printf("\n");
	}
	
	return 0;
}

unsigned int fibunacci(unsigned int n){
	
	unsigned int a_0, a_1, a_2;
	unsigned int i;
	
	a_0 = 1;
	a_1 = 1;
	a_2 = a_1 + a_0;
	
	i = 2;
	
	while(i < n){
		
		a_0 = a_1;
		a_1 = a_2;
		a_2 = a_1 + a_0;
		
		i = i+1;
	}
	
	return a_2;
}

unsigned int fibunacci_recursive(unsigned int n){
	
	counter(1);
	
	if(n == 0){
		
		return 1;
		
	} else if(n == 1){
		
		return 1;
		
	} else {
		
		return fibunacci_recursive(n-2) + fibunacci_recursive(n-1);
	}
}

int counter(int counter){
	
	static int sum = 0;		/* Variable wird wie eine globale Variable behandelt (Wert bleibt erhalten*/
	
	sum = sum + counter; 
	
	return sum;
}