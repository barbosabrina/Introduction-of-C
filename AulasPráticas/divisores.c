#include <stdio.h>

void divisores(int n){
	
	printf("Os divisores de %d são: ", n); //printf principal para mostrar todos os divisores
	
	int i = 1; //O i começará com 1 pois entrará na divisão
	
	while(i <= n){ 
	//Enquanto o numero de i for menor ou igul que o numero escolhido é possivel de se fazer a divisao
	
		if (n % i == 0){// Se a divisao do numero escolhido pelo i tiver resto igul  0, o numero sera incrementado na tela
		printf("%d ", i);
		}
		
		i++; //De toda forma o numero sera incrementado no codigo desde que satisfaça a condicao apresentada no while
	}
		
		printf("\n"); //Se nõ for com resto 0, sera impresso apenas um espaço para o proximo
		 
}
			
int main(){
	int num;
	
	printf("Digite o valor de n: ");
	scanf("%d", &num); // Entrada do numero escolhido
	
	divisores(num); // Chamada da funçao
	
	return 0;
}


