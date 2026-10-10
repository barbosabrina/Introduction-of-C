#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    float nota;
    int frequencia;
}Aluno;

void salvarTXT(Aluno *alunos, int n);
void salvarBIN(Aluno *alunos, int n);

int main(){

    int n;

    printf("Digite a quantidade de alunos: "); scanf("%d", &n);
    Aluno *alunos = malloc(n * sizeof(Aluno));

    if(alunos == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Digite os dados do aluno %d respectivamente: nome, nota, frequencia: ", i+1);
        scanf("%s%f%d", alunos[i].nome, &alunos[i].nota, &alunos[i].frequencia);
    }

    salvarTXT(alunos, n);
    salvarBIN(alunos, n);

    free(alunos);
    return 0;
}

void salvarTXT(Aluno *alunos, int n){

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    for(int i = 0; i < n; i++){
        fprintf(arquivo, "Nome: %s\n", alunos[i].nome);
        fprintf(arquivo, "Nota: %f\n", alunos[i].nota);
        fprintf(arquivo, "Frequencia: %d\n", alunos[i].frequencia);
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void salvarBIN(Aluno *alunos, int n){

    FILE *arquivo;
    arquivo = fopen("arquivo.dat", "wb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    for(int i = 0; i < n; i++){
        fwrite(&alunos[i], sizeof(Aluno), 1 , arquivo);
    }

    fclose(arquivo);
}