#include <stdio.h>

int main( void ) {
  int n, x = 0, i=0;
  printf( "Inserisci una serie di numeri: " );

  do {
    scanf( "%d", &n );
      if(n==0)
        break;
      else
        x = x + n;
        i++;
  } while ( i != 10 );

  printf( "%d\n", x );
  return 0;

}
