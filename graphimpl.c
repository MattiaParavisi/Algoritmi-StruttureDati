#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct graph{
  int nv;
  int ne;
  int **A;
};

Graph graph_new(int n){
  Graph newgraph = malloc(sizeof(struct graph));
  newgraph -> nv = n;
  newgraph -> ne = 0;
  newgraph -> A = calloc(n, sizeof(int*));
  for (int i = 0; i < n; i++){
    *(newgraph -> A+i) = calloc(n, sizeof(int*));
  }
  return newgraph;
}

void graph_edgeinsert( Graph g,int v,int w ){
   *(*(g -> A+v)+w) = 1 ;
   *(*(g -> A+w)+v) = 1 ;
}

void graph_destroy( Graph g ){
  free(g);
}

Graph graph_read(void){
  Graph newgraph = malloc(sizeof(struct graph));
  return newgraph;
}

void graph_print( Graph g ){

}
