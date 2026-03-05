#include <stdio.h>
int main(){
    int n = 1;
    int osszeg = 0;
    while (n <= 100){
        osszeg = osszeg+n;
        ++n;
    }
    printf("%d\n", osszeg);
}
