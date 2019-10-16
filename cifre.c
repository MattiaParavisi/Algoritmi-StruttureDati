#include <stdio.h>
#include <ctype.h>

int main(void){

  int c, f[10] = {0}, i;
  c = getchar();

  while ( c != '.' ) {
    if ( isdigit( c ) )
      f[ c - '0' ]++;
    c = getchar();
  }

  for(i=0; i<10; i++){
    if(f[i]!=0){
      printf("%d: ", i);
      printf("%d \n", f[i]);
    }
  }

}
