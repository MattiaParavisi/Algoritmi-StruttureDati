#include <stdio.h>

int main(void){
  int numero, ripetizioni[10]={}, cifra, i;
	scanf("%d", &numero);
	printf("numero letto: %d \n", numero);
	while(numero>0){
		cifra= numero%10;
		printf("cifra %d \n", cifra);
		ripetizioni[cifra]++;
 		numero /= 10;
	}
	printf("ripetizioni: ");
	for(i=0; i<10; i++){
		if(ripetizioni[i]>1){
			printf("%d", i);
		}
	}
	printf("\n");
	
}
