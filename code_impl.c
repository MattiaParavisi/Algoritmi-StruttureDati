#include "code.h"
#include <stdlib.h>
#include <stdio.h>

typedef int *Heap;

struct pqueue {
  Heap h;
  int size, count;
};

Pqueue pqueue_new(int n){
  Pqueue coda = malloc(sizeof(struct pqueue));
  coda-> h = malloc(n + 1 * sizeof(int));
  coda -> size = n;
  coda -> count = 0;
  return coda;
}

/*distrugge la coda di priorità*/
void pqueue_destroy( Pqueue coda ){
  free(coda);
  return;
}

/*restituisce la lunghezza della coda di priorità*/
int pqueue_length( Pqueue coda ){
  return (coda -> count);
}


int cmp(int a, int b){
  return a-b;
}

void swap( Heap h, int i, int j ){
  int backup;
  backup = *(h+i);
  *(h+i) = *(h+j);
  *(h+j) = backup;
}

int father(int i){
  return i/2;
}

void  heapify_up( Heap h, int i ) {
  if ( i > 1 ) {
    int j = father(i);
    int ret = cmp(*(h+i), *(h+j));
    if ( ret < 0 ) {
      swap( h, i, j );
      heapify_up( h, j );
    }
  }
}

/*inserisce l’Item nella coda di priorità*/
void pqueue_insert( Pqueue coda , int item ){
  coda -> count ++;
  *(coda -> h + coda -> count ) = item;
  heapify_up( coda -> h, coda -> count);
  return;
}

void  heapify_down( Heap h, int i, int n ) {
  if ( 2*i <= n ) { /*i ha  almeno  un  figlio*/
    int j;   /*indice  del  figlio  di i con  chiave  minore*/
    if ( 2*i == n ) /*i ha solo il  figlio  sinistro*/
      j = 2*i;
    else  /*i ha due  figli*/
      j = cmp( *(h+2*i), *(h+2*i+1) ) < 0 ? 2*i : 2*i + 1;
    if ( cmp( *(h+j), *(h+i) ) < 0 ) {
      swap( h, i, j );
      heapify_down( h, j, n );
    }
  }
}

/*estrae dalla coda di priorità l’Item con chiave minima*/
int pqueue_extractmin( Pqueue coda){
  int ret = *(coda -> h + 1);
  swap(coda->h, 1, coda -> count);
  coda -> count --;
  heapify_down(coda -> h, 1 , coda -> count );
  return ret;
}

/*restituisce l’Item con chiave minima nella coda di priorità*/
int pqueue_min( Pqueue coda){
  return *(coda -> h+1);
}
