#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define len 2
#define HASHSIZE 8

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
  int hashsize = HASHSIZE;
  int c;
  while((c = *str++))
    hash = ((hash << 5) + hash) + c;
  return hash % hashsize;
}

Dict dict_init(){
  int hashsize = HASHSIZE;
  Dict init = malloc(sizeof(Dict));
  init -> array = malloc(hashsize*sizeof(Chain));
  init -> count = 0;
  for(int i = 0; i < hashsize; i++)
    *(init -> array+i) = NULL;
  return init;
}

Item *dict_lookup(Dict t, char *w){
  unsigned long hashres;
  struct element *p;
  hashres = hash(w);
  if((t -> array + hashres)==NULL){
    return NULL;
  }else{
    p = *(t -> array + hashres);
    while(p){
      if(strcmp((p -> item -> word), w)==0){
        return p->item;
      }
      p = p -> next;
    }
    return NULL;
  }
}

void dict_add(Dict t, Item *p){
  unsigned long hashres;
  struct element *nuovo;
  nuovo = malloc(sizeof(struct element));
  hashres = hash(p -> word);
  nuovo -> item = p;
  nuovo -> next = NULL;
  *(t -> array + hashres) = nuovo;//element
}

int main(void){
  Dict dizionario;
  Item *mioitem;
  int ln = 0;
  char carattere, primo;
  mioitem = malloc(sizeof(Item));
  dizionario = dict_init();
  char *parola = "PORCODIO";
  mioitem -> word = parola;
  dict_add(dizionario, mioitem);
  mioitem = dict_lookup(dizionario, parola);
  printf("%s\n",mioitem -> word );



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
