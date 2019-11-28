#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1//macro per generazione numeri random

struct bit_node {
  int item;
  struct bit_node *l, *r;
};

typedef struct bit_node* Bit_node;

int *randinarr(){
  int *a, randomnum;
  a = malloc(N*sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < N; i++ ){
    randomnum = rand() % 21;
    *(a + i) = randomnum;
  }
  return a;
}

Bit_node bit_arr2tree( int a[],int size,int i){
  Bit_node newnode, figliosinistro, figliodestro;
  newnode = malloc(sizeof(struct bit_node));
  figliosinistro = malloc(sizeof(struct bit_node));
  figliodestro = malloc(sizeof(struct bit_node));
  if((2*i+1) > (N-1)){
    newnode -> item = a[i];
    newnode -> l = NULL;
    newnode -> r = NULL;
    return newnode;
  }
  if(i<N)
    newnode -> item = a[i];
  if((2*i+1)<N)
    figliosinistro = bit_arr2tree(a, size, (2*i+1));
    newnode -> l = figliosinistro;
  if((2*i+2)<N)
    figliodestro = bit_arr2tree(a, size, (2*i+2));
    newnode -> r = figliodestro;
  return newnode;
}

void bit_printnode( Bit_node p){
  printf("*");
  if(p -> item){
    printf("%d \n", p -> item);
  }
}

void bit_printassummary( Bit_node p,int spaces ){
  if ( p ) {
    for(int i = 0; i < spaces; i++ ){
      printf("  ");
    }
    bit_printnode( p );
    bit_printassummary( p -> l, spaces+1 );
    bit_printassummary( p -> r, spaces+1 );
  }
}

int main(void){
  int *vettore;
  Bit_node res;
  vettore = randinarr();
  for(int i = 0; i < N; i++)
    printf("%d \n", *(vettore+i));
  res = bit_arr2tree(vettore, N, 0);
  printf("adesso stampo l'albero\n");
  bit_printassummary(res, 0);
  printf("\n");
}
