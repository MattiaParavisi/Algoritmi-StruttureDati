#include <stdio.h>
#define n 9
int main(void){
  int i, j, inew, jnew, nn, riga, colonna;
  int quadrato[n][n] = {{0}}, k = 1;
  i = 0; 
  j = n/2;
  nn = n * n;
  for ( k = 1; k <= nn; k++ ) {
    quadrato[i][j] = k;
    inew = ( i == 0 ) ? n - 1 : i - 1;
    jnew = ( j == n - 1 ) ? 0 : j + 1;
    if ( quadrato[ inew ][ jnew ] == 0 ) {
      i = inew;
      j = jnew;
    }
    else {
      i++; 
    }
  }
  
  for(riga=0; riga<n; riga++){
	for(colonna=0; colonna<n; colonna++){
		printf("%d\t",quadrato[riga][colonna]);
		if (colonna+1==n){
			printf("\n");
		}
	}
  }
}
