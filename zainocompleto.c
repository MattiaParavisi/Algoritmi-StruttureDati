#include <stdio.h>
#include <stdlib.h>

struct oggetto{
  int peso;
  int valore;
};

struct oggetto *riempiarray(int *return_obj){
  int numero1, numero2, index = 0, input = 0;
  struct oggetto *arr;
  printf("quanti oggetti vuoi inserire? ");
  scanf("%d", &input);
  FILE *filereader;
  arr = malloc(input*sizeof(struct oggetto));  //SUPPONGO DI SAPERE CHE GLI OGETTI SIANO N
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
  *return_obj = input;
  return arr;
}

int max(int a, int b){
  return a>b ? a : b;
}

int main(void){
  int numOgg, peso;
  struct oggetto *arr = riempiarray(&numOgg);
  printf("inserisci il peso dello zaino da considerare: ");
  scanf("%d", &peso);
  int matrice[peso+1][numOgg+1];
  for(int i = 0; i < peso+1; i++){
    for(int j = 0; j < numOgg+1; j++){
      matrice[i][j] = 0;
    }
  }
  for(int j = 1; j <= numOgg+1; j++){ //colonna oggetto
    for(int i = 1; i <= peso+1; i++){  //riga peso
      if((i-(*(arr+j-1)).peso)>=0){
        matrice[i][j] = max(matrice[i][j-1] , (*(arr+j-1)).valore + matrice[i-(*(arr+j-1)).peso][j-1]);
      } else {
        matrice[i][j]  = matrice[i][j-1];
      }
    }
  }
  for(int i = 0; i < peso+1; i++){
    for(int j = 0; j < numOgg+1; j++){
      printf("%d", matrice[i][j]);
    }
    printf("\n");
  }
}




/*
if(j-(*(arr+j-1)).peso >= 0){
  printf("a questo punto considero la matrice: m[%d][%d]",j-(*(arr+j)).peso,i-1 );
  matrice[j][i] = max(matrice[j][i-1], (*(arr+j)).valore + matrice[j-(*(arr+j)).peso][i-1]) ;
} else {
  printf("consider la matrice m[%d][%d]", j, i-1);
  matrice[j][i] = matrice[j][i-1];
}
printf("%d",matrice[j][i]);
}
printf("\n");
*/
