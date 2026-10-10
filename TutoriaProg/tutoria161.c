#include <stdio.h>

void mapeamentoViagem(int viagem[], int tam, int *rapido, int *lento, int *media){

	int i, soma;
	soma = 0;
	*lento = viagem[0];
	*rapido = viagem[0];
	*media = 0;
	
	
	for(i = 1; i < tam; i++){
		if (viagem[i] > *rapido)
			*rapido = viagem[i];
	}
	
	for(i = 1; i < tam; i++){
		if (viagem[i] < *lento)
			*lento = viagem[i];
	}
	
	for(i = 0; i < tam; i++){
		soma += viagem[i];
	}
	
	*media = soma/tam;
}

int main(){
	
	int i, rapido, lento, media;
	int viagem[7];
	int tam = 7;
	
	printf("Digite a duração das viagens: ");
	
	for(i = 0; i < 7; i++){
		scanf("%d", &viagem[i]);
	}
	
	mapeamentoViagem(viagem, tam, &rapido, &lento, &media);
	
	printf("A viagem mais lenta foi de %d minutos, a mais rápida foi de %d minutos e a media entre elas é de %d minutos.\n", lento, rapido, media);
	
	return 0;
	
}
	
