#include<stdio.h>

unsigned long f_iter2(int n){
  unsigned long f, f1 = 1, f2 = 1, i;
  if( n == 2 | n == 1 ) {
    return 1;
  }

  for( i = 3; i <= n; i++ ) {
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  }
  return f;
}

int main(void){
  int n=8;
  int res;
  res = f_iter2(n);
  printf("%d \n", res );
}
