#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void statisztika(int n, int tomb[], int *pMin, int *pMax, double *pAtlag) {
    *pMin = tomb[0];
    *pMax = tomb[0];
    int osszeg = 0;

    for (int i = 0; i < n; i++){
        if (tomb[i] < *pMin){
            *pMin = tomb[i];
        }else if (tomb[i] > *pMax){
            *pMax = tomb[i];
        }
        osszeg += tomb[i];
    }
    *pAtlag = (double)osszeg / n;
}

int main() {
    srand(time(NULL));
    int meret = 10;
    int szamok[10];

    printf("A tomb elemei: ");
    for (int i = 0; i < meret; i++){
        szamok[i] = rand() % 90 + 10;
        printf("%d%s", szamok[i], (i == meret - 1 ? "" : ", "));
    }
    puts("");

    int min, max;
    double atlag;

    statisztika(meret, szamok, &min, &max, &atlag);

    printf("Legkisebb elem: %d\n", min);
    printf("Legnagyobb elem: %d\n", max);
    printf("Az elemek atlaga: %.1f\n", atlag);

    return 0;
}