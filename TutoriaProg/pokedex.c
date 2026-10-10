#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int num;
    char nome[30];
    char tipo[20];
    bool status;
} Pokemon;

void atualizaPokedex();
void buscaPokemon();
void limpar_buffer();

void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main() {
    int cod;

    do {
        printf("\n-----Minha Pokedex:-----\n");
        printf("1 - Adicionar Pokemon\n");
        printf("2 - Consultar Pokemon\n");
        printf("3 - Sair\n");
        printf("\n     Escolha:   ");
        
        if (scanf("%d", &cod) != 1) {
            limpar_buffer();
            continue;
        }

        switch (cod) {
            case 1:
                atualizaPokedex();
                break;
            case 2:
                buscaPokemon();
                break;
            case 3:
                printf("Fechando Pokedex...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (cod != 3);

    return 0;
}

void atualizaPokedex() {

    FILE *arquivo = fopen("pokedex.dat", "ab");
    Pokemon p;
    char capturado;

    while (1) {
        printf("\nNumero (0 para sair): ");
        scanf("%d", &p.num);
        if (p.num == 0) {
            printf("Voltando ao menu...\n");
            break;
        }

        printf("Nome: ");
        limpar_buffer();
        scanf("%s", p.nome); 

        printf("Tipo: ");
        limpar_buffer();
        scanf("%s", p.tipo);

        printf("Capturado ('S' ou 'N'): ");
        limpar_buffer();
        scanf(" %c", &capturado);

        if (capturado == 'S' || capturado == 's') {
            p.status = true;
        } else {
            p.status = false;
        }

        fwrite(&p, sizeof(Pokemon), 1, arquivo);
        printf("Pokemon salvo!\n");
    }

    fclose(arquivo);
}

void buscaPokemon() {
    char continuar_busca = 'S';

    while (continuar_busca == 'S' || continuar_busca == 's') {
        FILE *arquivo = fopen("pokedex.dat", "r+b"); 
        if (arquivo == NULL) {
            printf("A Pokedex esta vazia ou o arquivo nao existe ainda!\n");
            return;
        }

        char nomeP[30];
        printf("\nDigite o nome do Pokemon que deseja buscar: ");
        limpar_buffer();
        scanf("%s", nomeP);

        Pokemon p;
        bool encontrado = false;
        long posicao;

        while (1) {
            posicao = ftell(arquivo);
            if (fread(&p, sizeof(Pokemon), 1, arquivo) != 1) {
                break; 
            }

            if (strcmp(p.nome, nomeP) == 0) {
                encontrado = true;
                printf("Dados do Pokemon:\n");
                printf("[%d] %s (%s) - Status: %s\n", p.num, p.nome, p.tipo, p.status ? "Capturado" : "Nao Capturado");

                char opcao;
                printf("Deseja alterar o estado de captura? ('S' ou 'N'): ");
                scanf(" %c", &opcao);

                if (opcao == 'S' || opcao == 's') {
                    p.status = !p.status; 

                    fseek(arquivo, posicao, SEEK_SET);
                    fwrite(&p, sizeof(Pokemon), 1, arquivo);
                    printf("Estado de captura atualizado com sucesso!\n");
                }
                break; 
            }
        }

        if (!encontrado) {
            printf("Pokemon nao encontrado!\n");
        }

        fclose(arquivo);

        printf("\nDeseja buscar outro Pokemon? ('S' ou 'N'): ");
        scanf(" %c", &continuar_busca);
    }
    printf("Encerrando a consulta...\n");
}