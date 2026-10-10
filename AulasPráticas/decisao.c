#include <stdio.h>
#include <math.h>

	int main(){
	
	int x;
	printf("Digite um número: ");
	scanf("%d", &x);
	
	if(x < 0){
		x *= -1;
		printf("Número transformado em positivo.\n");
	}
	
	double raiz = sqrt(x);
	
	if(raiz < 10){
		printf("A raiz é %.1lf \n", raiz);
	}
	if(raiz >= 10){
		printf("A raiz é maior ou igual a 10. \n");
	}
	
	return 0;
	
}
		
		
