#include <stdio.h>

void mediaPrato(float pratos[5][4], float medias[5]){

	int i, j;
	float soma, media;
	
	for(i = 0; i < 5; i++){
		soma = 0.0;
		for (j = 0; j < 4; j++){
		soma += pratos[i][j];
		}
		media = soma/4;
		medias[i] = media;
	}
	
	printf("----------Médias dos pratos-----------\n");
	for(i = 0; i < 5; i++){
		printf("%.2f", medias[i]);
		printf("\n");
	}
}
int pratoVencedor(float pratos[5][4]) {
   
    int i, j;
    float somas[5] = {0, 0, 0, 0, 0}; 
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4; j++) {
            somas[i] += pratos[i][j];
        }
    }
    
    int maiorIndice = 0;
    float maiorSoma = somas[0];
    
    for(i = 1; i < 5; i++) {
        if(somas[i] > maiorSoma) {
            maiorSoma = somas[i];
            maiorIndice = i;
        }
    }
    
    return maiorIndice + 1; 
}

int main() {
    float pratos[5][4];
    float medias[5];
    int i, j;
    
   
    for(i = 0; i < 5; i++) {
        printf("Digite as 4 notas do prato %d:\n", i + 1);
        for(j = 0; j < 4; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &pratos[i][j]);
        }
        printf("\n");
    }
    
    mediaPrato(pratos, medias);
    int ven = pratoVencedor(pratos);
    
    printf("\n-------------Prato vencedor-------------\n");
    printf("Prato numero %d\n", ven);
    
    return 0;
}
