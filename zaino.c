#include<stdio.h>
#include<stdlib.h>

struct oggetto{
  int peso;
  int valore;
};

struct oggetto *riempiarray(int *return_obj){
  int numero1, numero2, index = 0;
  struct oggetto *arr;
  FILE *filereader;
  arr = malloc(3*sizeof(struct oggetto));  //SUPPONGO DI SAPERE CHE GLI OGETTI SIANO N
  filereader = fopen( "PesiValori", "r");
  if(filereader == NULL){
    printf("non posso aprire il file \n");
    exit(0);
  }
  while(fscanf(filereader,"%d %d \n", &numero1, &numero2)!=EOF){
    (*(arr+index)).peso = numero1;
    (*(arr+index)).valore = numero2;
    index++;
  }
  *return_obj = 3;
  return arr;
}

int main(void){
  int peso_zaino, *arrpesi, oggetti_zaino;
  struct oggetto *arr;
  scanf("%d", &peso_zaino);
  arrpesi = malloc((peso_zaino+1)*sizeof(int));
  *(arrpesi) = 0;
  arr = riempiarray(&oggetti_zaino);
  /*for(int i = 0; i < oggetti_zaino; i++){
    printf("%d\n", (*(arr+i)).peso );
  }*/
  for(int i = 0; i < peso_zaino; i++ ){
    for(int j = 0; j < oggetti_zaino; j++){
      if(*(arrpesi+i+(*(arr+j)).peso) < peso_zaino && *(arrpesi+i)+(*(arr+j)).valore > *(arrpesi+i+(*(arr+j)).peso)){
        *(arrpesi+i+(*(arr+j)).peso) = *(arrpesi+i) + (*(arr+j)).valore;
      }
    }
  }
  printf("stampo arr pesi giro: \n");
  for(int i = 0; i<=peso_zaino;i++){
    printf("%d \n", *(arrpesi+i) );
  }
}
