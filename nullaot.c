#include <stdio.h>

int main() {
    FILE *be = fopen("in.txt", "r");
    FILE *ki = fopen("out.txt", "w");

    if (be == NULL) {
        fprintf(stderr, "Hiba: Az in.txt nem talalhato!\n");
        return 1;
    }
    if (ki == NULL) {
        fprintf(stderr, "Hiba: Az out.txt-t nem sikerult letrehozni!\n");
        fclose(be);
    }

    printf("# in.txt sikeresen megnyitva\n");
    printf("# 0,5-nel nagyobb szamok szurese...\n");

    double szam;
    int darab = 0;

    while (fscanf(be, "%lf", &szam) == 1) {
        if (szam > 0.5) {
            fprintf(ki, "%f\n", szam);
            darab++;
        }
    }

    printf("# szures vege\n");

    fclose(be);
    fclose(ki);

    printf("# out.txt bezarva\n");
    printf("# out.txt-be kiirt szamok mennyisege: %d db\n", darab);

    return 0;
}