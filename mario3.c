#include <stdio.h>
int main(){
    printf("Kérem a magasságot:\n");
    int h;
    scanf("%d", &h);
    int i=0;
    int j=0;
    for(i=0;i<=h;i++){
        for(j;j<h-1;j++){
            printf(" ");
        }
        for(j=0;j<i;j++){
            printf("#");
        }
        printf("  ");
        for(j=0;j<i;j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}