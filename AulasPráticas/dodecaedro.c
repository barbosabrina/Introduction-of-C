#include <stdio.h>
#include <math.h>

	float calculaArea (float l){
	
		float op;
		op = (3 * pow(l,2))* sqrt(25 + 10 * sqrt(5));
		return op;
	}
	
	int main(){
	
		int lado; float area;
	
		printf("Digite o lado do dodecaedro regular: ");
		scanf("%d", &lado);
	
		area = calculaArea(lado);
		printf("A area e: %.2f \n", area);
	
		return 0;
	}
	

	
	
