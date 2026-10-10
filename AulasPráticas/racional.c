#include <stdio.h>

struct Racional {
    int numerador;
    int denominador;
};

int mdc(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct Racional simplificar(struct Racional r) {
    int divisor = mdc(r.numerador, r.denominador);
    r.numerador /= divisor;
    r.denominador /= divisor;
   
   	if (r.denominador < 0) {
       	 	r.numerador = -r.numerador;
        	r.denominador = -r.denominador;
    	}
    return r;
}

int equal(struct Racional r1, struct Racional r2) {
    r1 = simplificar(r1);
    r2 = simplificar(r2);
    return (r1.numerador == r2.numerador && r1.denominador == r2.denominador);
}

int main() {
    
    struct Racional r1, r2;

   	printf("Digite numerador e denominador de r1: ");
   	scanf("%d %d", &r1.numerador, &r1.denominador);

    	printf("Digite numerador e denominador de r2: ");
    	scanf("%d %d", &r2.numerador, &r2.denominador);

    	if (equal(r1, r2)) {
        	struct Racional simplificado = simplificar(r1);
        	printf("r1 e r2 são iguais a (%d / %d)!\n",
               	simplificado.numerador, simplificado.denominador);
    	} else {
        	printf("r1 e r2 são diferentes!\n");
    	}

    return 0;
}
