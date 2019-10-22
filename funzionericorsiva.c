#include <stdio.h>

int counter = 0;

int f_rec(int n){
  if( n == 1 || n == 2 ){
    return 1;
  }
  counter++,
  printf("%d \n", counter );
 return f_rec( n - 1 ) + f_rec( n - 2 );
}

int main(void){
  int n=10;
  int res;
  res = f_rec(n);
  printf("%d \n", res );
}
