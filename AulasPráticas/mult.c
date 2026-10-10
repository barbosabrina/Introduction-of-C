#include <stdio.h>

int main(){

	int m, n, p, q, i, j, k;
	
	printf("Entre com os valores de m, p, q, n: ");
	scanf("%d %d %d %d", &m, &p, &q, &n);
		
	if(m > 10 || n > 10 || p > 10 || q > 10 || p != q){
		printf("Valores inválidos! ");
		return 0;
	}
	
	int m1[10][10];
	int m2[10][10];
	int m3[10][10];
	
	printf("Entre com os elementos da matriz: ");
		for (i = 0; i < m; i++){
			for ( j = 0; j < p; j++){
			scanf("%d", &m1[i][j]);
		}
	}
	
	printf("Entre com os elementos da matriz: ");
		for (i = 0; i < q; i++){
			for ( j = 0; j < n; j++){
			scanf("%d", &m2[i][j]);
		}
	}
	
	for (i = 0; i < m; i++) {
        	for (j = 0; j < n; j++) {
        		m3[i][j] = 0;
            		for (k = 0; k < p ; k++) {
                	m3[i][j] += m1[i][k] * m2[k][j];
            		}
       		}
    	}
	
	for (i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%d ", m3[i][j]);
		}
	printf("\n");
	}
	
	return 0;
}

	
	
	
