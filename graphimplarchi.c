#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

struct nodi{
  int v;
  struct nodi *next;
};

struct graph{
  int nv;
  int ne;
  struct nodi **A;
};

Graph graph_new(int n){
  Graph newgraph = malloc(sizeof(struct graph));
  newgraph -> nv = n;
  newgraph -> ne = 0;
  newgraph -> A = calloc(n, sizeof(struct nodi*));
  for (int i = 0; i < n; i++){
    *(newgraph -> A + i) = NULL;
  }
  return newgraph;
}

void graph_edgeinsert( Graph g,int v1,int w ){
  struct nodi nuovonodo;
  if(*(g -> A + v1 ) == NULL){
    nuovonodo.v = w;
    *(g -> A[v1]) = nuovonodo;
    nuovonodo.next = NULL;
  }
  nuovonodo.next = *(g -> A + v1);
  nuovonodo.v = w;
  *(*(g-> A + v1)) = nuovonodo;
  if(*(g -> A + w ) == NULL){
    nuovonodo.v = v1;
    *(g -> A[v1]) = nuovonodo;
    nuovonodo.next = NULL;
  }
  nuovonodo.next = *(g -> A + v1);
  nuovonodo.v = v1;
  *(*(g-> A + v1)) = nuovonodo;
  return;
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
  return;
}
