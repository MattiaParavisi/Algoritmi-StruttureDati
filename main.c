#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph{
  int nv;
  int ne;
  int **A;
};

void stampaMatrice(Graph g, int n ){
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++ ){
      printf("%d", *(*(g -> A + i) + j));
    }
    printf("\n");
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  Graph mygraph = malloc(sizeof(struct graph));
  mygraph = graph_new(n);
  //printf("il grafo contiene: %d \n", mygraph -> nv);
  graph_edgeinsert( mygraph, 4, 3 );
  stampaMatrice(mygraph, n);
  return 0;
}
