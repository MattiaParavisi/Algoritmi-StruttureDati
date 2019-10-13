#include <stdio.h>

int main(void){
  int numero, count=1, flag=0;
  printf("inserisci un numero: \n");
  scanf("%d",&numero);
  for(count; count<numero; count++){
    if(numero%count==0 && count!=numero && count!=1){
      printf("il numero non è primo\n");
      flag=1;
      break;
    }
  }
  if(flag==0){
    printf("il numero è primo\n");
  }
}
