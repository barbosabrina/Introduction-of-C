#include <stdio.h>

typedef struct{
	char nome[15];
	float potencial;
	float tempo_ativo;
	
}Aparelho;

int main(){

	Aparelho eletro[4];
	int i, t;
	
	for(i = 0; i <  4; i++){
		printf("Eletrodoméstico %d\nNome: ", i);
		scanf("%s", eletro[i].nome);
		printf("Consumo (kW/h): ");
		scanf("%f", &eletro[i].potencial);
		printf("Tempo ativo em horas: ");
		scanf("%f", &eletro[i].tempo_ativo);
		printf("\n");
	}
	
	printf("Número de dias para o cálculo: ");
	scanf("%d", &t);
	printf("\n");
	
	float itens[4];
	float consumoTotal = 0;
	
	for(i = 0; i < 4; i++){
		itens[i] = eletro[i].potencial * eletro[i].tempo_ativo * t;
		consumoTotal += itens[i];
	}
	
	float porcentagens[4];
	
	for(i = 0; i < 4; i++){
		porcentagens[i] = (itens[i] / consumoTotal) * 100;
	}
	
	printf("Consumo total: %.1fkW\n", consumoTotal);
	printf("\n");
	printf("Porcentagens:\n");
	
	for(i = 0; i < 4; i++){
		printf("%s %.2f%%", eletro[i].nome, porcentagens[i]);
		printf("\n");
	}
	
	
	return 0;
}
