#include <stdio.h>

int main(void){
	int ore, minuti, scelta;
	char lettera1, lettera2; 
	printf("inserisci 1 per convertire da hh:mm a AM/PM e 2 per convertire da AM/PM a hh:mm \n scelta: ");
	scanf("%d",&scelta);
	switch(scelta){
		
		case 1:
		printf("inserisci un orario nel formato: hh:mm ");
		scanf("%d:%d", &ore, &minuti);
		if(ore==24){
			printf("le ore espresse in AM/PM sono: 12:%d AM \n",minuti);
			return 0;	
		}else if(ore==12){
			printf("le ore espresse in AM/PM sono: 12:%d PM \n",minuti);
			return 0;
		}
		if(ore>12){
			ore= ore-12;
			printf("le ore espresse in AM/PM sono: %d:%d PM \n",ore, minuti);
		}else {
			printf("le ore espresse in AM/PM sono: %d:%d AM \n",ore, minuti);
		}
		break;

		case 2:
		printf("inserisci un orario nel formato: hh:mm AM/PM ");
		scanf("%d:%d %c%c", &ore, &minuti, &lettera1, &lettera2);
		if(ore==12 && lettera1=='A' && lettera2=='M'){
			printf("le ore espresse in AM/PM sono: 24:%d \n",minuti);
			return 0;	
		}else if(ore==12 && lettera1=='P' && lettera2=='M'){
			printf("le ore espresse in AM/PM sono: 12:%d \n",minuti);
			return 0;
		}
		if(lettera1=='P' && lettera2=='M'){
			ore= ore+12;
			printf("le ore espresse in AM/PM sono: %d:%d \n",ore, minuti);
		}else {
			printf("le ore espresse in AM/PM sono: %d:%d \n",ore, minuti);
		}
		break;
	}
}
