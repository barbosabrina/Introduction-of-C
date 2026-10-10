#include <stdio.h>

int main(){

	int i;
	float n, soma;
	soma = 0;
	
	printf("Digite um valor: ");
	scanf("%f", &n);
		
		if(n == 0){
		printf("Não foi possível calcular MA!\n");
		return 0; 
		}
		
		else{
		soma += n;
		}
	i = 1;
	
	do{	
		printf ("Digite um valor: ");
		scanf("%f", &n);
		soma += n;
		i++;
		
	}while(n != 0);
	
	i -= 1;
	float ma = soma / i; 
	
	printf("MA = %.2f\n", ma);
	
	return 0;
}
