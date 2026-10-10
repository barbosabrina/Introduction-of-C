#include <stdio.h>

	int main(){
	
	double preço, valorFinal; 
	int codigo;
	
	printf("Digite o preço do produto: "); scanf("%lf", &preço);
	printf("Digite a condição de pagamento: "); scanf("%d", &codigo);
	
	switch(codigo){
	
	case 1:
		valorFinal = preço - (preço/10);
		break;
	case 2:
		valorFinal = preço - ((preço/10)/5);
		break;
	case 3: 
		valorFinal = preço;
		break;
	case 4:
		valorFinal = preço + (preço/10);
		break;
	default:
		printf("Condicao de pagamento invalida \n"); 
		return 0;
	}
	
	printf("O valor final do seu produto sera: R$ %.2lf \n", valorFinal);
	
	return 0;	
}
