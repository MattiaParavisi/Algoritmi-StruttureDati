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
  for(int i = 0; i <  g -> nv; i++){
    free( *(g -> A + i ));
  }
  free(g);
  return;
}

Graph graph_read(void){
  int numero1, numero2, vertici;
  FILE *filereader;
  printf("inserisci il numero di vertci del grafo che vuoi ottenere: \n");
  scanf("%d", &vertici);
  Graph newgraph = graph_new(vertici);
  filereader = fopen( "VerticiGrafo", "r");
  if(filereader == NULL){
    printf("non posso aprire il file");
    exit(0);
  }
  while(fscanf(filereader,"%d %d \n", &numero1, &numero2)!=EOF){
    newgraph -> ne ++;
    graph_edgeinsert(newgraph, numero1, numero2);
  }
  return newgraph;
}

void graph_print( Graph g ){
  for(int i = 0; i< g -> nv; i++){
    for(int j = 0; j< g -> nv; j++ ){
      printf("%d", *(*(g -> A + i) + j));
    }
    printf("\n");
  }
}
