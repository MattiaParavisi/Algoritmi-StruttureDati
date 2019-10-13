#include <stdio.h>

int main(void){
  int i, j, h, n, flag;
  char prev;
  flag=0;
  scanf("%d", &n );
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      if(i==j){
        printf("|");
        prev='|';
        continue;
      }
      if(i!=0 && flag!=1){
        for(h=0;h<i;h++){
          printf("o");
        }
        flag=1;
        prev='o';
        continue;
      }
      if(prev!='o'){
        printf("+");
      }
    }
    printf("\n");
    flag=0;
  }
}
