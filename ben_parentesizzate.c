#include<stdio.h>

int main(void){
  char countgenerale, c;

  while((c=getchar())!='.'){
    if(c=='('){
      countgenerale++;
    }else if(c==')'){
      countgenerale--;
    }
  }

  if(countgenerale!=0){
    printf("non ");
  }
  printf("ben parentesizzata \n");
}
