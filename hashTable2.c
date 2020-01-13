#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define len 2
#define hashsize_def 8
#define len_array 5

typedef struct{
  char *word;
  int *ln_arr;
  int size_array;
  int ult_pos_occ;
}Item;


struct element{
  Item *item;
  struct element *next;
};

typedef struct element *Chain;

typedef struct ht{
  Chain *array;
  int count;
} *Dict;

char *readword(char *a){
  int size = len, countletter = 0;
  char c;
  char *parola = malloc(size * sizeof(char));
  *(parola) = ' ';
  while(isalpha(c = getchar())){
    if(countletter > size){
      size += 2;
      parola = realloc(parola, size*sizeof(char));
      *(parola+countletter) = c;
    }
    *(parola+countletter) = c;
    countletter++;
  }
  *a = c;
  return parola;
}

unsigned long hash(char *str){
  unsigned long hash = 5381;
  int hashsize = hashsize_def;
  int c;
  while((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash % hashsize;
}

Dict dict_init(){
  printf("entro in dict_init\n");
  int hashsize = hashsize_def;
  Dict init = malloc(sizeof(struct ht));
  init -> array = malloc(hashsize * sizeof(Chain));
  init -> count = 0;
  for(int i = 0; i < hashsize - 1; i++)
    *(init -> array+i) = NULL;
  return init;
}

Item *dict_lookup(Dict t, char *w){
  printf("entro in dict lookup \n");
  unsigned long hashres;
  struct element *p;
  printf("parola: %s \n", w );
  hashres = hash(w);
  printf("hash: %ld \n", hashres);
  if(*(t -> array + hashres)==NULL){
    printf("entro qui\n");
    return NULL;
  }else{
    p = *(t -> array + hashres);
    while(p){
      printf("parole in p: %s\n", p-> item -> word );
      if(strcmp((p -> item -> word), w)==0){
        return p->item;
      }
      p = p -> next;
    }
    return NULL;
  }
}


Item *chain_find(Chain c, char *w ){
  //chain è definito come *element
  printf("entro in chain_find c vale %p\n", c);
  if(c == NULL){
    printf("CATENA NULLA\n");
    return NULL;
  }
  if(c -> item != NULL){
    printf("a quanto pare item è diverso da null \n");
    printf("la parola quindi è %s\n", c -> item -> word );
  }
  printf("la parola da confrontare è %s\n", w);
  while(c){
    if( strcmp(w,  c -> item -> word) == 0 ){
      return c -> item;
    }
  }
  return NULL;
}

Chain chain_insert( Chain c, Item *p ){
  printf("entro in chain insert \n");
  struct element *backup_vecchio;
  struct element *nuovo;
  Item *trovato;
  nuovo = malloc(sizeof(struct element));
  backup_vecchio = malloc(sizeof(struct element));
  backup_vecchio = c;
  if(c == NULL){
    printf("CATENA VUOTA \n");
    nuovo -> item = p;
    //printf("vecchio: %s\n", c -> item -> word );
    nuovo -> next = NULL;
    c = nuovo;
    printf("c %p\n", c);
    return c;
  } else {
    //cerco l'elemento, se c'e' aggiorno se non c'e' aggiungo in testa.
    trovato = chain_find(c, p->word);
    if(trovato!=NULL){
      printf("DIOSTRACANE\n"); //aggiornare il nujmero di linea
      return c; //CAMBIA
    } else {
      printf("TI DEVO AGGIUNGERE");
      nuovo -> item = p;
      c = nuovo;
      nuovo -> next = backup_vecchio;
      return c; //CAMBIA
    }
  }
}

void chain_print( Chain h ){
  struct element *next;
  while(h){
    printf("stampo %s\n", h -> item -> word);
    next = h -> next;
    h = next;
  }
  return;
}

void dict_add(Dict t, Item *p){
  unsigned long hashres;
  Chain chain_res;
  Item *trovato;
  hashres = hash(p -> word);
  trovato = chain_find(*(t -> array + hashres), p -> word);
  if(trovato == NULL){
    chain_res = chain_insert(*(t -> array + hashres), p );
    *(t -> array + hashres) = chain_res;
  }else {
    printf("ho trovato qualcosa!!!\n");
    chain_res = chain_insert(*(t -> array + hashres), p );
  }
}

Item *item_new(char *w, int ln){
  Item *return_item = malloc(sizeof(Item));
  return_item -> word = w;
  return_item -> ln_arr  = malloc(len_array*sizeof(int));
  return_item -> ult_pos_occ = 0;
  return_item -> size_array = len_array;
  return return_item;
}

void item_modify( Item *p, int ln ){
  int size = p -> size_array;
  if( p -> ult_pos_occ == size - 1 ){
    size *= 2;
    p -> ln_arr = realloc( p -> ln_arr, size * sizeof(int) );
    p -> ult_pos_occ ++;
    *( p -> ln_arr + (p -> ult_pos_occ)) = ln ;
    return;
  } else {
    p -> ult_pos_occ ++;
    *( p -> ln_arr + (p -> ult_pos_occ)) = ln ;
    return;
  }
}

int main(void){
  Item *my_item;
  Dict dizionario;
  Item *mioitem;
  int ln = 0;
  char carattere, primo;
  mioitem = malloc(sizeof(Item));
  dizionario = dict_init();


  char *parola = "OSSIGNUR";
  mioitem -> word = parola;
  dict_add(dizionario, mioitem);

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL){
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
      printf("la parola di hashcodeeeeeeeee %d è : %p\n",i , dizionario -> array[i]-> item -> word);
    }
  }

  mioitem = malloc(sizeof(Item));
  mioitem -> word = "MIAMMAMMA";
  dict_add(dizionario, mioitem);

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL){
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
      printf("la parola di hashcodeeeeeeeee %d è : %p\n",i , dizionario -> array[i]-> item -> word);
    }
  }

  mioitem = malloc(sizeof(Item));
  mioitem -> word = "PLUTO";
  dict_add(dizionario, mioitem);

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL)
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
  }

  mioitem = malloc(sizeof(Item));
  mioitem -> word = "PAPERINO";
  dict_add(dizionario, mioitem);

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL){
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
      printf("la parola di hashcodeeeeeeeee %d è : %p\n",i , dizionario -> array[i]-> item -> word);
    }
  }
  mioitem = malloc(sizeof(Item));
  mioitem -> word = "PIPPONE";
  dict_add(dizionario, mioitem);

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL)
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
  }

  printf("SECONDO PAPERO\n");

  mioitem = malloc(sizeof(Item));
  mioitem -> word = "PAPERINO";
  dict_add(dizionario, mioitem);

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL){
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
      printf("la parola di hashcodeeeeeeeee %d è : %p\n",i , dizionario -> array[i]-> item -> word);
    }
  }


  printf("la parola che cerco è: %s\n", parola);
  mioitem = dict_lookup(dizionario, parola);
  if( mioitem != NULL){
    printf("%s\n",mioitem -> word );
    my_item = item_new(parola, 1);
    printf("%s \n", my_item -> word);
    printf("%d \n", my_item -> ult_pos_occ);
    printf("%d \n", my_item -> size_array);
  } else {
    printf("la parola non è stata trovata \n");
  }

  for(int i = 0; i < hashsize_def; i++){
    printf("array in posizione %d = %p \n", i, *(dizionario -> array +i));
    if( *(dizionario -> array +i)!=NULL)
      printf("la parola di hashcode %d è : %s\n",i , dizionario -> array[i]-> item -> word);
  }

  printf("STAMPO CON CHAIN PRINT");

  chain_print(*(dizionario -> array +7));

  /*printf("ORA CHIAMO CHAIN_PRINT \n");
  chain_print(*(dizionario -> array + 7));*/

  /*while(1){
    scanf("%c", &primo);
    printf("primo: %c \n", primo);
    if(primo=='f'){
      break;
    }
    while(carattere != '\n'){
      char *parola = readword(&carattere);
      if(*(parola)!=' ')
        printf("%s ", parola);
    }
    carattere = ' ';
    printf("\n");
  }*/
}




/*
void dict_add(Dict t, Item *p){
  printf("entro in dict_add \n");
  unsigned long hashres;
  struct element *nuovo;
  Chain chain_res;
  Item *trovato;
  printf("parola: %s \n", p -> word );
  nuovo = malloc(sizeof(struct element));
  printf("nuovo next : %p \n", nuovo -> next);
  hashres = hash(p -> word);
  printf("hash: %ld \n", hashres);
  nuovo -> item = p;
  printf("parola nell' element: %s \n", nuovo -> item -> word );
  trovato = chain_find(*(t -> array + hashres), p -> word);
  if(trovato == NULL){
    printf("NULLO *********\n");
    printf("%p e hashres = %ld\n", *(t -> array + hashres), hashres );
    chain_res = chain_insert(*(t -> array + hashres), p );
    printf("chainres %p e chainres contiene %s\n", chain_res, chain_res -> item ->word);
    *(t -> array + hashres) = chain_res;
  } else {

  }
  return;
}*/
