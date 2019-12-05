#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct occorrenza{
  char *word;
  int n;
};

struct node{
  struct occorrenza occ;
  struct node *l, *r;
};

typedef struct node* Parola;

int main(void){

}
