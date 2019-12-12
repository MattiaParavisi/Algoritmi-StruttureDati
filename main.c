#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

struct graph{
  int nv;
  int ne;
  int **A;
};

int main(void) {
  Graph mygraph = malloc(sizeof(struct graph));
  mygraph = graph_read();
  graph_print(mygraph);
  graph_destroy(mygraph);
  return 0;
}
