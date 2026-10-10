#include <stdio.h>
#include <string.h>

int main(){

    char string1[21];

    printf("Digite a palavra: "); //Ler uma palavra ate 20 
    scanf("%s", &string1[21]);

    int tam = strlen(string1); //Tamanho da palavra

    char string2[21]; //Nova string

    printf("Digite outra palavra: "); //Entrada da segunda str
    scanf("%s", &string2[21]);

    int comp = strcmp(string1, string2); //Comparação entre as duas strings para qual é maior

    strcat(string1, string2); //Concatenar uma string em outra

    printf("%s\n", string1);
    printf("O tamanho é %d\n", tam);
    printf("%s\n", string2);
    printf("%d\n", comp);
    printf("%s\n", string1);


    for(int i = tam - 1; i >= 0; i--){
        printf("%c", string1[i]); 
    } //Imprimir palavra de tras pra frente

    printf("\n");

    char c; //Novo caractere para ser escolhido

    printf("Digite um caractere: ");
    scanf("%c", &c); //Entrada do caractere

    int quant = 0;//Inicializaçao da quantidade 

    for(int i = 0; i < tam; i++){ //Enquanto i for menor que o tamanho da palavra
        if(string1[i] == c){
            quant += 1; //Se o caractere dessa posiçao for == ao escolhido, adicionara 1 a quantidade
        }
    }

    printf("\n %d \n", quant); //imprimir o quant final

    strstr(string1, string2);

    printf("%s\n", string1);

    return 0;
}