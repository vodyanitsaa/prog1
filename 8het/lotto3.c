#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int db, min, max;

    printf("Hany db random szamot kersz? ");
    scanf("%d", &db);
    printf("Also hatar: ");
    scanf("%d", &min);
    printf("Felso hatar (zart intervallum): ");
    scanf("%d", &max);

    if (db > (max - min + 1)) {
        printf("Hiba: Nem lehet ennyi kulonbozo szamot generalni ebben az intervallumban!\n");
        return 1;
    }

    int szamok[db];
    int akt_db = 0;

    while (akt_db < db) {
        int uj_szam = rand() % (max - min + 1) + min;
        
        int volt_mar = 0;
        for (int i = 0; i < akt_db; i++) {
            if (szamok[i] == uj_szam) {
                volt_mar = 1;
                break;
            }
        }

        if (!volt_mar) {
            szamok[akt_db] = uj_szam;
            akt_db++;
        }
    }

    for (int i = 0; i < db - 1; i++) {
        for (int j = 0; j < db - i - 1; j++) {
            if (szamok[j] > szamok[j + 1]) {
                int seged = szamok[j];
                szamok[j] = szamok[j + 1];
                szamok[j + 1] = seged;
            }
        }
    }

    printf("\nA generalt szamok:");
    for (int i = 0; i < db; i++) {
        printf(" %d", szamok[i]);
    }
    printf("\n");

    return 0;
}
