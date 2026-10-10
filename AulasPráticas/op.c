#include <stdio.h>
#include <math.h>

	int main(){
	
	float x1, x2, x3;
	double op, p2, p3, p4;
	
	printf("Entre com os valores de x1, x2 e x3: \n");
	scanf("%f %f %f", &x1, &x2, &x3);
	
	
	p2 = pow(x2,2);
	p3 = pow(x3,2);
	p4 = pow(x1*x2*x3,2);
	op = pow(x1 + p2 + p3,2) - p4;
	
	printf("y = %.2lf\n", op);
	
	return 0;
	
	}
