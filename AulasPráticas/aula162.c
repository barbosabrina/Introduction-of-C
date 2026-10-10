#include <stdio.h>
#include <stdlib.h>

float **alocarMatriz(int d, int a){
    float **m = (float **) malloc(d * sizeof(float *));
    for(int i = 0; i < d; i++){
        m[i] = (float *) malloc(a * sizeof(float));
    }
    return m;
}

void liberarMatriz(float **m, int d){
    for(int i = 0; i < d; i++){
        free(m[i]);
    }
    free(m);
}

int main(void){
    int d, a;

    printf("Digite o numero de delegacoes: ");
    scanf("%d", &d);

    printf("Digite o numero de atletas: ");
    scanf("%d", &a);

    float **alturas = alocarMatriz(d, a);
    float *medias = (float *) malloc(d * sizeof(float));

    printf("Digite as alturas\n");
    for(int i = 0; i < d; i++){
        printf("Delegacao %d:\n", i + 1);
        for(int j = 0; j < a; j++){
            printf("Atleta %d: ", j + 1);
            scanf("%f", &alturas[i][j]);
        }
    }

    for(int i = 0; i < d; i++){
        float soma = 0;
        for(int j = 0; j < a; j++){
            soma += alturas[i][j];
        }
        medias[i] = soma / a;
    }

    float maiorAltura = alturas[0][0];
    for(int i = 0; i < d; i++){
        for(int j = 0; j < a; j++){
            if(alturas[i][j] > maiorAltura){
                maiorAltura = alturas[i][j];
            }
        }
    }

    printf("Media das Alturas\n");
    for(int i = 0; i < d; i++){
        printf("Delegacao %d: %.2f\n", i + 1, medias[i]);
    }

    printf("Maior altura: %.2f\n", maiorAltura);

    liberarMatriz(alturas, d);
    free(medias);

    return 0;
}