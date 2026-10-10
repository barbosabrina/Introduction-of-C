#include <stdio.h>

	int main(){
	
	int x;
	printf("Digite um número: ");
	scanf("%d", &x);
	
	if((x > 10) && (x < 50) && (x % 2 == 0)){
		printf("Número Válido! \n");
	}
	if ((x < 10) || (x > 50) || (x % 2 == 1)){
		printf("Número Inválido. \n");
	}
	
	return 0;
	
}
