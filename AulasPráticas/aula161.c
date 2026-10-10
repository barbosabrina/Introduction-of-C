#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int **alocarMatriz(int n);
void liberarMatriz(int **m, int n);
bool valorRepetido(int **m, int n, int li, int ci, int valor);
bool quadradoMagico(int **m, int n);


int main() {

    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int **mat = alocarMatriz(n);

    printf("Digite os valores da matriz %d x %d:\n", n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

    int c = quadradoMagico(mat, n);
        if(c){
            printf("\nEsta matriz é um quadrado mágico!\n");
        }
        else{
            printf("\nEsta matriz não é um quadrado mágico!\n");
        }

    liberarMatriz(mat, n);

    return 0;
}

int **alocarMatriz(int n){

    int **m = (int **) malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            m[i] = (int *) malloc(n * sizeof(int));
        }
    return m;
}

void liberarMatriz(int **m, int n){

    for(int i = 0; i < n; i++){
        free(m[i]);
    }

    free(m);
}

bool valorRepetido(int **m, int n, int li, int ci, int valor){

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == li && j == ci){
                return false; 
            }
            if(m[i][j] == valor){
                return true;
            }
        }
    }
    return false;
}

bool quadradoMagico(int **m, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(valorRepetido(m, n, i, j, m[i][j])){
                return false;
            }
        }
    }

    int somaReferencia = 0;
    for(int j = 0; j < n; j++){
        somaReferencia += m[0][j];
    }

    for(int i = 0; i < n; i++){

        int somaLinha = 0;
        for(int j = 0; j < n; j++){
            somaLinha += m[i][j];
        }
        if(somaLinha != somaReferencia){
            return false;
        }
    }

    for(int j = 0; j < n; j++){

        int somaColuna = 0;
        for(int i = 0; i < n; i++){
            somaColuna += m[i][j];
        }
        if(somaColuna != somaReferencia){
            return false;
        }
    }

    int somaDiagPrincipal = 0;
    for(int i = 0; i < n; i++){
        somaDiagPrincipal += m[i][i];
    }
    if(somaDiagPrincipal != somaReferencia){
        return false;
    }

    int somaDiagSecundaria = 0;
    for(int i = 0; i < n; i++){
        somaDiagSecundaria += m[i][n - 1 - i];
    }
    if(somaDiagSecundaria != somaReferencia){
        return false;
    }

    return true;
}

