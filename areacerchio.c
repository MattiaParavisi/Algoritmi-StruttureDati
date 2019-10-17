#include<stdio.h>
#include<math.h>

typedef struct {
  float x, y;
} Punto;

typedef struct {
  Punto p1;
  Punto p2;
} Rettangolo;

typedef struct{
  Punto centro;
  float raggio;
} Cerchio;

int main( void ){

  float b, h, area, duep, distanza_punti, area_cerchio, perimetro_cerchio;
  Rettangolo r;
  Cerchio c;

  printf( "RETTANGOLO:\n" );
  printf( "Inserisci le coordinate del punto in basso a sinistra\n" );
  scanf( "%f%f" , &r.p1.x, &r.p1.y );
  printf( "Inserisci le coordinate del punto in alto a destra\n" );
  scanf( "%f%f", &r.p2.x, &r.p2.y );
  b = r.p2.x - r.p1.x;
  h = r.p2.y - r.p1.y;
  area = b * h;
  duep = 2 * ( b + h );
  printf( "L'area del rettangolo vale %f, il perimetro vale %f\n", area, duep );

  printf("CERCHIO:\n");
  /*printf("Inserisci le coordinate del centro: \n");
  scanf("%f%f", &c.centro.x, &c.centro.y);
  printf("Inserisci le coordinate del raggio: \n");
  scanf("%f%f", &c.raggio.x, &c.raggio.y );
  distanza_punti=sqrt(pow((c.centro.x-c.raggio.x),2.0)+pow((c.centro.y-c.raggio.y),2.0));
  area_cerchio= pow(2.0,distanza_punti)*M_PI;
  printf("%f\n", area_cerchio );*/
  printf("inserisci il punto di centro: ");
  scanf("%f%f", &c.centro.x, &c.centro.y);
  printf("inserisci la lunchezza del raggio: ");
  scanf("%f", &c.raggio);
  perimetro_cerchio= 2*M_PI*c.raggio;
  area_cerchio=M_PI*pow(2.0,c.raggio);
  printf("l'area è %.1f, il perimetro e' %.1f \n", area_cerchio, perimetro_cerchio);
 	
  return 0;
}
