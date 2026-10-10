#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int main(){

	int i, j;
	char c;
	char cons[11];
	char vog[11];
	
	int quantV, quantC;
	quantV = 0;
	quantC = 0;
	
	for(i = 1; i <= 10; i ++){
		printf("Digite o %d caractere: ", i);
		scanf("%c", &c);
		limpar_buffer();
		
		if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			vog[quantV] = c ;
			quantV ++; }
		else {
			cons[quantC] = c;
			quantC ++; }
	}
	
	//vog[quantV] = '\0';
	//cons[quantC] = '\0';
	
	printf("\n");
	
	printf("%d vogais: ", quantV);
	
    		for (i = 0; i < quantV; i++) {
        	printf("%c ", vog[i]);
    		}
    		
    	printf("\n");
	
	printf("%d consoantes: ", quantC);
	
   	 	for (i = 0; i < quantC; i++) {
        	printf("%c ", cons[i]);
    		}
    		
    	printf("\n");    
	
	return 0;
	
}
