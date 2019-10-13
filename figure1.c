#include <stdio.h>

int main ( void ) {
  int n , i , j, n1;
  printf("inserisci la dimensione del lato del quadrato: \n");
  scanf("%d", &n );
  n1=n;
  if(n%2!=0){
    n++;
  }
  for(i=0; i<n1; i++){
    if(i%2==0){
        for(j=0;j<n/2;j++){
          printf("o");
          printf("+");
        }
        printf("\n");
    }else if(i%2!=0){
        for(j=0;j<n/2;j++){
          printf("+");
          printf("o");
        }
        printf("\n");
    }
  }
  return 0;
}
