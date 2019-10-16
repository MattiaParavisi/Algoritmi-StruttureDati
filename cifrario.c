#include <stdio.h>

int main(void){

  char c, frase[100]={};
  int i=0, k, j, l;

  while((c=getchar())!='.'){
    frase[i]=c;
    i++;
  }

  printf("inserisci la chiave di cifratura: ");
  scanf("%d", &k);

  for(j=0; j<i; j++){
    for(l=0; l<k; l++){
      if(frase[j]==' '){
        continue;
      }
      if(frase[j]=='z'){
        frase[j]='a';
        continue;
      }else if(frase[j]=='Z'){
        frase[j]='A';
        continue;
      }
      frase[j] += 1;
    }
  }

  for(i=0;i<j; i++){
    printf("%c", frase[i]);
  }

  printf("\n");

}
