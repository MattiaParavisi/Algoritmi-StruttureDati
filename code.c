#include <stdio.h>
#include <stdlib.h>

#define arrlen 2;

struct Nodo{
  int value;
  struct Nodo* next;
};

void list_printInv( struct Nodo *l ){
  if(l == NULL){
    return;
  }
  while(l != NULL){
    printf("valore non rec: %d\n", l -> value );
    l = l -> next;
  }
  return;
}

void count( struct Nodo *l ){
    int counter = 0;
  if(l == NULL){
      printf("0\n");
    return;
  }
  while(l != NULL){
    counter++;
    l = l -> next;
  }
  printf("%d\n", counter);
  return;
}

void list_printInvRec( struct Nodo *l){
  if( l == NULL){
    return;
  }
  list_printInvRec(l -> next);
  printf("valore rec: %d\n", l -> value);
  return;
}

int *listToArray( struct Nodo *l ){
  int *a, i=0, size = arrlen;
  a = malloc(size*sizeof(int));
  while(l != NULL){
    if(i>size){
      size = size + size;
      a = realloc(a, size*sizeof(int));
    }
    *(a+i) = l -> value;
    l = l -> next;
    i++;
  }
  return a;
}

struct Nodo *olist_search(int n,struct Nodo *l ){
  if(l == NULL){
    return l;
  }
  while(l -> value != n){
    l = l -> next;
    if(l == NULL){
      break;
    }
  }
  return l;
}

struct Nodo *delete(int n, struct Nodo *l){
    struct Nodo *segugio=NULL, *start = l;
    if(l==NULL){
        return l;
    }
    if(l -> value == n){
        segugio = l -> next;
        return segugio;
    }
    while(l!=NULL && l->value!=n){
        segugio = l;
        l = l->next;
    }
    segugio -> next = l -> next;
    free(l);
    return start;
}

struct Nodo *olist_insert(int n, struct Nodo *l ){
  struct Nodo *segugio=NULL, *newnode, *start;
  start = l;
  newnode = malloc(sizeof(struct Nodo));
  newnode -> value = n;
  newnode -> next = NULL;
  if(l==NULL){
    l = newnode;
    return l;
  }
  if(segugio==NULL && l -> value > n){
    segugio = newnode;
    newnode -> next = l;
    return segugio;
  }
  while(l->next!=NULL && l->next->value<n){
    segugio = l;
    l = l->next;
  }
  segugio = l;
  l = l->next;
  segugio->next = newnode;
  newnode->next = l;
  return start;
}

void list_destroy(struct Nodo *l){
	struct Nodo *osso;
	while(1){
    osso = l -> next;
		free(l);
    l = osso;
    if(l->next == NULL){
      free(l);
      return;
    }
  }
}


int main(void){
  struct Nodo *curr = NULL, *new = NULL, *start = NULL, *resins, *ressearch;
  int scelta, keyvalue, *res, valins, ins;
  char sceltaoperazione;
  while(1){
      printf("scegli l'operazione: ");
      scanf(" %c", &sceltaoperazione);
      switch(sceltaoperazione){
          case '+':
              printf("inserisci il numero da aggiungere all'insieme: ");
              scanf("%d", &ins);
              ressearch = olist_search(ins, start);
              if(ressearch==NULL){
                  start = olist_insert(ins, start);
                  list_printInv(start);
              }
              break;
          case '-':
              printf("inserisci il numero da eliminare dall'insieme: ");
              scanf("%d", &ins);
              start = delete(ins, start);
              list_printInv(start);
              break;
          case '?':
              printf("inserisci il numero da cercare nell'insieme: ");
              scanf("%d", &ins);
              ressearch = olist_search(ins, start);
              if(ressearch==NULL){
                  printf("%d non appartiene all'insieme \n", ins);
                  break;
              }
              printf("%d appartiene all'insieme \n", ins);
              break;
          case 'c':
              count(start);
              break;
          case 'p':
              list_printInv(start);
              break;
          case 'o':
              list_printInvRec(start);
              break;
          case 'd':
              list_destroy(start);
              start = NULL;
              break;
          case 'f':
              return 0;
      }
  }
}













/*while(1){
    printf("inserisci un nuovo nodo?\n1)si \n2)no \n");
    scanf(" %d",&scelta);
    if(scelta == 0 && curr == NULL){
      break;
    }
    if(scelta == 0){
      curr -> next = NULL;
      break;
    }
    printf("inserisci il valore della chiave: ");
    scanf(" %d", &keyvalue );
    new = malloc(sizeof(struct Nodo));
    if(curr == NULL){
      curr = new;
      start = new;
      curr -> value = keyvalue;
    } else {
      curr -> next = new;
      curr = curr -> next;
      curr -> value = keyvalue;
    }
  }/*
  
