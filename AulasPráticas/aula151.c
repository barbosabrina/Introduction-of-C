#include <stdio.h>
#include <stdlib.h>

int** criaMatriz(int m, int n);
void liberaMatriz(int** A, int m);
int procura_valor(int **A, int m, int n, int valor);

int main() {

    int m, n, valor, i, j;
    int **a;

    printf("Digite o valor de m e n: ");
    scanf("%d %d", &m, &n);

    a = criaMatriz(m, n);

    printf("Digite a matriz:\n");
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            }
        }

    printf("Digite o valor a ser procurado: ");
    scanf("%d", &valor);

    if (procura_valor(a, m, n, valor)) {
        printf("\nValor encontrado!\n");
    } 
    else {
        printf("\nValor não encontrado!\n");
    }

    liberaMatriz(a, m);

    return 0;
}

int** criaMatriz(int m, int n) {

    int **a = malloc(m * sizeof(int*));
        if (a == NULL) {
        return NULL;
        }

    for (int i = 0; i < m; i++) {
        a[i] = malloc(n * sizeof(int));

        if (a[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(a[j]);
            }
            free(a);
            return NULL;
        }
    }
    return a;
}

void liberaMatriz(int** a, int m) {
    if (a != NULL) {
        for (int i = 0; i < m; i++) {
            free(a[i]); 
        }
        free(a); 
    }
}

int procura_valor(int **a, int m, int n, int valor) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == valor) {
                return 1; 
            }
        }
    }
    return 0; 
}