#include <stdio.h>

int main(){

    int tam, a, b;
    char d;

    do{
        printf("Informe o tamanho da matriz quadrada: ");
        scanf("%d", &tam);

    }while(tam <= 0);

    int mat[tam][tam];

    printf("Diagonal principal (P) ou secundaria(S): ");
    scanf(" %c", &d);

    switch(d){

    case 'P':

        for(a = 0; a < tam; a++){
            for(b = 0; b < tam; b++){
                if(a == b){
                    mat[a][b] = 1;
                }
                else{
                    mat[a][b] = 0;
                }
            }
        }
    break;

    case 'S':

        for(a = 0; a < tam; a++){
            for(b = 0; b < tam; b++){
                if(a + b == tam - 1){
                    mat[a][b] = 1;
                }
                else{
                    mat[a][b] = 0;
                }
            }
        }
        
    }

    printf("\nMatriz resultante:\n");

    for(a = 0; a < tam; a++){
		for(b = 0; b < tam; b++){
		printf("%d ", mat[a][b]);
		}
	    printf("\n");
	}

    return 0;
}