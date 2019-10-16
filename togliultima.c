#include <stdio.h>

int main(void){

  char frase[100]={}, c;
  int base, i=0;

  while((c=getchar())!= '\n'){
    frase[i]=c;
    i++;
  }

  frase[i++]='\n';

  for(i=0; i<100; i++){
    if(frase[i+1]==' '||frase[i+1]=='\n'){
      continue;
    }
    printf("%c", frase[i]);
  }
  printf("\n");

}
