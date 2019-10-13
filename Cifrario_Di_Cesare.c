#include <stdio.h>
#include <ctype.h>

int main( void ) {
  char c;
  int k, backup;

  printf("inserire la chiave di cifratura sotto forma di un numero intero: ");
  scanf("%d",&k);
  backup=k;  //tengo k in un ulteriore variabile così da poter riasseganre il valore di k che decrementa

  while ( ( c = getchar() ) != '.' ) {
    if ( !isalpha( c ) ){
      putchar( c );
      continue;
    } else {
      for(; k!=0 ; k--){
        if(c=='z'){
          c='a'; //come se avessi incrementato di 1
          continue;
        }else if(c=='Z'){
          c='A';//come se avessi incrementato di 1
          continue;
        }
        c++;
      }
      putchar( c );
      k=backup;
    }
  }

  printf ( "\n" );
  return 0;
}
