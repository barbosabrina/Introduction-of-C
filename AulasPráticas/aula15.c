#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int *vetor1 = malloc(n * sizeof(int));
    
    int quantI = 0;
    int quantP = 0;

    printf("Digite os valores do vetor: ");
    for(i = 0; i < n; i++){
        scanf("%d", &vetor1[i]);
    }

    for(i = 0; i < n; i++){
        if(vetor1[i] % 2 == 0)
            quantP += 1;
        else 
            quantI += 1;
    }

    int indP = 0;
    int indI = 0;

    int *vetorP = malloc(quantP * sizeof(int));
    int *vetorI = malloc(quantI * sizeof(int));

    for(i = 0; i < n; i++){
        if(vetor1[i] % 2 == 0){
            vetorP[indP] = vetor1[i];
            indP++;
        }
        else {
            vetorI[indI] = vetor1[i];
            indI++;
        }
    }

    printf("\nVetor com os valores pares: ");
        if(quantP == 0){
            printf(" Vazio\n");}
        else{
            printf("[ ");
            for(i = 0; i < quantP; i++){
                printf("%d ", vetorP[i]);
            }
        printf("]\n");
        }
    
    printf("Vetor com os valores ímpares: ");
        if(quantI == 0){
            printf(" Vazio\n");}
        else{
            printf("[ ");
            for(i = 0; i < quantI; i++){
            printf("%d ", vetorI[i]);
            }
            printf("]\n");
        }
    free(vetorP);
    free(vetorI);

    return 0;
}
