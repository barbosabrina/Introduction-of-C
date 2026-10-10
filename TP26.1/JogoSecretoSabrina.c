//TRABALHO FINAL BCC201-26.1 
//Feito unicamente por Sabrina Barbosa Gomes de Souza. - 26.1.4044
//Finalizado em 13/07/2026.

#include <stdio.h>
#include <stdlib.h>                     
#include <time.h>
#include <string.h>
#include <stdbool.h>

// cores e formato de texto
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"
#define ANSI_COLOR_ORANGE     "\x1b[38;5;208m"
#define ANSI_BG_COLOR_ORANGE  "\x1b[48;5;208m"

// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET
#define ORANGE(string)     ANSI_COLOR_ORANGE     string ANSI_RESET
#define BG_ORANGE(string)  ANSI_BG_COLOR_ORANGE  string ANSI_RESET

//Unica e principal struct para os dados do jogador
typedef struct{
    char nome[51];//Nome
    int cores;//Quantidade de cores em sua sequencia
    int nivel;//Nivel do seu jogo
    int tent;//Quntidade de tentativas
    int tentAcerto;//Tentativa em que o jogador acertou o jogo, caso tenha
    int tentJogadas;//Numero de tentativas ja jogadas pelo jogador
    int **historicoTentativas;//Matriz que guarda o historico de tentativas do jogador
    int *sequenciaCorreta;//Vetor da sequencia correta do jogo
    char (*sequenciaCorretaCores)[51];//Vetor da sequencia correta em palavras do jogo
}Jogador;

//Struct obrigatoria para persistencia no arquivo binario do ranking conforme enunciado
typedef struct {
    char nome[51];
    int nivel;
    int tentativas;
} Ranking;

void ajuda();//Função com todas instruções do jogo
void carregarJogo(bool *jogoEmAndamento, Jogador *jogador);//Funçõ para carregar um jogo já iniciado por algum jogador
void novoJogo(bool *jogoEmAndamento, Jogador *jogador);//Função para criar um novo jogo
void salvarJogo(bool *jogoEmAndamento, Jogador *jogador);//Função para salvar o jogo em andamento em um arquivo
//Função principal da logica do jogo
void jogo(bool *jogoEmAndamento, Jogador *jogador, int *sequenciaCorreta, int *sequenciaJogador, int cores, int tentativaInicial);
void atualizarRanking(Jogador *jogadorAtual);//Função para atualizar e mostrar o novo ranking do jogo
void abrirRanking();//Função somente para abrir o ranking no menu principal
void liberarMemoriaJogador(Jogador *jogador); //Função para liberar memoria alocada e nao dar vazamento     
int menu(bool *jogoEmAndamento, Jogador *jogador);//Função do menu principal

int main(){

    srand(time(NULL));//Inicializo a geração de números aleátorios

    Jogador jogador;//Inicializando o jogador atual
    //Inicializando os ponteiros com NULL para evitar erros de compilação
    jogador.sequenciaCorreta = NULL;
    jogador.sequenciaCorretaCores = NULL;
    jogador.historicoTentativas = NULL;

    bool jogoEmAndamento = false;//Variavel para indicar se há ou não, jogo em andamento
    int voltarMenu;

    //Loop para constantemente após uma funcao, voltar ao menu
    do{
        voltarMenu = menu(&jogoEmAndamento, &jogador); 
    } while(voltarMenu == 1);

    liberarMemoriaJogador(&jogador); //Libera memoria restante ao fechar o programa
    printf("\nObrigada por jogar! :) \n");
    return 0;
}

int menu(bool *jogoEmAndamento, Jogador *jogador){
    
    char cod;
    
    printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
    printf(BLUE("                               "RED("C")YELLOW("Ó")BLUE("D")GREEN("I")MAGENTA("G")ORANGE("O")RED(" S")YELLOW("E")BLUE("C")GREEN("R")MAGENTA("E")ORANGE("T")RED("O")" FEITO POR SABRINA BARBOSA            \n"));
    printf("=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");

    printf("\n");
    printf(BOLD("                                   Como deseja começar?                  \n"));
    printf(RED(BOLD("\n A"))" - Ajuda\n");
    printf(BLUE(BOLD("\n N"))" - Novo Jogo\n");
    printf(YELLOW(BOLD("\n C"))" - Carregar Jogo\n");
    printf(GREEN(BOLD("\n R"))" - Ranking\n");
    printf(MAGENTA(BOLD("\n S"))" - Salvar Jogo\n");
    printf(ORANGE(BOLD("\n X"))" - Sair\n");

    //A variavel cod irá armazenar a opçao que o usuario deseja fazer
    //O do/while vai obrigar o usuario digitar uma das opções de letras
    printf(BOLD("\n                               Informe a letra que deseja: "));
    do{
        scanf(" %c", &cod);
        if(cod != 'A' && cod != 'a' && cod != 'N' && cod != 'n' && cod != 'C' && cod != 'c' && cod != 'S' && cod != 's' && cod != 'R' && cod != 'r' &&cod != 'X' && cod != 'x')
           printf("\n"RED("ERRO:")" Letra inválida. Tente novamente: ");
    }while(cod != 'A' && cod != 'a' &&
           cod != 'N' && cod != 'n' && 
           cod != 'C' && cod != 'c' && 
           cod != 'S' && cod != 's' && 
           cod != 'R' && cod != 'r' &&
           cod != 'X' && cod != 'x');
    
    switch(cod){//Loop para entrada de opções

        //Uso das duas formas de letras
        case 'A':
        case 'a':
            ajuda();
            return 1;
        break;
        case 'N':
        case 'n':
            novoJogo(jogoEmAndamento, jogador);
            return 1;
        break;
        case 'C':
        case 'c':
            carregarJogo(jogoEmAndamento, jogador);
            return 1;
        break;
        case 'S':
        case 's':
            salvarJogo(jogoEmAndamento, jogador);
            return 1;
        break;
        case 'R':
        case 'r':
            abrirRanking();
            return 1;
        break;
        //Caso o jogador queira sair e houver um jogo em andamento, o programa pergunta se quer salvá-lo e faz o processo de chamar a função salvar jogo
        case 'X':
        case 'x':
            if(*jogoEmAndamento){
                char salvarOpcao;
                printf("\nHá um jogo em andamento! Deseja salvá-lo antes de sair? (S/N): ");
                scanf(" %c", &salvarOpcao);
                    if (salvarOpcao == 'S' || salvarOpcao == 's') {
                        salvarJogo(jogoEmAndamento, jogador);
                    }
            }
            return 0;
        break;
        }
    return 0;
}

void ajuda(){ 

    char sair;

    //RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "-"
        BOLD("GUIA DE AJUDA")
        "-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")
        "\n"
    );

    printf("\nSeja bem-vindo(a) ao jogo Código Secreto das Cores, feito por "BOLD("Sabrina Barbosa.\n"));

    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "-"
        BOLD("IDEIA PRINCIPAL")
        "-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "\n"
    );

    printf("\nInicialmente o jogo irá gerar uma sequência aleátoria de cores que você deverá acertar em sua ordem correta.\n");

    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "-"
        BOLD("COMO FUNCIONA?")
        "-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "\n"
    );
    printf("\nAo iniciar um novo jogo, você poderá escolher o nível de dificulade que gostaria de jogar, sendo assim:\n");
    
    printf("\n------------------------------------------------------------------------------------------------------\n");
    printf("                         "BOLD("Nível")"        "BOLD("Tamanho da sequência")"      "BOLD("Tentativas")"                              \n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("                         Fácil              4 cores                10                                   \n");
    printf("                         Médio              5 cores                12                                   \n");
    printf("                         Difícil            6 cores                15                                   \n");
    printf("------------------------------------------------------------------------------------------------------\n");

    printf("\nDessa forma, de acordo com o nível escolhido, você terá que informar a quantidade de cores selecionada e \nterá respectivas tentativas para acertar a ordem exatamente como for.\n");
    printf("Para informar as cores, você deverá informar o código delas de acordo com a tabela de possibilidades abaixo.\n");

    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("                                  "BOLD("Código")"                "BOLD("Cor")"                                           \n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf(RED("                                    1                 Vermelho                                         \n"));
    printf(BLUE("                                    2                   Azul                                           \n"));
    printf(GREEN("                                    3                  Verde                                           \n"));
    printf(YELLOW("                                    4                 Amarelo                                          \n"));
    printf(MAGENTA("                                    5                   Roxo                                           \n"));
    printf(ORANGE("                                    6                  Laranja                                         \n"));
    printf("-------------------------------------------------------------------------------------------------------\n");

    printf(RED(BOLD("\nImportante!"))" O programa só irá aceitar sua resposta devidamente correta se os códigos forem digitados na \nordem correta das cores.\nNesse caso poderá ocorrer três situações:\n");
    
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf(" 1) Cor certa no lugar certo       O programa irá lhe retornar a letra "GREEN("'C'")"                             \n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf(" 2) Cor certa no lugar errado      O programa irá lhe retornar a letra "YELLOW("'E'")"                               \n");    
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf(" 3) Cor não existe na senha        O programa irá lhe retornar a letra "RED("'X'")"                             \n");    
    printf("-------------------------------------------------------------------------------------------------------\n");

    printf(RED(BOLD("\nAviso!"))" O programa não irá informar necessariamente na ordem do código em que você informou, exemplo: \n");
    printf("\nEXEMPLO Sequência correta: 3 3 2 1\n");
    printf("EXEMPLO Digitado por você: 3 1 2 6\n");
    printf("Resposta do jogo: "GREEN("[C]")YELLOW(" [E] [E]")RED(" [X]")"\n");
    printf("\nComo você pode ver, a resposta oferecida não apresenta lugar exato de onde estão os acertos ou falhas.\n");

    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")
        "-JOGOS ANTERIORES-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "\n"
    );
    printf("\n- Se você não quiser continuar o jogo, deve apertar na opção de salvar. Com isso, informe o nome do\narquivo que quer salvá-lo e assim, poderá continuar novamente.\n");
    printf("- Se você já tiver feito isso, poderá acessar seu antigo jogo por meio da tecla 'C' no menu principal.\nAssim, informe o nome que escolheu para acessá-lo.\n");

    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=") GREEN("~")
        "-FINAL DE JOGO-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        "\n"
    );
    printf("\nO jogo acaba se você acertar a sequência na ordem certa ou quando o número de tentativas for atingido.\nQuando uma dessas opções for alcançada, você pode escolher entre voltar para o menu ou sair \ncompletamente do jogo.\n");
    printf("\nVoltando para o menu, você pode acessar a aba de ranking de jogos.\n");
    printf("\nO ranking irá informar a classificação dos últimos 10 jogadores de acordo com a facilidade \npara acertar a ordem.\nSe você acertar de primeira, ganha 10 pontos, de segunda 9 pontos, de terceira 8 pontos e assim \npor diante.\n");
    printf("\nNesse caso, os rankings serão separados pelo nível de jogo que os jogadores escolheram, visto que acertar \nde primeira no nível difícil te concede 15 pontos.\n");

    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        "-ATENÇÃO-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "\n"
    );
    printf("\n 1) O programa não aceitará códigos de cores que não estão disponíveis.\n");
    printf(" 2) Assim que o número de tentativas for atingido, o jogo irá mostrar a nequência correta e NÃO será \npossível alterar.\n");
    printf(" 3) Para acessar o jogo保存, deve-se informar o nome correto que foi salvo, pelo contrário, não poderá \nacessá-lo.\n");
    printf(" 4) Quando o jogo for pausado e salvo, seu progresso será salvo exatamente como for, assim, obedecendo \na quantidade de tentativas que faltam.\n");
   
    printf(BOLD("\n                      Agora sim, devidamente informado(a) aproveite o jogo!                         \n"));
    
    printf(BOLD("                               Pressione 'M' para voltar ao menu.                                     \n"));
        do {
            scanf(" %c", &sair);
        } while(sair != 'M' && sair != 'm');
}

void liberarMemoriaJogador(Jogador *jogador) {

    //Se neessario, liberação de todas as memorias alocadas no meio do codigo
    if (jogador->sequenciaCorreta != NULL) {
        free(jogador->sequenciaCorreta);
        jogador->sequenciaCorreta = NULL;
    }
    if (jogador->sequenciaCorretaCores != NULL) {
        free(jogador->sequenciaCorretaCores);
        jogador->sequenciaCorretaCores = NULL;
    }
    if (jogador->historicoTentativas != NULL) {
        for (int g = 0; g < jogador->tent; g++) {
            if (jogador->historicoTentativas[g] != NULL) {
                free(jogador->historicoTentativas[g]);
            }
        }
        free(jogador->historicoTentativas);
        jogador->historicoTentativas = NULL;
    }
}

void novoJogo(bool *jogoEmAndamento, Jogador *jogador){                                                            

    int i;
    jogador->tentAcerto = 0;//Inicializa a tentativa de acerto com 0 

    //Evita vazamento limpando estruturas se ja existirem antes de criar um novo jogo
    liberarMemoriaJogador(jogador);

    //Entrada principal dos dados da struct do jogador
    printf("\n Digite seu nome: "); 
    int c;
    while ((c = getchar()) != '\n' && c != EOF);//Limpar o buffer que pode ter ficado da escolha no menu principal
    fgets(jogador->nome, 51, stdin);
    jogador->nome[strcspn(jogador->nome, "\n")] = '\0'; //Remove a quebra de linha capturada pelo fgets

    printf("\n                     "BOLD("Qual nível de dificuldade você gostaria de jogar? \n"));
    printf("\n"GREEN("1) Fácil ")"- 10 tentativas\n");
    printf("\n"YELLOW("2) Médio ")"- 12 tentativas\n");
    printf("\n"RED("3) Difícil ")"- 15 tentativas\n");   
    printf("\n                          "BOLD("Informe o número do nível escolhido: "));

    do{
        scanf("%d", &jogador->nivel);
        if(jogador->nivel != 1 && jogador->nivel != 2 && jogador->nivel != 3)
            printf("\n"RED("ERRO:")" Número inválido, por favor digite novamente: ");
    }while(jogador->nivel != 1 && jogador->nivel != 2 && jogador->nivel != 3);

    int cores = 0;

    //Adaptar parâmetros para criação dos vetores principais do jogo
    if(jogador->nivel == 1){
        cores = 4;
        jogador->tent = 10;
        jogador->cores = 4;
    }
    else if(jogador->nivel == 2){
        cores = 5;
        jogador->tent = 12;
        jogador->cores = 5;
    }
    else{
        cores = 6;
        jogador->tent = 15;
        jogador->cores = 6;
    }

    int *sequenciaCorreta = malloc(cores * sizeof(int)); //Vetor para sequencia gerada
    jogador->sequenciaCorretaCores = malloc(cores * sizeof(*jogador->sequenciaCorretaCores)); //Vetor para a sequencia gerada em forma de cores
    int *sequenciaJogador = malloc(cores * sizeof(int));//Vetor com a sequencia digitada pelo jogador

    jogador->sequenciaCorreta = (int *) malloc(cores * sizeof(int));//Criar um vetor dinamico na struct para a sequencia correta

    //Criar o historico direto na struct, ja com o tamanho maximo de tentativas do nivel escolhido
    jogador->historicoTentativas = malloc(jogador->tent * sizeof(int *));
    for(int g = 0; g < jogador->tent; g++){
        jogador->historicoTentativas[g] = malloc(cores * sizeof(int));
    }
    jogador->tentJogadas = 0; //Reseta contador de tentativas jogadas para o novo jogo

    //Geração da sequencia aleatoria de cores
    for (i = 0; i < cores; i++) {
        sequenciaCorreta[i] = (rand() % 6) + 1; 
        jogador->sequenciaCorreta[i] = sequenciaCorreta[i];
    }
    //Tranformo a sequencia numerica em palavras
    for(i = 0; i < cores; i++){ 
        if(sequenciaCorreta[i] == 1) strcpy(jogador->sequenciaCorretaCores[i], "Vermelho");
        else if(sequenciaCorreta[i] == 2) strcpy(jogador->sequenciaCorretaCores[i], "Azul");
        else if(sequenciaCorreta[i] == 3) strcpy(jogador->sequenciaCorretaCores[i], "Verde");
        else if(sequenciaCorreta[i] == 4) strcpy(jogador->sequenciaCorretaCores[i], "Amarelo");
        else if(sequenciaCorreta[i] == 5) strcpy(jogador->sequenciaCorretaCores[i], "Roxo");
        else strcpy(jogador->sequenciaCorretaCores[i], "Laranja");
    }

    //Após criaçao dos dados do jogador, chamada da funçao jogo
    jogo(jogoEmAndamento, jogador, sequenciaCorreta, sequenciaJogador, cores, 0);

    //Liberaçao de todas as alocações
    free(sequenciaCorreta);
    free(sequenciaJogador);

    return;
}

void carregarJogo(bool *jogoEmAndamento, Jogador *jogador){

    char nomeArq[105];
    char extensao[5] = ".cor";

    //Entrada do nome do arquivo salvo anteriormente
    printf("\nInforme o nome do arquivo: ");
    scanf("%95s", nomeArq);
    strcat(nomeArq, extensao);

    FILE *arquivo = fopen(nomeArq, "r");//Abro o arquivo para a leitura de seus dados
        if(arquivo == NULL){//Se o arquivo não existir, retorno uma mensagem de erro para o jogador
            printf("\n"RED("ERRO:")" O arquivo não existe.\n");
            return;
        }
        else{//Se existir, pego todos os dados e modifico na struct atual do jogador
            
            liberarMemoriaJogador(jogador); //Limpa estruturas antigas para evitar vazamento antes de preencher

            fgets(jogador->nome, 51, arquivo);//Primeiro pego o nome do jogador
            jogador->nome[strcspn(jogador->nome, "\r\n")] = '\0';//Com essa função eu calculo até a string chegar no \n e não leio ele

            char letraNivel;//Variavel para armazenar o nivel salvo do jogador
            fscanf(arquivo, " %c", &letraNivel);//Uso do fscanf para ler letra e armazenar na atual variavel

            //Ler todos os dados anotados do jogador para atualizar o atual jogador
            int cores;
            if(letraNivel == 'F'){
                jogador->nivel = 1;
                jogador->tent = 10;
                cores = 4;
                jogador->cores = 4;
            } 
            else if(letraNivel == 'M'){
                jogador->nivel = 2;
                jogador->tent = 12;
                jogador->cores = 5;
                cores = 5;
            }
            else{
                jogador->nivel = 3;
                jogador->tent = 15;
                jogador->cores = 6;
                cores = 6;
            }

            //Ler a sequencia correta da partida salva pelo jogador
            jogador->sequenciaCorreta = malloc(cores * sizeof(int));
            for(int i = 0; i < cores; i++){
                fscanf(arquivo, "%d", &jogador->sequenciaCorreta[i]);
            }

            //Ler a sequencia correta em palavras da partida salva pelo jogador na mesma lógica de criação
            jogador->sequenciaCorretaCores = malloc(cores * sizeof(*jogador->sequenciaCorretaCores));
            for(int i = 0; i < cores; i++){
                if(jogador->sequenciaCorreta[i] == 1) 
                    strcpy(jogador->sequenciaCorretaCores[i], "Vermelho");
                else if(jogador->sequenciaCorreta[i] == 2) 
                    strcpy(jogador->sequenciaCorretaCores[i], "Azul");
                else if(jogador->sequenciaCorreta[i] == 3) 
                    strcpy(jogador->sequenciaCorretaCores[i], "Verde");
                else if(jogador->sequenciaCorreta[i] == 4) 
                    strcpy(jogador->sequenciaCorretaCores[i], "Amarelo");
                else if(jogador->sequenciaCorreta[i] == 5) 
                    strcpy(jogador->sequenciaCorretaCores[i], "Roxo");
                else 
                    strcpy(jogador->sequenciaCorretaCores[i], "Laranja");
            }

            //Ler o número de tentativas jogadas pelo jogador na partida salva
            fscanf(arquivo, "%d", &jogador->tentJogadas);

            //Ler o histórico de tentativas jogadas na partida do jogador
            //Crio a matriz ja com o tamanho maximo (jogador->tent), nao so o que ja foi jogado,
            //pois o jogador pode continuar jogando alem do que ja tinha feito antes de salvar
            jogador->historicoTentativas = malloc(jogador->tent * sizeof(int *));//Criando um vetor com a quantidade maxima de tentativas, simulando as linhas da matriz
            for(int i = 0; i < jogador->tent; i++){
                jogador->historicoTentativas[i] = malloc(cores * sizeof(int));//Criando um vetor dentro do vetor criado para a quant maxima de tentativas, visando o parametro de quant de cores como colunas da matriz
            }
            //Preenche apenas as linhas referentes as tentativas ja jogadas, lidas do arquivo
            for(int i = 0; i < jogador->tentJogadas; i++){
                for(int j = 0; j < cores; j++){
                    fscanf(arquivo, "%d", &jogador->historicoTentativas[i][j]);
                }
            }

            //Apos pegar todos os dados, fecho o arquivo e carrego a funçao principal do jogo
            fclose(arquivo);
            *jogoEmAndamento = true;
            printf("\n            Carregando seu jogo...                \n");

            //Crio o vetor temporario que a funcao jogo() precisa para receber o chute do jogador a cada rodada
            int *sequenciaJogador = malloc(cores * sizeof(int));

            jogo(jogoEmAndamento, jogador, jogador->sequenciaCorreta, sequenciaJogador, cores, jogador->tentJogadas);

            //Libero a alocação temporaria de suporte 
            free(sequenciaJogador);
        }
}

void jogo(bool *jogoEmAndamento, Jogador *jogador, int *sequenciaCorreta, int *sequenciaJogador, int cores, int tentativaInicial){
    
    char sair;
    int i, j;
    bool jogadorGanhou = false;//Começo com a variavel falsa 

    printf("\n                                  Cores disponíveis                         \n");
    printf("\n                                CODIGO           COR                        \n");
    printf(RED("\n                                  1            Vermelho                     \n"));
    printf(BLUE("\n                                  2             Azul                        \n"));
    printf(GREEN("\n                                  3             Verde                       \n"));
    printf(YELLOW("\n                                  4            Amarelo                      \n"));
    printf(MAGENTA("\n                                  5             Roxo                        \n"));
    printf(ORANGE("\n                                  6            Laranja                      \n"));

    // Começo das tentativas
    for(i = tentativaInicial; i < jogador->tent; i++){ 
        printf("\n                    Tentativa %d de %d (Digite 0 para voltar ao menu)\n", i + 1, jogador->tent);
        printf("\n Digite %d cores usando os códigos de 1 a 6: ", cores);

        int primeiraCor;//Variavel para conseguir ler a primeira cor e já sair se for = 0
        scanf("%d", &primeiraCor); 

        bool pularRodada = false;//Variavel para saber se vai continuar ou nao na rodada

        if (primeiraCor == 0) {
            char decisao;
            printf(RED("Você realmente deseja sair? (S OU N): ")); //Confirmaçao se o jogador quer sair mesmo
            do {
                scanf(" %c", &decisao);
                if(decisao == 'S' || decisao == 's'){

                    jogador->tentJogadas = i;//Armazenar as tentativas ja concluidas ate aqui (a atual ainda nao foi jogada)
                    *jogoEmAndamento = true;
                    //O historico ja esta armazenado direto em jogador->historicoTentativas a cada rodada,
                    //entao aqui so precisamos sair da funçao, sem duplicar a matriz de novo
                    return;
                }
                else if(decisao == 'N' || decisao == 'n'){ 
                        i--; //Volta a tentativa normalmente
                        pularRodada = true;//Se realmente quiser continuar, armazena true
                }else
                    printf("\n"RED("ERRO:")" Opção inválida. Digite S ou N: ");//Somente as letras N e S sao permitidas para continuar
            } while(decisao != 'n' && decisao != 'N' && decisao != 's' && decisao != 'S'); 
        } 
        else { 
            bool valido; 
            do {
                valido = true;
                sequenciaJogador[0] = primeiraCor;

                // Lê o restante das cores da tentativa atual
                for(j = 1; j < cores; j++){
                    scanf("%d", &sequenciaJogador[j]);
                }

                // Bloco para verificação se todos os números estão dentro da tabela
                for (int k = 0; k < cores; k++) {
                    if(sequenciaJogador[k] < 1 || sequenciaJogador[k] > 6) {
                        valido = false;
                        printf("\n"RED("ERRO:")" Os números digitados não estão na faixa de 1 a 6.\n"); 
                        printf("Por favor, digite TODAS as %d cores novamente: ", cores);
                        
                        // Reseta a entrada lendo o primeiro número e forçando o loop a refazer o ciclo completo
                        scanf("%d", &primeiraCor); 
                        break; 
                    }  
                }
            } while(!valido); 
        }

        if (pularRodada) 
            continue;//Assim, se a variavel for verdadeira continua o resto do for

        // C = Correto (1); E = Existe, lugar errado (2); X = Nao existe (3);
        int *resultadoNum = malloc(cores * sizeof(int)); 
        int *corretaUsada = calloc(cores, sizeof(int)); 
        int *jogadorUsado = calloc(cores, sizeof(int)); 

        for(int x = 0; x < cores; x++){
            if(sequenciaJogador[x] == sequenciaCorreta[x]){
                resultadoNum[x] = 1;// Equivale a 'C'
                corretaUsada[x] = 1;// Bloqueia essa cor da senha
                jogadorUsado[x] = 1;// Bloqueia essa cor do chute do jogador
            } else {
                resultadoNum[x] = 3;// Deixa como 'X' por padrão
            }
        }

        for(int x = 0; x < cores; x++){
            if(jogadorUsado[x] == 1) 
                continue; 

            for(int s = 0; s < cores; s++){ 
                // Se a cor da senha não foi usada E bate com o chute atual
                if(corretaUsada[s] == 0 && sequenciaJogador[x] == sequenciaCorreta[s]){
                    resultadoNum[x] = 2; //Equivale a E
                    corretaUsada[s] = 1; // Bloqueia essa cor da senha para não repetir feedback
                    break;                 
                }
            }
        }

        free(jogadorUsado);

        // Bloco para ordenar o vetor resultadoNum em ordem crescente para não mostrar a posiçao correta do resultado
        for (int x = 0; x < cores - 1; x++) {
            for (int p = 0; p < cores - 1 - x; p++) {
                if (resultadoNum[p] > resultadoNum[p + 1]) {
                    int aux = resultadoNum[p];
                    resultadoNum[p] = resultadoNum[p + 1];
                    resultadoNum[p + 1] = aux;
                }
            }
        }

        // Bloco para guardar o resultado ordenado direto no historico do jogador (1=C, 2=E, 3=X)
        for(int p = 0; p < cores; p++){
            jogador->historicoTentativas[i][p] = resultadoNum[p];
        }
        jogador->tentJogadas = i + 1; //Atualiza dinamicamente as rodadas que ja foram efetuadas

        bool vitoria = true; //Variavel para detectar a vitoria definitiva do jogador na rodada
        for(int k = 0; k < cores; k++){
            if(jogador->historicoTentativas[i][k] != 1){//Confirmaçao que todos os valores da rodada sao 'C' (1)
                vitoria = false;
                break;
            }
        }

        //Bloco para oferecer um feedback da rodada para o jogador continuar
        printf(BOLD("\n Feedback desta rodada: "));
        for(int m = 0; m < cores; m++){
            int v = jogador->historicoTentativas[i][m];
            char letra;//Variavel para trocar os numeros por letras na hora da impressao
                if(v == 1) 
                    letra = 'C';
                else if(v == 2) 
                    letra = 'E';
                else
                    letra = 'X';   

            if(letra =='C')
                printf(GREEN("[%c] "), letra);
            else if(letra == 'E')
                printf(YELLOW("[%c] "), letra);
            else 
                printf(RED("[%c] "), letra);
        }
        printf("\n");

        free(resultadoNum);
        free(corretaUsada);

        //Bloco par verificar se o jogador ganhou em meio as tentativas
        if(vitoria == true){
            jogadorGanhou = true;
            jogador->tentAcerto = i + 1;
            printf(BOLD("\n           Parabéns %s!\n Você acertou a sequêcia. \n"), jogador->nome);
            printf("\n                    Histórico de rodadas:                      \n");
            for(int k = tentativaInicial; k <= i; k++){ 
                printf("Rodada %d:", k + 1);
                for(int m = 0; m < cores; m++){
                    int v = jogador->historicoTentativas[k][m];
                    char letra = (v == 1) ? 'C' : (v == 2) ? 'E' : 'X';
                    if(letra == 'C')
                        printf(GREEN(" %c"), letra);
                    else if(letra == 'E')
                        printf(YELLOW(" %c"), letra);
                    else
                        printf(RED(" %c"), letra);
                }
                printf("\n");
            }

            *jogoEmAndamento = false; //Partida encerrada com vitoria
            atualizarRanking(jogador);//Chamar a função para atualizar e mostrar o ranking

            printf("                  Pressione 'M' para voltar ao menu principal!                 \n");
            do {
                scanf(" %c", &sair);
            } while(sair != 'M' && sair != 'm');
            break;
        }
    } 

    //Bloco para a derrota do jogador no fim das tentativas
    if(!jogadorGanhou){
        printf("\n                                  Você "RED("perdeu")" :(                                   \n");
        printf("\n                         O número de tentativas foi esgotado.                    \n");
        printf("\n                     A sequência correta era:");
        for(i = 0; i < cores; i++){
            if(strcmp(jogador->sequenciaCorretaCores[i],"Vermelho") == 0){
                printf(RED(" [%d]"), jogador->sequenciaCorreta[i]);
                printf(RED(" %s"), jogador->sequenciaCorretaCores[i]);
            }else if(strcmp(jogador->sequenciaCorretaCores[i],"Azul") == 0){
                printf(BLUE(" [%d]"), jogador->sequenciaCorreta[i]);
                printf(BLUE(" %s"), jogador->sequenciaCorretaCores[i]);
            }else if(strcmp(jogador->sequenciaCorretaCores[i],"Amarelo") == 0){
                printf(YELLOW(" [%d]"), jogador->sequenciaCorreta[i]);
                printf(YELLOW(" %s"), jogador->sequenciaCorretaCores[i]);
            }else if(strcmp(jogador->sequenciaCorretaCores[i],"Verde") == 0){
                printf(GREEN(" [%d]"), jogador->sequenciaCorreta[i]);
                printf(GREEN(" %s"), jogador->sequenciaCorretaCores[i]);
            }else if(strcmp(jogador->sequenciaCorretaCores[i],"Roxo") == 0){
                printf(MAGENTA(" [%d]"), jogador->sequenciaCorreta[i]);
                printf(MAGENTA(" %s"), jogador->sequenciaCorretaCores[i]);
            }else if (strcmp(jogador->sequenciaCorretaCores[i],"Laranja") == 0){
                printf(ORANGE(" [%d]"), jogador->sequenciaCorreta[i]);                
                printf(ORANGE(" %s"), jogador->sequenciaCorretaCores[i]);
            }
        }
        printf("\n");
        *jogoEmAndamento = false;

        printf("\n                      Pressione 'M' para voltar ao menu principal!                \n");
        do {
            scanf(" %c", &sair);
            if(sair == 'm' || sair == 'M')
                return;
        } while(sair != 'M' && sair != 'm');
    }
}

void salvarJogo(bool *jogoEmAndamento, Jogador *jogador){
    
    char sair;

    if(*jogoEmAndamento){

        char nomeArq[105];
        char extensao[5] = ".cor";//Extensao pré-definida para quaisquer arquivos
        printf("\n Informe o nome do arquivo que quer salvar: ");
        scanf("%95s", nomeArq);//Ler so ate 99 para que nao cause nenhum erro futuro no codigo

        strcat(nomeArq, extensao);//Coloca a extensao .cor ao fim do nome do arquivo

        FILE *arquivo = fopen(nomeArq, "w");
            if(arquivo == NULL){
                printf("\n"RED("ERRO:")" Não foi possível criar o arquivo.\n");
            return;
            }
        
        char letraNivel;//Tranformar o nivel armazenado por numero em letras equivalentes ao nivel
        if(jogador->nivel == 1)
            letraNivel = 'F';
        else if(jogador->nivel == 2)
            letraNivel = 'M';
        else
            letraNivel = 'D';
        
        fprintf(arquivo, "%s\n", jogador->nome);//Armazeno o nome do jogador
        fprintf(arquivo, "%c\n", letraNivel);//Armazeno o nivel do jogo
        
        for(int i = 0; i < jogador->cores; i++){//Armazeno a sequencia correta do jogo
            fprintf(arquivo, "%d", jogador->sequenciaCorreta[i]);
        }
        fprintf(arquivo, "\n");

        fprintf(arquivo, "%d\n", jogador->tentJogadas);//Armazeno as tentativas já usadas pelo jogador

        for(int i = 0; i < jogador->tentJogadas; i++){//Armazeno o historico de tentativas do jogador
            for(int j = 0; j < jogador->cores; j++){
                fprintf(arquivo, "%d ", jogador->historicoTentativas[i][j]);
            }
            fprintf(arquivo, "\n");
        }

        fclose(arquivo);//Fecho o arquivo apos salvar tudo
        printf("\n         Jogo salvo com sucesso em '%s'!         \n", nomeArq);

        *jogoEmAndamento = false;//Como o jogo já foi salvo, o jogo nao esta em andamento

    }
    else{
        printf("\n"RED("ERRO:")" Não há nenhum jogo em andamento para ser salvo.\n");
        return; //Mensagem caso nao há nenhum jogo para salvar
    }

    printf("                  Pressione 'M' para voltar ao menu principal!                 \n");
            do {
                scanf(" %c", &sair);
            } while(sair != 'M' && sair != 'm');
}

void atualizarRanking(Jogador *jogadorAtual){

    Ranking lista[11];//Criação de uma lista de jogadores com a struct correta de tamanho fixo
    Ranking aux;
    int i, j, quant;
    quant = 0;

    FILE *arquivo = fopen("ranking.rnk", "rb"); //Abrir o arquivo ranking

        if (arquivo != NULL) {
            quant = fread(lista, sizeof(Ranking), 10, arquivo); //Lendo os n primeiros jogadores da lista no arquivo
            fclose(arquivo);
        }

        //Mapeia struct jogadorAtual para a struct de gravação Ranking regulamentada no PDF
        strcpy(lista[quant].nome, jogadorAtual->nome);
        lista[quant].nivel = jogadorAtual->nivel;
        lista[quant].tentativas = jogadorAtual->tentAcerto;
        quant++;

        //Começando a ordenar a lista do ranking
        for(i = 0; i < quant - 1; i++){
            for(j = 0; j < quant - i - 1; j++){

                // Criterio 1: Menor número de tentativas para o maior (conforme pág 5)
                if(lista[j].tentativas > lista[j+1].tentativas){
                    aux = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = aux;
                }
                // Criterio 2: Desempate por nível do mais difícil para o fácil (D=3, M=2, F=1)
                else if(lista[j].tentativas == lista[j+1].tentativas && lista[j].nivel < lista[j+1].nivel){
                    aux = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = aux;
                }
            }
        }

        if(quant > 10)//Se estrapolar o tanto de posições, reoorganizar para no máximo 10
            quant = 10;

        int posicao = 0;//Variavel para armazenar a posicao do jogador
        for(i = 0; i < quant; i++){//Descobrir a posicao que ele esta com base nos seus dados
            if(strcmp(lista[i].nome, jogadorAtual->nome) == 0 && 
               lista[i].nivel == jogadorAtual->nivel &&
               lista[i].tentativas == jogadorAtual->tentAcerto){

               posicao = i + 1; //Como o vetor começa em 0, importante armazenar somado com 1
               break;//O break serve para que se já for encontrado, saia do loop do for
            }
        }

        if(posicao != 0){//Se o jogador alcançar qualquer posicao a nao ser 0 ira imprimir o parabens
            printf("\n                  Você consquistou a posição %d do ranking.                 \n", posicao);
        }else{//Se não a mensagem será essa
            printf("\n             Que pena! Você não conseguiu atingir o mínimo do ranking.          \n");
        }

        FILE *arquivoEscrita = fopen("ranking.rnk", "wb");//Abrindo o arquivo para escrever a lista atualizada
            if (arquivoEscrita != NULL){//Se o arquivo estiver vazio por algum motivo, apresenta falha
                fwrite(lista, sizeof(Ranking), quant, arquivoEscrita);
                fclose(arquivoEscrita);
            }else{
                printf("\n"RED("ERRO:")" Não foi possível salvar o ranking.\n");
            }

        //Imprimir o ranking da mesma forma da funçao comum de abrir o ranking, mas agora, atualizado
        printf(
            "\n"
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            "-RANKING-"
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")
            "\n"
        );
            printf("\n");
                for(i = 0; i < quant; i++){
                    printf("\n %dº- %s no nível %d com %d tentativa(s). \n", i + 1, lista[i].nome, lista[i].nivel, lista[i].tentativas);
                }
        printf(
            "\n"
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
            RED("=")
            "\n"
        );
}

void abrirRanking(){
    
    Ranking lista[11]; //Ajustado para ler a struct Ranking limpa
    int i;
    int quant = 0;
    char sair;

    FILE *arquivo = fopen("ranking.rnk", "rb"); //Abrir o arquivo ranking

        if (arquivo != NULL) {
            quant = fread(lista, sizeof(Ranking), 10, arquivo); //Lendo os n primeiros jogadores da lista no arquivo
            fclose(arquivo);
        }

    //Imprime o ranking guardado no arquivo
    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        "-RANKING-"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")
        "\n"
    );
    printf("\n");
        for(i = 0; i < quant; i++){
            printf("\n %dº- %s no nível %d com %d tentativa(s). \n", i + 1, lista[i].nome, lista[i].nivel, lista[i].tentativas);
        }
    printf(
        "\n"
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")YELLOW("~")BLUE("=")GREEN("~")MAGENTA("=")ORANGE("~")
        RED("=")
        "\n"
    );

    //Saída da função exclusiva para ver o ranking
    printf("                             Pressione 'M' para voltar ao menu.           \n");
        do {
            scanf(" %c", &sair);
        } while(sair != 'M' && sair != 'm');
}