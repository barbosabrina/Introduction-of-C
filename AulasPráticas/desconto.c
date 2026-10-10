#include <stdio.h>

	int main(){
	
	float valorFinal, desconto;
	
	printf("Informe o valor do produto: \n");
	scanf("%f", &valorFinal);
	
	if (valorFinal >= 150.00){
	        
	        desconto = valorFinal / 10;
	        valorFinal -= desconto;
		printf("O seu novo valor é %.2f \n", valorFinal);
		return 0;
	}
	if (valorFinal < 150.00){
		printf("O preço continua o mesmo.\n");
	}
	return 0;	
}
