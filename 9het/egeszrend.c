#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Használat: %s <fájlnév>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Hiba: A fájl nem nyitható meg!\n");
        return 1;
    }

    int szamok[2000];
    int db = 0;

    while (db < 2000 && fscanf(f, "%d", &szamok[db]) == 1) {
        db++;
    }

    fclose(f);

    if (db > 0) {
        qsort(szamok, db, sizeof(int), compare);

        for (int i = 0; i < db; i++) {
            printf("%d\n", szamok[i]);
        }
    }

    return 0;
}