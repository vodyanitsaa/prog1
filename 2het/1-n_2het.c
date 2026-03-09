#include <stdio.h>
int main(){
    printf("Kérek egy számot:");
    int nyil;
    scanf("%d", &nyil);
    int counter = 1;
    while(counter<nyil){
        printf("%d -> ", counter);
        ++counter;
    }
    printf("%d\n",counter);
}
