#include <stdio.h>

	int main(){
	
	int x, y, maior;
	printf("Digite dois numeros: ");
	scanf("%d %d", &x, &y);
	
	if( x == y){
		printf("Ambos valores são iguais. \n");
		return 0;
	}	
	if (x > y){
		maior = x;
	}
	if (y > x){
		maior = y;
	}
	printf("O maior numero é %d \n", maior);
	
	return 0;
	
}
