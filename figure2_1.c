#include <stdio.h>

int main(void){
  int i, j, h, n, flag;
  flag=0;
  scanf("%d", &n );

  for(i=0; i<n; i++){

    for(j=0; j<n; j++){

      if(i==j){
        printf("|");
        continue;
      }

      if(i!=0 && flag!=1){
        for(h=0;h<i;h++){
          printf("o");
        }
        flag=1;
        j=h-1;
        continue;
      }

      printf("+");
    }
    
    printf("\n");
    flag=0;
  }
}
