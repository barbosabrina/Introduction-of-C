#include <stdio.h>
#include <string.h>

int ajusteNomeTurma(char *nome){
	
	int i;
	
	for(i = 0; nome[i] != '\0'; i++){
	
		if(nome[i] >= 97 && nome[i] <= 122)
			nome[i] -= 32;
	}
	
	if(nome[0] >= 65 && nome[0] <= 77)
		return 1;
	else
		return 2;
}

int main(){

	char nome[51];
	
	printf("Digite o nome do(a) aluno(a): ");
	fgets(nome, 51, stdin);
	
	printf("%s da turma %d \n ", nome, ajusteNomeTurma(nome));
	
	return 0;
	
}


