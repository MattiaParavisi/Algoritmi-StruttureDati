#include <stdio.h>
#include <stdlib.h>
#include "code.h"

typedef int *Heap;

struct pqueue {
  Heap h;
  int size, count;
};

void heapsort(Pqueue coda){
  int size;
  for(int i = 0; i < coda -> size; i++){
    size = pqueue_extractmin(coda);
    printf("%d \n", size);
  }
}

int main(void){
  int size, numelem, elem;
  Pqueue coda;
  printf("inserisci quanti elementi vuoi ordinare: ");
  scanf("%d", &numelem);
  coda = pqueue_new(numelem);
  for(int i = 0; i <  numelem ; i++){
    printf("inserisci l'elemento da inserire: \n");
    scanf("%d", &elem);
    pqueue_insert(coda, elem);
  }
  printf("PORCO DIO \n");
  heapsort(coda);
}
