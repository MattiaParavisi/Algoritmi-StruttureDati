#include <stdio.h>
#include <ctype.h>

int main( void ) {
  char c;

  while ( ( c = getchar() ) != '.' ) {
    if ( isalpha( c ) )
      putchar( toupper( c ) );
    else
      putchar( c );
  }

  printf ( "\n" );
  return 0;
}
