#include <stdio.h>

int main(void){
  int numero, nummezzi;
  printf("inserisci un numero: \n");
  scanf("%d",&numero);
  nummezzi=numero/2;
  printf("i divisori sono: \n");
  printf("%d\n", numero);
  for(nummezzi; nummezzi>0; nummezzi--){
    if(numero%nummezzi==0){
      printf("%d\n", nummezzi );
    }
  }
}
