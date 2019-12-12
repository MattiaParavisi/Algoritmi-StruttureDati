#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

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
  Graph mygraph = malloc(sizeof(struct graph));
  mygraph = graph_read();
  printf("%p", *(*(mygraph -> A + 1)) );
  return 0;
}
