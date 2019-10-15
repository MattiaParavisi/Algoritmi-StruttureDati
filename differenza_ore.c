#include<stdio.h>

int main(void){
	int ora, minuti, secondi;
	int ora1, minuti1, secondi1;
	int orafinale, minutifinale, secondifinale;
	
	printf("inserisci un orario nel formato hh:mm:ss : ");
	scanf("%d : %d : %d", &ora, &minuti, &secondi);
	
	printf("inserisci un orario nel formato hh:mm:ss : ");
	scanf("%d : %d : %d", &ora1, &minuti1, &secondi1);

	if(ora>ora1){
		orafinale= ora-ora1;
	}else{
		orafinale= ora1-ora;	
	}

	if(minuti>minuti1){
		minutifinale= minuti-minuti1;
	}else{
		minutifinale= minuti1-minuti;	
	}

	if(secondi>secondi1){
		secondifinale= secondi-secondi1;
	}else{
		secondifinale= secondi1-secondi;	
	}

	printf("la differenza tra i due orari è %d:%d:%d \n",orafinale, minutifinale, secondifinale);

	
	
}

