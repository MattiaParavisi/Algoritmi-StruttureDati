#include <stdio.h>
#include <stdlib.h>

typedef struct{
  float x, y;
}Punto;

typedef struct{
  Punto p1;
  Punto p2;
}Rettangolo;

Rettangolo *newRettangolo(int x1, int y1, int x2, int y2 ){
  Rettangolo *newrett;
  newrett = malloc(1 * sizeof(Rettangolo));
  newrett -> p1.x = x1 ;
  newrett -> p1.y = y1 ;
  newrett -> p2.x = x2 ;
  newrett -> p2.y = y2 ;
}


int main(void){
  Rettangolo *rettmain;
  rettmain = newRettangolo(5.0, 4.0, 3.0, 2.0);
  printf("%.2f \n", rettmain->p1.x);
  printf("%.2f \n", rettmain->p1.y);
  printf("%.2f \n", rettmain->p2.x);
  printf("%.2f \n", rettmain->p2.y);
}
