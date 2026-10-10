#include <stdio.h>

	int main(){
	
	int hora, min, seg, op;
	
	printf("Digite a hora, minutos e segundos: ");
	scanf("%d %d %d", &hora, &min, &seg);
	
	op = (hora * 60 * 60) + (min * 60) + seg;
	
	printf("Total = %d", op);
	
	return 0;
	
}
	
	
