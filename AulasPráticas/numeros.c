#include <stdio.h>

	int main(){
	
	int a, b, c, d, e, menor;
	
	printf("Insira 5 numeros: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	if ( a < b && a < c && a < d && a < e)
		menor = a;
	else 
	
	if (b < a && b < c && b < d && b < e)
		menor = b;
	else 
	
	if (c < a && c < b && c < d && c < e)
		menor = c;
	else
	
	if (d < a && d < b && d < c && d < e)
		menor = d;
	else 
		menor = e;
		
	printf("O menor número é %d \n", menor);
	
	return 0;
		
	}
		
