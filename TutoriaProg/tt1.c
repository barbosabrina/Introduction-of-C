#include <stdio.h>

typedef struct{
	int codigo;
	char nome[30];
	float preco;
}Produto;

void limpar_buffer() {
   int ch;
   while ((ch = getchar()) != '\n' && ch != EOF);
}

void salvar_produtos(int n, Produto *produtos);

int main(){

	int i, j, quant;
	Produto produtos[10];
	
	printf("Quantos produtos deseja cadastrar? ");
	scanf("%d", &quant);
	
	salvar_produtos(quant, produtos);
	printf("%d produtos salvos com sucesso em 'produtos.dat'!\n", quant);
	
	return 0;
}

void salvar_produtos(int quant, Produto *produtos){
	
	int i;
	FILE *arquivo;
	
	for(i = 0; i < quant; i++){
		int k = i + 1;
		printf("Produto %d:\n", k);
		printf("Código: ");
		scanf("%d", &produtos[i].codigo);
		printf("Nome: ");
		limpar_buffer();
		scanf("%s", produtos[i].nome);
		printf("Preco: ");
		scanf("%f", &produtos[i].preco);
	}
	
	arquivo = fopen("produtos.dat", "wb");
	fwrite(produtos, sizeof(Produto), quant, arquivo);
	fclose(arquivo);
}
	
