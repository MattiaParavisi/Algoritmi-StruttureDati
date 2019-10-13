#include<stdio.h>

int main(void){

  int giorno, mese, stampagiorno, i, tabeseguiti;
  stampagiorno=1;
  tabeseguiti=0;
  printf("inserisci il numero del mese (1=gennaio,....,12=dicembre):");
  scanf("%d", &mese );
  printf("inserisci il giorno in cui comincia il mese (1=lunedì, 2=martedì... 7=domenica):");
  scanf("%d", &giorno );
  printf("L\tM\tM\tG\tV\tS\tD \n");
  for(i=0; i<giorno-1 ; i++ ){
    printf("\t");
    tabeseguiti++;
  }
  printf("%d", stampagiorno ); //stampagiorno=1
  if(mese==1||mese==3||mese==5||mese==7||mese==8||mese==10||mese==12){
    mese=1;
  }else if(mese==4||mese==6||mese==9||mese==11){
    mese=2;
  }else{
    mese=3;
  }

  switch(mese){
    case 1:
    printf("\t");
    tabeseguiti++;
      for(i=0; i<30; i++){
        stampagiorno++; //stampagiorno = 2
        printf("%d", stampagiorno );
        printf("\t");
        tabeseguiti++;
        if(tabeseguiti==7){
          printf("\n");
          tabeseguiti=0;
        }
      }
      break;

      case 2:
      printf("\t");
      tabeseguiti++;
        for(i=0; i<29; i++){
          stampagiorno++; //stampagiorno = 2
          printf("%d", stampagiorno );
          printf("\t");
          tabeseguiti++;
          if(tabeseguiti==7){
            printf("\n");
            tabeseguiti=0;
          }
        }
        break;

        case 3:
        printf("\t");
        tabeseguiti++;
          for(i=0; i<27; i++){
            stampagiorno++; //stampagiorno = 2
            printf("%d", stampagiorno );
            printf("\t");
            tabeseguiti++;
            if(tabeseguiti==7){
              printf("\n");
              tabeseguiti=0;
            }
          }
          break;
  }
  printf("\n");
}
