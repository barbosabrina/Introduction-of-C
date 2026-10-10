#include <stdio.h> 

long int fat(int n){
	
	long int op;
	op = 1;
	
	for(int i = 1; i <= n; i++){
		op *= i;
	}
	
	return op;
}

int main(){

	int num;
	
	printf("Digite o valor de n: ");
	scanf("%d", &num);
	
	long int fatorial = fat(num);
	
	printf("%d! = %ld \n", num, fatorial);
	
	return 0;
	
}
	
			
