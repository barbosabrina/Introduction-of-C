#include <stdio.h>

	int main(){
	
	int p;
	float terra, peso;
	
	printf("Digite o peso da terra e o codigo interno se seu outro planeta: ");
	scanf("%f %d", &terra, &p);
	
	switch(p){
	
	case 101: 
		peso = terra * (3.7/9.80);
		break;
	case 102: 
		peso = terra * (8.87/9.80);
		break;
	case 103: 
		peso = terra * (9.80/9.80);
		break;
	case 104: 
		peso = terra * (3.711/9.80);
		break;
	case 105: 
		peso = terra * (24.79/9.80);
		break;
	case 106: 
		peso = terra * (10.44/9.80);
		break;
	case 107: 
		peso = terra * (8.69/9.80);
		break;
	case 108: 
		peso = terra * (11.15/9.80);
		break;
	case 201: 
		peso = terra * (0.62/9.80);
		break;
	case 202: 
		peso = terra * (0.00016/9.80);
		break;
	case 203: 
		peso = terra * (0.27/9.80);
		break;
	case 204: 
		peso = terra * (0.0007/9.80);
		break;
	case 205: 
		peso = terra * (0.00017/9.80);
		break;
	default:
		printf("ERRO: planeta inválido.\n");
	}
		
	printf("O planeta escolhido tem peso de %.2f \n", peso);
	
	return 0;
}
		
