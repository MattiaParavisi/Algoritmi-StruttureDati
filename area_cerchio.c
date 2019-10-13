#include <stdio.h>
#include <math.h>

int main(void){
  float raggio, area;
  printf("inserisci il raggio del cerchio di cui vuoi calcolare l'area: \n");
  scanf("%f",&raggio);
  area= (raggio*raggio)*M_PI;
  printf("l'area è: %f\n",area );
}
