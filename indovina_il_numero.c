#include <stdio.h>
#define MAX 1000

int main ( void ) {
	int min = 0, max = MAX , n;
	char risposta ;
	for ( ; ; ) {
		n = min + ( max - min ) / 2;
		printf ( " Il numero e ‘ %d? " , n );
		scanf ( "%c " , &risposta );
		switch ( risposta ) {
		case '<': 
			max = n - 1; 
			break;
		case '>': 
			min = n + 1; 
			break;
		case '=': 
			return 0;
		}
	}
	/* printf( "max = %d, min = %d\n", max, min ); */
	return 0;
}
