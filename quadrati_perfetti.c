#include <stdio.h>
#define N 10

int main(void){
  int num,power;
  num=1;
  for(num; num!=(N+1); num++){
    power=num*num;
    printf("%d\n", power);
  }

}
