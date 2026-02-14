#include <stdio.h>

int main(){
    int a,b;
    printf("Adja meg a téglalap első oldalának hosszát(cm): \n");
    scanf("%d", &a);
    printf("Adja meg a másik oldal hosszát(cm): \n");
    scanf("%d", &b);
    int K = 2*(a+b);
    int T = a*b;
    printf("A téglalap kerülete: %dcm; a területe: %dn^2. \n", K, T);
    return 0;
}