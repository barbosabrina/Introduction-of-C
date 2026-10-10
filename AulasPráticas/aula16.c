#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q);

int main(){

    int i, j, n, m, p, q;
    int **r;

    printf("Digite os tamanhos da matriz A: ");
    scanf("%d%d", &n, &m);

    int **matrizA = malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){ 
        matrizA[i] = malloc(m * sizeof(int));
    }
    printf("Digite os dados da matriz A:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("Digite os tamanhos da matriz B: ");
    scanf("%d%d", &p, &q);

    int **matrizB = malloc(p * sizeof(int *));
    for(i = 0; i < p; i++){ 
        matrizB[i] = malloc(q * sizeof(int));
    }
    printf("Digite os dados da matriz B:\n");
    for(i = 0; i < p; i++){
        for(j = 0; j < q; j++){
            scanf("%d", &matrizB[i][j]);
        }
    }

    int ok = multiplicaMatrizes(&r, matrizA, n, m, matrizB, p, q);

    if(ok){
        printf("Resultado de A x B:\n");
        for(i = 0; i < n; i++){
            for(j = 0; j < q; j++){
                printf("%d ", r[i][j]);
            }
            printf("\n");
        }
        for(i = 0; i < n; i++) 
            free(r[i]);                   
        free(r);
    }

    for(i = 0; i < n; i++) 
        free(matrizA[i]);
    free(matrizA);

    for(i = 0; i < p; i++) 
        free(matrizB[i]);
    free(matrizB);

    return 0;
}

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q){
    
    if(m != p){
        printf("Não é possível multiplicar as matrizes A e B.\n");
        return 0;
    }

    int i, j, k;

    int **matrizR = malloc(n * sizeof(int *));
    for(i = 0; i < n; i++){ 
        matrizR[i] = malloc(q * sizeof(int));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
            matrizR[i][j] = 0;
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < q; j++){
            for(k = 0; k < m; k++){
                matrizR[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    *R = matrizR;
    return 1;
}