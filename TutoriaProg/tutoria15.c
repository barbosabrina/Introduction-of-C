#include <stdio.h>

void trocaLinhas(int m[3][3], int i, int j){
	
	int aux[3];
	int a;
	for(a = 0; a < 3; a++){
		aux[a] = m[i][a];
		
		m[i][a] = m[j][a];
		
		m[j][a] = aux[a];
	}
	
	printf("\nMatriz resultante\n");

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
		printf("%d ", m[i][j]);
		}
	printf("\n");
	}
	
}	
void multiplicaLinhas(int m[3][3], int i, int k){
	
	int a, j;
	for( a = 0; a < 3; a++){
		m[i][a] *= k;
	}
	
	printf("\nMatriz resultante\n");

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
		printf("%d ", m[i][j]);
		}
	printf("\n");
	}
}
void modificaLinha(int m[3][3], int i, int j, int k){

	int a;
	int aux[3];
	for(a = 0; a < 3; a++){

		aux[a] = m[j][a] * k;
		m[i][a] += aux[a];
	}

	printf("\nMatriz resultante\n");

	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
		printf("%d ", m[i][j]);
		}
	printf("\n");
	}

}	
int main(){

	int m[3][3];
	int cod, i, j, k;
	printf("Informe os elementos da matriz 3 x 3: ");
	
	for (i = 0; i < 3; i++){
		for ( j = 0; j < 3; j++){
		scanf("%d", &m[i][j]);
		}
	}
	
	printf("\n 1. Troca de Linhas \n 2. Multiplicação de Linha \n 3. Substituição de Linha \n Escolha uma operação elementar: "); 
	scanf("%d", &cod);
	
	switch(cod){
	case 1: 
	
		do{
		
		printf("\n Quais linhas vão ser trocadas? ");
		scanf("%d %d", &i, &j);
		
		}while( i == j);
		
		trocaLinhas(m, i, j);
		break;
	
	case 2:
	
		printf("\n Qual linha irá ser multiplicada? ");
		scanf("%d", &i);
		
		do{
			printf("Por qual num será multiplicada? ");
			scanf("%d", &k);
			
		}while(k == 0);	
		
		multiplicaLinhas(m, i, k);
		break;
	
	case 3:
		
		printf("Linha 1: "); scanf("%d", &i);
		printf("Linha 2: "); scanf("%d", &j);
		
		do{
		
		printf("Multiplicador: "); scanf("%d", &k);
		
		}while( k == 0);
		
		modificaLinha(m, i, j, k);
		break;
	
	}
	return 0;
}	
	
