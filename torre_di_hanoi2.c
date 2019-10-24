#include <stdio.h>
//int i=0;

void hanoi( int n, int from, int temp, int to ){
  if(n==1){
    printf("%d -> %d\n", from, to );
    //i+=1;
  }if(n>=2){
    hanoi(n-1, from, to, temp);
    hanoi(1,from,temp,to);
    hanoi(n-1, temp, from, to);
  }

}

int main(void){
  int n;
  scanf("%d",&n);
  hanoi(n, 0, 1, 2);
  //printf("%d \n",i);
}
