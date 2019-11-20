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
  struct Nodo *curr = NULL, *new = NULL, *start = NULL, *resins;
  int scelta, keyvalue, *res, valins;
  while(1){
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
  }
  list_printInv(start);
  /*printf("La ricorsiva: \n");
  list_printInvRec(start);
  printf("Trasformo in array: \n");
  res = listToArray(start);
  for(int i=0; i<4; i++){     //chiedere come determinare la grandezza di un array
    if(*(res+i)==0){
      break;
    }
    printf("%d \n", *(res+i));
  }
  printf("Libero tutto! \n");
  list_destroy(start);              //chidere per le free nella destroy se poi start punta a roba a caso
  printf("Stampo la lista! \n");
  list_printInv(start);
  printf("inserisco nela lista\n");
  printf("inserisci il valore da inserire nella lista: \n");
  scanf("%d", &valins);
  resins = olist_insert(valins, start);
  list_printInv(resins);*/
  printf("inserisci il valore da cercare nella lista: \n");
  scanf("%d", &valins);
  resins = olist_search(valins, start);
  if(resins!=NULL){
    printf("valore trovato: %d\n", resins -> value);
  }
  return 0;

}
