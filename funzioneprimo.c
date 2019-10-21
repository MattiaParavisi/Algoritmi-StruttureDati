/*Scrivete una funzione con parametro un interonche stabilisca senè un numero primo.
Scrivete la funzionepartendo dal programma che avete scritto per l’esercizio 5 della scheda “L01-lab”.*/
#include <stdio.h>

int primo(int n){
  int i;
  for(i=2; i<(n/2); i++){
    if(n%i==0){
      return 0;
    }
  }
  return 1;
}

int main(void){
  int numero, res;
  scanf("%d", &numero );
  res = primo(numero);
  if(res==0){
    printf("non primo\n");
  }else{
    printf("primo\n");
  }
}
