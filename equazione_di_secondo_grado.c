#include <stdio.h>
#include <math.h>

int main(void){
  float delta, a, b, c;
  float sol1, sol2;
  printf("inserisci i valori di a b e c: \n");
  scanf("%f %f %f", &a, &b, &c);
  delta= (b*b)-(4*a*c);
  if(delta<0){
    printf("equazione impossibile");
  }else {
    sol1= (-b+sqrt(delta))/(2*a);
    sol2= (-b-sqrt(delta))/(2*a);
    printf("le soluzioni dell'equazione %.1fx^2 + %.1fx + %.1f \n", a, b, c );
    printf("sono %f e %f", sol1, sol2 );
  }
}
