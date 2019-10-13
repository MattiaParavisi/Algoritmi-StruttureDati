#include <stdio.h>

#define FATTORE_SCALA (5.0f / 9.0f)
#define ZERO 32.0f

int main ( void ){
  float fahr;
  printf ( " Inserisci la temperatura in gradi Fahrenheit : " );
  scanf ( "%f" , & fahr );
  fahr = ( fahr - ZERO ) * FATTORE_SCALA ;
  printf ( " Gradi Celisus equivalenti : %.1f \n" , fahr );
return 0;
}
