#include <stdio.h>

int quadrado_por_soma(int n){ //Funçao que devolve o quadrado
	
	int i; // Variavel contador
	int resultado; //Variavel para acumular a soma
	int impar; // Variavel para organizar os numeros impares
	
	resultado = 0; // Soma começa zerada
	i = 0; //Contador começa zerado
	impar = 1; // O impar começa pelo primeiro impar
	
	while( i < n){ // Enquanto o contador estiver estritamente menor que o numero escolhido
		resultado += impar; // Somara um impar no resultado
		impar += 2; // O impar ira ser contado de 2 em 2 
		i++; //O contador irá passando
	}
	
	return resultado; // Retornar´a soma quando nao satisfazer mais o while
}

int main(){

	int n;
	
	//Entrada do numero escolhido
	printf("Digite um número: "); scanf("%d", &n);
	
	//Chamada da funcao
	int op = quadrado_por_soma(n);
	
	//Saida dos quadrados pegando o numero escolhido e o resultado oferecido pela funcao
	printf("O quadrado de %d é %d\n", n, op);
	
	return 0;
}


	
