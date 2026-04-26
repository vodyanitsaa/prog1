#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10

typedef struct{
    int min;
    int max;
    double atlag;
}stat;

stat szamlalas(int n, int tomb[]){
    stat adatok;
    adatok.min = tomb[0];
    adatok.max = tomb[0];
    int osszeg = 0;
    for(int i = 0; i < n; ++i){
        if(tomb[i] < adatok.min){
            adatok.min = tomb[i];
        }else if(tomb[i] > adatok.max){
            adatok.max = tomb[i];
        }
        osszeg += tomb[i];
    }
    adatok.atlag = (double) osszeg / n;

    return adatok;
}

void randomizalas(int n, int tomb[]){
    printf("A tömb elemei: ");
    for(int i = 0; i < n; ++i){
        tomb[i] = rand() % (90 - 10 + 1) + 10;
        printf("%d", tomb[i]);
        if(i != n-1){
            printf(", ");
        }
    }
}

int main() {
    srand(time(NULL));

    int szamok[size] = {};

    randomizalas(size, szamok);

    stat m = szamlalas(size, szamok);

    printf("\nLegkisebb elem: %d\n", m.min);
    printf("Legnagyobb elem: %d\n", m.max);
    printf("Az elemek atlaga: %.1f\n", m.atlag);

    return  0;
}
