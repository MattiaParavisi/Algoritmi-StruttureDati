#include <stdio.h>
#include <ctype.h>

int main(void){

  int c, f[10] = {0}, i;
  c = getchar();

  while ( c != '.' ) {
    if ( isdigit( c ) )
      printf("%c ", c );
    c = getchar();
  }

}
