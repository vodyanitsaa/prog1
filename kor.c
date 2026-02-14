#include <stdio.h>
#include <math.h>

int main() {
    float r;
    printf("Kérem a kör sugarát(cm):");
    scanf("%f", &r);
    float K = 2*r*(4.0*atan(1.0));
    float T = r*r*(4.0*atan(1.0));
    printf("A kör kerülete: %fcm, a területe %fcm^2. \n", K, T);
    return 0; 
}