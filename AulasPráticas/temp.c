#include <stdio.h>
float calcularMedia(float tempDias[], int n){
	
	int i;
	float soma, media;
	soma = 0;
	
	for(i = 0; i < 30; i++){
		soma += tempDias[i];
	}
	media = soma / 30;
	
	return media;
}

void contarDias(float tempDias[], int n, float media, int *acima, int *abaixo){
	
	int i;
	*acima = 0;
	*abaixo = 0;
	
	for(i = 0; i < 30; i++){
		if(tempDias[i] > media)
			*acima += 1;
		else if (tempDias[i] < media) 
			*abaixo += 1;
	}
}

int main(){

	float tempDias[30];
	int acima, abaixo;
	int i;
	float media;
	
	printf("Entre com as temperaturas: ");
	
	for(i = 0; i < 30; i++){
		scanf("%f", &tempDias[i]);
	}
	
	media = calcularMedia(tempDias, 30);
	contarDias(tempDias, 30, media, &acima, &abaixo);
	
	printf("\n Acima: %d \n Abaixo: %d \n", acima, abaixo);
	
	return 0;
}
	
