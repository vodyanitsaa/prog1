#include <stdio.h>

int main() {
    FILE *f = fopen("valos_szamok.txt", "r");

    if (f == NULL) {
        fprintf(stderr, "Hiba: Nem sikerult megnyitni a fajlt!\n");
        return 1;
    }

    double osszeg = 0.0;
    double aktualis_szam;

    while (fscanf(f, "%lf", &aktualis_szam) == 1) {
        osszeg += aktualis_szam;
    }

    fclose(f);

    printf("%.20f\n", osszeg);

    return 0;
}