#ifndef CODA_H
#define CODA_H

typedef struct pqueue *Pqueue;

/*crea una coda di priorità vuota che potrà contenere al massimo n Item*/
Pqueue pqueue_new(int );

/*distrugge la coda di priorità*/
void pqueue_destroy( Pqueue );

/*restituisce la lunghezza della coda di priorità*/
int pqueue_length( Pqueue );

/*inserisce l’Item nella coda di priorità*/
void pqueue_insert( Pqueue , int );

/*estrae dalla coda di priorità l’Item con chiave minima*/
int pqueue_extractmin( Pqueue );

/*restituisce l’Item con chiave minima nella coda di priorità*/
int pqueue_min( Pqueue );

#endif
