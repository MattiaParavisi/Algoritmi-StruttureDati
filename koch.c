#include <stdio.h>
#include "libpsgraph.h"

void koch(int lunghezza, int grado){
  if(grado==0){
    draw(lunghezza);
    return;
  }
  koch( lunghezza/3 , grado-1 );
  turn(-45);
  koch( lunghezza/3 , grado-1 );
  turn(90);
  koch( lunghezza/3 , grado-1 );
  turn(-45);
  koch( lunghezza/3 , grado-1 );
}

void kochsnow(int lunghezza, int grado){
  koch(lunghezza, grado);
  turn(120);
  koch(lunghezza, grado);
  turn(120);
  koch(lunghezza, grado);
  turn(120);
  koch(lunghezza, grado);
}

int main(void){
  start("koch.ps");
  int x, i;
  printf("inserisci il grado della curva: \n");
  scanf("%d", &i );
  printf("inserisci la lunghezza della curva risultante: \n");
  scanf("%d", &x );
  kochsnow(x, i);
  end();
}
