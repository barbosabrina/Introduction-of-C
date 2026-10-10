#include <stdio.h>

typedef struct{
	char cord;
	float x;
	float y;
	
}Cord;

void limpar_buffer() {
   int ch;
   while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(){
	
	char nome[50];
	int quantP, i;
	Cord pontos[5];
	// Criação do arquivo
	FILE *arquivo;
	
	printf("Digite o número de pontos:");
	scanf("%d", &quantP);
	
	for(i = 0; i < 5; i++){
		int j = i + 1;
		printf("Ponto %d\n", j);
		printf("Digite o identificador, a coord. x e coord. y:");
		//Limpar o buffer antes de ler cada caractere
		limpar_buffer();
		
		scanf("%c %f %f", &pontos[i].cord, &pontos[i].x, &pontos[i].y);
	}
	
	//Limpar o buffer antes de ler o nome do arquivo
	printf("Digite o nome do arquivo para salvamento:");
	limpar_buffer();
	scanf("%s", nome);
	
	//Abrir o arquivo criado e colocar o nome digitado
	arquivo = fopen(nome, "w");
	
		//Armazenar a quantidade de pontos no arquivo
		fprintf(arquivo, "%d\n", quantP);
		
		//Gravar cada ponto digitado na struct
		for(i = 0; i < 5; i++) {
			fprintf(arquivo, "%c %.1f %.1f\n", pontos[i].cord, pontos[i].x, pontos[i].y);
    		}
    		
	//Fechar o arquivo após tudo finalizado
	fclose(arquivo);
	
	return 0;
}
	
	
	
	
