#include <stdio.h>

int main( void ) {
  int n, x = 0;
  float i;
  printf( "Inserisci una serie di numeri: " );

  do {
    scanf( "%d", &n );
      if(n==0)
        break;
    x = x + n;
    i++;
  } while ( n != 0 );

  printf( "la media è: %.1f\n", x/i );
  return 0;

}
