#include<stdio.h>

unsigned long f_iter1(int n){
  unsigned long f, f1 = 1, f2 = 1;
  if( n == 2 | n == 1 ) {
    return 1;
  }
  while(n-- >= 3){
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  }
  return f;
}

int main(void){
  int n=8;
  int res;
  res = f_iter1(n);
  printf("%d \n", res );
}
