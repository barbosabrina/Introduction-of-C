#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    float preco;
}Jogo;

Jogo* leArquivo(char *nomeArquivo, int *n);
void imprimeRelatorio(Jogo *jogos, int n);

int main(int argc, char **argv){

    if(argc < 2){
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    char nomeArq[100];
    strcpy(nomeArq, argv[1]);

    int n;
    Jogo *jogos = leArquivo(nomeArq, &n);

    if(jogos == NULL){
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }

    imprimeRelatorio(jogos, n);

    free(jogos);
    return 0;
}

Jogo* leArquivo(char *nomeArquivo, int *n){

    FILE *arquivo = fopen(nomeArquivo, "r");

    if(arquivo == NULL){
        return NULL;
    }

    fscanf(arquivo, "%d", n);

    Jogo *jogos = malloc((*n) * sizeof(Jogo));

    for(int i = 0; i < *n; i++){
        fscanf(arquivo, "%s", jogos[i].nome);
        fscanf(arquivo, "%f", &jogos[i].preco);
    }

    fclose(arquivo);

    return jogos;
}

void imprimeRelatorio(Jogo *jogos, int n){

    printf("\nLista de jogos:\n");
    for(int i = 0; i < n; i++){
        printf("%s %.2f\n", jogos[i].nome, jogos[i].preco);
    }

    float soma = 0;
    for(int i = 0; i < n; i++){
        soma += jogos[i].preco;
    }
    float media = soma / n;
    printf("A media de precos e: %.2f\n", media);

    int indiceMaisCaro = 0;
    for(int i = 1; i < n; i++){
        if(jogos[i].preco > jogos[indiceMaisCaro].preco){
            indiceMaisCaro = i;
        }
    }
    printf("O mais caro e: %s\n", jogos[indiceMaisCaro].nome);
}