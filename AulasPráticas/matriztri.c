#include <stdio.h>

void lerMatriz(float dados[3][5][12]);

float mediaCidade(float dados[3][5][12], int cod);

void maiorTemp(float dados[3][5][12]);

int main(){

	float dados[3][5][12]; //Anos, cidades, meses
	int cod;
	float media;
	
	lerMatriz(dados);
	
	printf("Digite o código da cidade para ver a media (0-4): "); scanf("%d", &cod);
	
	media = mediaCidade(dados, cod);
	
	printf("Media da Cidade %d nos 3 anos: %.2f \n", cod, media);
	
	maiorTemp(dados);
	
	return 0;
}

void lerMatriz(float dados[3][5][12]){
	
	int i, j, k;
	
	printf("Digite as temperaturas: ");
	
	for(i = 0; i < 3; i++){
		for (j = 0; j < 5; j++){
			for (k = 0; k < 12; k++){
				scanf("%f", &dados[i][j][k]);
			}
		}
	}
}

float mediaCidade(float dados[3][5][12], int cod){

	int i, j;
	float media, soma;
	soma = 0;
	media = 0;
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 12; j++){
			soma += dados[i][cod][j];
		}
	}
	
	media = soma/36;
	
	return media;
}

void maiorTemp(float dados[3][5][12]){

	int i, j, cidade, mes;
	
	float maiorTemp;
	maiorTemp = 0;
	
	for(i = 0; i < 5; i++){
		for(j = 0; j < 12; j++){
			if (dados[1][i][j] > maiorTemp){
				cidade = 0;
				mes = 0;
				maiorTemp = dados[1][i][j];
				cidade = i;
				mes = j + 1;
			}
		}
	}
	
	printf("Maior temperatura no Ano 2: %.2f (Cidade %d, Mes %d) \n", maiorTemp, cidade, mes);
	
}
	
	
