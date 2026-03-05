#include <stdio.h>
int main(){
printf("Kérek egy számot:");
    int szam;
    scanf("%d", &szam);
    while (szam>0){
        if(szam%2!=0){
            printf("%d\n", szam);
        }
        --szam;
    }
}
