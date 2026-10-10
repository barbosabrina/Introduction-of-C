#include <stdio.h>

	void converterDistancias(float metros, float *jar, float *pes, float *pol);
	
	int main(){
	
	float metros, jar, pes, pol;
	
	printf("Digite o valor em Metros: "); 
	scanf("%f", &metros);
	
	converterDistancias(metros, &jar, &pes, &pol);
	
	printf("\n Jardas: %.3f \n\n Pés: %.3f \n\n Polegadas: %.3f \n\n", jar, pes, pol);
	
	return 0;
}
	
	void converterDistancias(float metros, float *jar, float *pes, float *pol){
	
	*jar = metros * 1.094;
	*pes = metros * 3.281;
	*pol = metros * 39.3701;
	
	}
	
