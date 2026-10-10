#include <stdio.h>
#include <string.h>

void limpar_buffer() {
   int ch;
   while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(){
	char palavraToda[93];
	char p1[31];
	char p2[31];
	char p3[31];
	
	printf("Digite a 1 palavra: "); 
	scanf("%s", p1);
	limpar_buffer();
	
	printf("Digite a 2 palavra: ");
	scanf("%s", p2);
	limpar_buffer(); 
	
	printf("Digite a 3 palavra: ");
	scanf("%s", p3);
	limpar_buffer(); 
	
	strcat(palavraToda, p1);
	strcat(palavraToda, p2);
	strcat(palavraToda, p3);
	
	printf("%s \n", palavraToda);
	
	return 0;
}	
	
