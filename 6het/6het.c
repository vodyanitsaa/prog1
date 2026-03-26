#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26
#define SIZE2 200
#include<time.h>

void abece(char tomb[]){
    for (int i = 0; i <= SIZE; ++i){
        if (i == SIZE){
            tomb[SIZE] = '\0';
            break;
        }
        tomb[i] = 'a'+i;
    }
}

void abszolut(int e[], int m[], int n){
    for (int i = 0; i < n; i++){
        if (e[i] < 0){
            m[i] = -1*e[i];
        }else{
            m[i] = e[i];
        }
    }
}

void kiiratas(int tomb[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d", tomb[i]);
        if (i < n-1){
            printf(", ");
        }
    }
    printf("\n");
}

int elemszamolas(int tomb[], int n){
    int kulonbozok = 0;
    while (1){
        printf("Szám: ");
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        if (n < 0 || n > 99){
            puts("Ez a szám kívül esik az elfogadható intervallumon.");
        }else{
            if (tomb[n] == 0){
                tomb[n] = 1;
                kulonbozok += 1;
            }
        }
    }
    return kulonbozok;
}



int main (int argc, char *argv[]){
    srand(time(NULL));

    char abc[SIZE];
    abece(abc);
    puts(abc);

    ////////////////////////////////////////////
    //./a.out utan kell megadni a szamokat
    char szamok[SIZE2];
    if (argc != 3){
        puts("Hiba! Két paramétert (számot) kell megadni");
        return 1;
    }
    int szam1 = atoi(argv[1]);
    int szam2 = atoi(argv[2]);
    int összeg = szam1 + szam2;
    printf("%d\n", összeg);

    ////////////////////////////////////////////

    puts("Hány számot szeretnél?:");
    int n;
    scanf("%d", &n);
    int eredeti[SIZE2];
    int masolat[SIZE2];
    for (int i = 0; i < n; ++i){
        printf("%d. szám: ", i+1);
        scanf("%d", &eredeti[i]);
    }
    abszolut(eredeti, masolat, n);
    printf("A kapott számok abszolútértékei: ");
    kiiratas(masolat, n);
    printf("A kapott számok: ");
    kiiratas(eredeti,n);

    /////////////////////////////////////////////

    puts("Adj meg 0 végjelig egész számokat az [1, 99] intervallumból:");
    int elofordul[100] = {0};
    int num;
    int kulondb = elemszamolas(elofordul, num);
    int kiirt = 0;
    printf("\n%d különböző számjegy fordult elő.\n", kulondb);
    printf("Ezek (növekvő sorrendben): ");
    for (int i = 0; i <= 99; ++i){
        if (elofordul[i] == 1){
            printf("%d", i);
            kiirt += 1;
            if (kiirt < kulondb){
                printf(", ");
            }
        }
    }
    printf("\n");

    ///////////////////////////////////////////

    puts("Adj meg szavakat '*' végjelig!");
    char szavak[100];
    int szo = 0;
    int maxhossz = 0;
    getchar();
    while (1){
        printf("Szó: ");
        fgets(szavak, sizeof(szavak), stdin);
        int hossz = strlen(szavak);
        if (hossz > 0 && szavak[hossz-1] == '\n'){
            szavak[hossz-1] = '\0';
            --hossz; 
        }
        if (strcmp(szavak, "*") == 0){
            break;
        }
        if (hossz > 0){
            szo += 1;
            if (hossz > maxhossz){
                maxhossz = hossz;
            }
        }
    }
    printf("%ddb szót adtál meg. A leghosszabb %d karakterből áll.\n", szo, maxhossz);

    ///////////////////////////////////////////

    puts("Hány darab random számot kérsz?");
    int db;
    scanf("%d", &db);
    printf("Alsó határ: ");
    int min;
    scanf("%d", &min);
    printf("Felső határ(zárt intervallum): ");
    int max;
    scanf("%d", &max);
    int lottoszamok[db];
    for(int i = 0; i < db; ++i){
        lottoszamok[i] = ((rand() % (max - min)) + min);
    }
    printf("A generált számok: ");
    for(int i = 0; i < db; ++i){
        printf("%d ", lottoszamok[i]);
    }
    puts("");

    return 0;
}
