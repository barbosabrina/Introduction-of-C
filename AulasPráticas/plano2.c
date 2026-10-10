#include <stdio.h> 
#include <math.h> // usar-lm no gcc

typedef struct{
	char cord;
	float x;
	float y;
}Ponto;

float dist2Pontos(Ponto a, Ponto b);

int main(){
	
	Ponto pontos[3];
	char nomeArq[50];
	int pontosArq;
	FILE *arquivo;
	
	printf("Digite o nome do arquivo:");
	scanf("%s", nomeArq);
	
	//Abrindo o arquivo para ler
	arquivo = fopen(nomeArq, "r");
		
		//Busca a quantidade de pontos armazenada na primeira linha do arquivo
		fscanf(arquivo, "%d", &pontosArq);
		
		//Ler os três pontos dentro do vetor criado
		for (int i = 0; i < 3; i++) {
        		fscanf(arquivo, " %c %f %f", &pontos[i].cord, &pontos[i].x, &pontos[i].y);
    		}
    	
    	//Fechando o arquivo depois da execução feita	
    	fclose(arquivo);
    	
    	for (int i = 1; i < 3; i++) {
        	float d = dist2Pontos(pontos[0], pontos[i]);
        	printf("Distância entre %c e %c: %.2f\n", pontos[0].cord, pontos[i].cord, d);
    	}
    	
    	return 0;
}

float dist2Pontos(Ponto a, Ponto b){
    	float termo_x = pow(b.x - a.x, 2);
    	float termo_y = pow(b.y - a.y, 2);
    
   	return sqrt(termo_x + termo_y);
}
    		
    		
