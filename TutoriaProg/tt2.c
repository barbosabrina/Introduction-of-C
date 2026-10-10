#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titulo[100];
    char autor[100];
}Livro;

Livro **alocarEstante(int linhas, int colunas);
void desalocarEstante(Livro **estante, int linhas);
int adicionarLivro(Livro **estante, int linhas, int colunas, int capacidadeMaxima, int quantidadeAtualdeLivros);
int removerLivro(Livro **estante, char *titulo, Livro *livroRemovido, int linhas, int colunas,
    int capacidadeMaxima, int quantidadeAtualdeLivros);

int main(){

    Livro livroRemovido;
    int lin, col;
    char titulo[100];
    int quantidadeAtualdeLivros = 0;

    printf("Entre com linhas e colunas: ");
    scanf("%d%d", &lin, &col);

    Livro **estante = alocarEstante(lin, col);
    int capacidadeMaxima = lin * col;

    int cod;

    do{
        printf("\nVocê gostaria de fazer o que?\n");
        printf(" 1- Pegar um livro\n");
        printf(" 2- Devolver um livro\n");
        printf(" 3- Sair\n");
        printf("\nDigite um número: ");

        do{
            scanf("%d", &cod);
        }while(cod != 1 && cod != 2 && cod != 3); //Verificação se o número está dentre os três

        switch(cod){

            case 1:
                if(quantidadeAtualdeLivros == 0){
                    printf("\nERRO: Estante vazia! Não foi possível pegar nenhum livro.\n");
                    break;
                }
                else{
                    printf("Digite o titulo do livro: ");
                    scanf("%s", titulo);

                    if(removerLivro(estante, titulo, &livroRemovido, lin, col, capacidadeMaxima, quantidadeAtualdeLivros)){
                        quantidadeAtualdeLivros--;
                        printf("%s, escrito por %s foi pego com sucesso!\n", livroRemovido.titulo, livroRemovido.autor);
                    }
                    else{
                        printf("Livro não encontrado!\n");
                    }
                    break;
                }

            case 2:
                if(quantidadeAtualdeLivros == capacidadeMaxima){
                    printf("\nERRO: Estante cheia! Não foi possível guardar o livro.\n");
                    break;
                }
                else{
                    if(adicionarLivro(estante, lin, col, capacidadeMaxima, quantidadeAtualdeLivros)){
                        quantidadeAtualdeLivros++;
                    }
                    break;
                }

            case 3:
                printf("Encerrando programa...\n");
                break;
        }

    }while(cod != 3);

    desalocarEstante(estante, lin);
    return 0;
}

Livro **alocarEstante(int linhas, int colunas) {

    Livro **estante = calloc(linhas, sizeof(Livro *));
    if (estante == NULL)
        return NULL;

    for (int i = 0; i < linhas; i++) {
        estante[i] = calloc(colunas, sizeof(Livro));
        if(estante[i] == NULL)
            return NULL;
    }
    return estante;
}

void desalocarEstante(Livro **estante, int linhas){

    for (int i = 0; i < linhas; i++) {
        free(estante[i]);
    }
    free(estante);
}

int adicionarLivro(Livro **estante, int linhas, int colunas, int capacidadeMaxima, int quantidadeAtualdeLivros){

    char titulo[100];
    char autor[100];

    printf("Digite o titulo do livro: ");
    scanf("%s", titulo);
    printf("Digite o nome do autor: ");
    scanf("%s", autor);

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(estante[i][j].titulo[0] == '\0') {

                strcpy(estante[i][j].titulo, titulo);
                strcpy(estante[i][j].autor, autor);

                printf("Livro adicionado com sucesso!\n");
                return 1;
            }
        }
    }

    printf("A estante está cheia!\n");
    return 0;
}

int removerLivro(Livro **estante, char *titulo, Livro *livroRemovido, int linhas, int colunas,
    int capacidadeMaxima, int quantidadeAtualdeLivros){

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(estante[i][j].titulo[0] != '\0' && strcmp(estante[i][j].titulo, titulo) == 0) {

                *livroRemovido = estante[i][j];

                estante[i][j].titulo[0] = '\0';
                estante[i][j].autor[0] = '\0';

                return 1;
            }
        }
    }
    return 0;
}