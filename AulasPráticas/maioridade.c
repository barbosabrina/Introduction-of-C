#include <stdio.h>

	int main(){
	
	int nascimento, atual;
	
	printf("Informe seu ano de nascimento e o ano atual: ");
	scanf("%d %d", &nascimento, &atual);
	
	int idade = atual - nascimento;
	
	if(idade >= 18){
		printf("Vocẽ já pode tirar a carteira de motorista! \n");
	}
	if(idade < 18){
		printf("Você ainda não pode dirigir. \n");
	}
	
	return 0;
	
}
	
