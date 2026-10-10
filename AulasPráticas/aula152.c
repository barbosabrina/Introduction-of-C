#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int m, int n);
void liberaMatriz(int** A, int m);
int** transposta(int **A, int m, int n);

int main() {
    int m, n, i, j;
    int **mat, **matT;

    printf("Digite o valor de m e n: ");
    scanf("%d %d", &m, &n);

    mat = criaMatriz(m, n);

    printf("Digite a matriz:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    matT = transposta(mat, m, n);

    printf("Transposta:\n");
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) { 
            printf("%d ", matT[i][j]);
        }
        printf("\n");
    }

    liberaMatriz(mat, m);
    liberaMatriz(matT, n);

    return 0;
}

int** criaMatriz(int m, int n) {
    int **matriz = malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        matriz[i] = malloc(n * sizeof(int));
        if (matriz[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

void liberaMatriz(int** matriz, int m) {
    if (matriz != NULL) {
        for (int i = 0; i < m; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }
}

int** transposta(int **matriz, int m, int n) {

    int **matT = criaMatriz(n, m);
    if (matT == NULL) {
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matT[j][i] = matriz[i][j];
        }
    }

    return matT;
}