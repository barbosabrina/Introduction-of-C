#include <stdio.h>

	int verificarElegibilidade(int idade, float score){
	
		int a;
		if(idade >= 18 && score >= 7.5)
			a = 1;
		else 
			a = 0;
	return a;
	}
	
	int main(){
	
	int idade, se; float score;
	
	printf("Digite a idade: "); scanf("%d", &idade);
	printf("Digite o score: "); scanf("%f", &score);
	
	se = verificarElegibilidade(idade, score);
	
	if(se == 1)
		printf("ELEGÍVEL \n");
	else 
		printf("NÃO ELEGÍVEL \n");
		
	return 0;
} 
			
