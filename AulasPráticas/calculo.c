#include <stdio.h> 
#include <math.h>

	int main(){
		
	int a, b, c, d;
	double op; // A variável op recebeu o tipo double por se tratar de uma potencia feita pelo pow
		
	printf("Entre com os valores de a, b, c, d: ");
	scanf("%d %d %d %d", &a, &b, &c, &d); //É importante que primeiro localize os numeros e depois armazene no endereço de cada um
	
	op = pow(a,3) * ((b + c) / (double)d); //O double serve para a divisão não ser somente inteira
		
	printf("x = %.0lf", op); // A formatção é para sair um numero inteiro
		
	return 0;
		
	}
