#include <stdio.h>
#include <stdlib.h>
#include "grapharchi.h"

struct nodi{
  int v;
  struct nodi *next;
};

struct graph{
  int nv;
  int ne;
  struct nodi **A;
};

int main(void) {
  /*Graph mygraph = graph_new(5);
  graph_edgeinsert(mygraph, 0, 1);
  printf("%d \n", mygraph -> A[0] ->v);
  printf("%d \n", mygraph -> A[1] ->v);
  graph_edgeinsert(mygraph, 0, 2);
  printf("%d \n", mygraph -> A[0] ->v);
  printf("%d \n", mygraph -> A[2] ->v);*/
  Graph mygraph = graph_read();
  printf("%d \n", mygraph -> A[0] ->v);
  printf("%d \n", mygraph -> A[2] ->v);
  graph_destroy(mygraph);
}
