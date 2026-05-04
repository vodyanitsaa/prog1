#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nev[50];
} Hallgato;

int pti_e(const char *szak) {
    if (strlen(szak) != 3) return 0;
    return (tolower(szak[0]) == 'p' && tolower(szak[1]) == 't' && tolower(szak[2]) == 'i');
}

int hasonlit(const void *a, const void *b) {
    return strcmp(((Hallgato*)a)->nev, ((Hallgato*)b)->nev);
}

void formal_nev(char *s) {
    if (s[0] != '\0') {
        s[0] = toupper(s[0]);
    }
}

int main() {
    FILE *f = fopen("nevek.csv", "r");
    if (!f) return 1;

    Hallgato ptisek[100];
    int db = 0;
    char sor[100];

    while (fgets(sor, sizeof(sor), f)) {
        sor[strcspn(sor, "\n\r")] = 0;

        char *nev = strtok(sor, ",");
        char *kor = strtok(NULL, ",");
        char *szak = strtok(NULL, ",");

        if (nev && szak && pti_e(szak)) {
            formal_nev(nev);
            strcpy(ptisek[db++].nev, nev);
        }
    }
    fclose(f);

    qsort(ptisek, db, sizeof(Hallgato), hasonlit);

    for (int i = 0; i < db; i++) {
        printf("%s%s", ptisek[i].nev, (i < db - 1) ? ", " : "");
    }
    printf("\n");

    return 0;
}