#ifndef GRAPH_H
#define GRAPH_H

typedef struct graph *Graph;

Graph graph_new( int n );

void graph_destroy( Graph g );

void graph_edgeinsert( Graph g,int v,int w );

Graph graph_read(void);

void graph_print( Graph g );

#endif
