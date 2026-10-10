#include <stdio.h>
#include <math.>

 int main(){
	
	int n;
	printf("Digite um valor de n (inteiro maior que 0): ");
	scanf("%d", &n);
	
	int i = 0; 
	double s = 0;
	
	while (i < n){
		s = s + pow(2,i);
		i++;
	}
	printf("Resultado: %lf\n", s);
	return 0;
 } 
		
	
