#include <stdio.h>

int counter = 0;

unsigned long f_riter(unsigned long a,unsigned long b,int n){
  if( n == 2 ) {
    return a;
  }
  if( n == 1 ) {
    return b;
  }
  counter++;
  printf("%d \n", counter );
  return f_riter( a + b, a, n - 1 );
}

int main(void){
  int n=10;
  int res;
  res = f_riter( 1, 1, n);
  printf("%d \n", res );
}
