#include <stdio.h>

	int main(){
	
	float n1,n2, media;
	n1 = 0;
	n2 = 0;
	
	while( n1 >= 0 && n2 >= 0){
		
		printf("Digite as notas do aluno: ");
		scanf("%f %f", &n1, &n2);
		
		if( n1 >= 0 && n2 >= 0){
		media = n1 + n2/2;
		printf("A média do aluno: %.1f\n", media);
		}	
	}	
	return 0;
}
