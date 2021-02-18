#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMR 50
#define NUMC 80

typedef float mappa[NUMR][NUMC];

typedef struct { int r; int c; } posizione;

void stampaPercorso(posizione p[NUMC]) {
    char v[NUMR][NUMC];
    for(int i = 0; i < NUMR; i++){
        for(int j = 0; j < NUMC; j++){
            v[i][j] = '.';
        }
    }
    for(int i = 0; i < NUMC; i++){
        v[p[i].r][p[i].c] = '*';
    }
    for(int i = 0; i < NUMR; i++){
        for(int j = 0; j < NUMC; j++){
            printf("%c", v[i][j]);
        }
        printf("\n");
    }
    
}

posizione *makeposizione(int rin, int cin){
    posizione *p = malloc(sizeof(posizione));
    p -> r = rin;
    p -> c = cin;
    return p;
}

int main()
{
    srand((unsigned int)time(0));
    posizione vett[NUMC];
    int aumenti[] = {-1, 1, 0};
    int prevr, actr, index, aum;
    posizione *p;
    for(int i = 0; i < NUMC; i++){ //colonna
        if(i == 0){
            actr = rand()%50;
            //printf("r: %d c: %d\n", actr, i);
            p = makeposizione(actr, i);
            prevr = actr;
        } else {
            index = rand()%3;
            aum = aumenti[index];
            actr = prevr + aum;
            //printf("aumenti : %d prever: %d\n", aum, prevr);
            //printf("r: %d c: %d\n", actr, i);
            p = makeposizione(actr, i);
            prevr = actr;
        }
        vett[i] = *p;
    }
    /*for(int i = 0; i < NUMC; i++){
        printf("%d %d\n", vett[i].r, vett[i].c);
    }*/    
    stampaPercorso(vett);
    return 0;
}
