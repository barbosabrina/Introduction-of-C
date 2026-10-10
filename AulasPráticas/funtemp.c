#include <stdio.h> 

	void converterCelsius(float celsius, float *fahrenheit, float *kelvin){
	
	*fahrenheit = (celsius * 9)/5 + 32;
	*kelvin = celsius + 273.15;
	
	}
	
	int main(){
	
	float c, f, k;
	
	printf("Digite o valor em Celsius: "); scanf("%f", &c);
	
	converterCelsius(c, &f, &k);
	
	printf("Fahrenheit: %.2f \n Kelvin: %.2f \n", f, k);
	
	return 0;	
}


