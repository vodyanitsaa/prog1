#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Használat: %s <fájlnév>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror("Hiba a fájl megnyitásakor");
        return 1;
    }

    int max_hossz = -1;
    int max_sor_szama = 0;
    
    int aktualis_hossz = 0;
    int aktualis_sor_szama = 1;
    int c;

    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            if (aktualis_hossz > max_hossz) {
                max_hossz = aktualis_hossz;
                max_sor_szama = aktualis_sor_szama;
            }
            aktualis_hossz = 0;
            aktualis_sor_szama++;
        } else {
            aktualis_hossz++;
        }
    }

    if (aktualis_hossz > 0 && aktualis_hossz > max_hossz) {
        max_hossz = aktualis_hossz;
        max_sor_szama = aktualis_sor_szama;
    }

    if (max_hossz != -1) {
        printf("%d %d\n", max_sor_szama, max_hossz);
    }

    fclose(f);
    return 0;
}