#include <stdio.h>
	
	float main(){
	
	//Declaraçõ das var para armazenar os valores das temperaturas
	float grauC, grauF, grauK;
	
	//Entrada da temperatura em celsius
	printf("Entre com o valor em graus Celsius: \n");
	scanf("%f", &grauC);
	
	//Operações com o valor de entrada oferecido
	grauF = (grauC * 9.00)/5 + 32.00;
	grauK = grauC + 273.15;
	
	//Saída dos valores armazenados e calculados
	printf ("Celsius: c = %.2f \n", grauC);
	printf ("Fahrenheit: f = %.2f \n", grauF);
	printf ("Kelvin = k = %.2f \n", grauK);
	
	return 0;
	
	}
