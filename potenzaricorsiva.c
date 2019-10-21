#include <stdio.h>

int potenzaricorsiva(int n, int i){
  int result = n;
  if(i==0){
    return 1;
  }
  result *= potenzaricorsiva(n, i-1);
  return result;
}

int main(void){
  int n, i, res;
  scanf("%d", &n);
  scanf("%d", &i);
  res = potenzaricorsiva(n,i);
  printf("%d\n", res );

}
