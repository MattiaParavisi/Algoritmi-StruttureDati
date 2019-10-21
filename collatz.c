#include <stdio.h>

int collatz(int n){
  int res;
  if(n==1){
    n=1;
    return 1;

  }
  if(n%2==0){
    n = n/2;
    printf("%d\n", n );
    collatz(n);

  } else {
    n = (n*3)+1;
    printf("%d\n", n );
    collatz(n);

  }
}

int main(void){
  int n,res;

  scanf("%d", &n );

  res=collatz(n);
}
