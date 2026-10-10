#include <stdio.h> 
#include <math.h> 

	void calculaRaizes (float a, float b, float c, float *xa, float *xb, float *del);
	
	int main(){
	
	float a, b, c;
	float xa, xb, del;
	
	printf("Digite os valores de a, b, c: \n ");
	scanf("%f %f %f", &a, &b, &c);
	
	calculaRaizes(a, b, c, &xa, &xb, &del);
	
	if (del >= 0)
		printf("\n xa = %.2f \n xb = %.2f\n", xa, xb);
	else
		printf("Não foi possível calcular as raízes!\n");
	
	return 0;
}

	void calculaRaizes (float a, float b, float c, float *xa, float *xb, float *del){
	
	float delta = pow(b,2) - (4 * a * c);
	*xa = (-b + sqrt(delta)) / (2 * a);
	*xb = (-b - sqrt(delta)) / (2 * a);
	
	*del = delta;
	}
	
	
	
