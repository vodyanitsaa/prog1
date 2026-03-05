#include <stdio.h>
int main(){
    int ascii=65;
    int osszeg=0;
    while (ascii<91){
        printf("%d: %c\n",ascii, (char)ascii);
        osszeg+=ascii;
        ++ascii;
    }
    printf("Az összegük: %d\n", osszeg);
}
