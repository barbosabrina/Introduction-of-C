#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

int main() {

    int vetor[TAMANHO];
    int limiar;
    int i;

    // Iniciando a semente
    srand(10);

    // Preenchendo o vetor com numeros entre 0 a 199 
    for (i = 0; i < TAMANHO; i++) {
        vetor[i] = rand() % 200;
    }

    printf("Digite um número: ");
    
    if (scanf("%d", &limiar) != 1) {
        printf("Erro ao ler o numero.\n");
        return 1;
    }

    printf("\n Maiores: ");
    for (i = 0; i < TAMANHO; i++) {
        if (vetor[i] >= limiar) {
            printf("%d ", vetor[i]);
        }
    }
    
    printf("\n Menores: ");
    for (i = 0; i < TAMANHO; i++) {
        if (vetor[i] < limiar) {
            printf("%d ", vetor[i]);
        }
    }
    
    printf("\n");

    return 0;
}
