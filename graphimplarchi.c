#include "grapharchi.h"
#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int v;
  struct nodo *next;
};

struct graph{
  int nv;
  int ne;
  struct nodo **A;
};

Graph graph_new(int n){
  Graph mygraph = malloc(sizeof(struct graph));
  mygraph -> nv = n;
  mygraph -> ne = 0;
  mygraph -> A = malloc(n * sizeof(struct nodo*));
  for(int i = 0; i<n; i++){
    *(mygraph -> A + i) = NULL;
  }
  return mygraph;
}

void graph_edgeinsert( Graph g,int valore1, int valore2 ){
  if(*(g -> A + valore1) == NULL){
    struct nodo *puntnodo = malloc(sizeof(struct nodo));
    puntnodo -> v = valore2;
    *(g -> A +valore1) = puntnodo;
    puntnodo -> next = NULL;
  } else {
    struct nodo *nodovecchio = *(g -> A + valore1);
    struct nodo *puntnodo = malloc(sizeof(struct nodo));
    puntnodo -> v = valore2;
    *(g -> A +valore1) = puntnodo;
    puntnodo -> next = nodovecchio;
  }
  if(*(g -> A + valore2) == NULL){
    struct nodo *puntnodo = malloc(sizeof(struct nodo));
    puntnodo -> v = valore1;
    *(g -> A +valore2) = puntnodo;
  } else {
    struct nodo *nodovecchio = *(g -> A + valore2);
    struct nodo *puntnodo = malloc(sizeof(struct nodo));
    puntnodo -> v = valore1;
    *(g -> A +valore2) = puntnodo;
    puntnodo -> next = nodovecchio;
  }
  return;
}

void graph_destroy( Graph g ){
  for(int i = 0; i < g -> nv; i++){
    free(g -> A[i]);
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




/*
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
*/
