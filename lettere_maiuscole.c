#include <stdio.h>
#include <ctype.h>

int main(void){
  char lettera1, lettera2;
  int differenza;
  printf("inserisci la prima lettera: \n");
  scanf("%c %c", &lettera1, &lettera2);
  if(isalpha(lettera1)!=0 && isalpha(lettera2)!=0 ){
    lettera1=toupper(lettera1);
    lettera2=toupper(lettera2);
    if (lettera1>lettera2){
      printf("la lettera: %c sta dopo di %c\n", lettera1, lettera2);
      differenza= lettera1-lettera2;
      printf("la loro differenza è; %d\n", differenza );
    }else {
      printf("la lettera: %c sta prima di %c\n", lettera1, lettera2);
      differenza= lettera2-lettera1;
      printf("la loro differenza è: %d\n", differenza );
    }
  }else{
    printf("errore \n");
  }

}
