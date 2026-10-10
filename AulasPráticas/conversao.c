#include <stdio.h>

	int main(){
	
	int a, b;
	float  graus, rad, c, f, k;
	
	printf("### CONVERSOR DE UNIDADES ### \n \n 1) Angulo \n 2) Temperatura \n \n Digite uma opcao: "); 
	scanf("%d", &a);
	
	switch(a){
	
	case 1:
		printf("\n Qual a unidade de origem? \n \n 1) Graus \n 2) Radianos \n \n Selecione uma opcao: ");
		scanf("%d", &b);
		
		switch(b){
		
		case 1: 
			printf("\n Digite o valor em Graus: ");
			scanf("%f", &graus);
		        rad = (graus * 3.14)/180;
		        printf("Valor em Radianos: %.2f \n", rad);
		        break;
		        
		case 2: 
			printf("Digite o valor em Radianos: ");
			scanf("%f", &rad);
		        graus = (rad * 180)/3.14;
		        printf("Valor em Radianos: %.2f \n", graus);
		        break;
		        
		default:
			printf("ERRO: opção inválida"); return 0;
		}
	break;
	
	case 2: 
		printf("\n Qual a unidade de origem? \n \n 1) Celsius \n 2) Fahrenheit \n 3) Kelvin \n \n Selecione uma opcao: "); scanf("%d", &b);
		
		switch(b){
		
		case 1:
			printf("\n Digite o valor em Celsius: ");
			scanf("%f", &c);
			f = (c * 1.8)+32;
			k = c + 273.15;
			printf("Valor em Fahrenheit: %.2f \n Valor em Kelvin: %.2f \n", f, k);
			break;
			
		case 2: 
			printf("\n Digite o valor em Fahrenheit: ");
			scanf("%f", &f);
			c = (f - 32)/1.8;
			k = c + 273.15;
			printf("Valor em Celsius: %.2f \n Valor em Kelvin: %.2f \n", c, k);
			break;
		
		case 3: 
			printf("\n Digite o valor em Kelvin: ");
			scanf("%f", &k);
			f = ((k - 273.15)* 1.8) +32;
			c = k - 273.15;
			printf("Valor em Celsius: %.2f \n Valor em Fahrenheit: %.2f \n", c, f);
			break;
		
		default:
			printf("ERRO: opção inválida"); return 0;
		}
	break;
	}
	
	return 0;
}
