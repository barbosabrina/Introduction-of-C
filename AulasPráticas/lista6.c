#include <stdio.h>

int main(){

    int mat[50], n, i;
    float n1[50], n2[50], n3[50];

    printf("Quantas matriculas sao? ");
    scanf("%d", &n);

    printf("Digite a matricula, e as tres notas: ");
    for(i = 0; i < n; i++){
        scanf("%d %f %f %f", &mat[i], &n1[i], &n2[i], &n3[i]);
    }

    float soma = 0;
    float media = 0;

    for (i = 0; i < n; i++){
        media = (n1[i] + n2[i] + n3[i])/3;

        if(media >= 6){
            printf("O aluno %d foi aprovado \n", mat[i]);
        }
        else{
            printf("O aluno %d foi reprovado \n", mat[i]);
        }
    }

    return 0;
}