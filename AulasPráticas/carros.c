#include <stdio.h>
#include <string.h>

typedef struct{
	char modelo[25];
	float consumo;
}Carro;

void limparBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void encontrarMaisEconomico(Carro carros[]);

void calcularConsumoViagem(Carro carros[]);

int main(){
	
	int i;
	Carro carros[5];
	
	for(i = 0; i < 5; i++){
		printf("Carro %d\nModelo: ", i);
		scanf("%s", carros[i].modelo); 
		limparBuffer();
		printf("Consumo (km/l): "); 
		scanf("%f", &carros[i].consumo);
		printf("\n");
	}
	
	encontrarMaisEconomico(carros);
	printf("\n");
	calcularConsumoViagem(carros);
	
	return 0;
}

void encontrarMaisEconomico(Carro carros[]){

	int i;
	char melhorModelo[25];
	float maior = 0.0;
	
	for(i = 0; i < 5 ; i++){
		if (carros[i].consumo > maior){
		maior = carros[i].consumo;
		strcpy(melhorModelo, carros[i].modelo);
		}
	}
	
	printf("Mais econômico: %s\n", melhorModelo);
}

void calcularConsumoViagem(Carro carros[]){

	int i;
	
	printf("Consumo em 1000 km\n");
	printf("\n");
	
	for(i = 0; i < 5; i++){
		float consumo = 1000.0/carros[i].consumo;
		printf("%s %.2f\n", carros[i].modelo, consumo);
	}
}
	
