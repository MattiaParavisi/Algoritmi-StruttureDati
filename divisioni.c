#include <stdio.h>
#define N 10

int main( void) {
    int b, n, i = 0;
    int c[N] = {0};

    printf("inserire il numero da convertire seguito da uno spazio e dalla base in cui deve essere convertito: ");
    scanf( "%d %d", &n, &b );

    do c[i++] = n % b;
        while ( ( n /= b ) > 0 );

    printf("il numero convertito in base %d e' : \n", b );
    while ( i > 0 )
        printf( "%d", c[--i] );
    printf( "\n" );

    return 0;
}
// 1) la variabile n può essere chimata anche numero da convertire, e la variabile b può essere chiamata
//    base

// 2) l'array c può essere chiamato anche "numero convertito" perchè contiene tutti i valori del numero convertito
//    nella base selezionata

// 3) il programma può essere chimato anche "converti_base"

// 4) aggiunto

// 5) il programma prende in input due numeri una base e un numero da convertire, poi restituisce il numero convertito

// 7) (numero/100)%10
