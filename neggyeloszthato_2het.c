#include <stdio.h>
int main(){
    printf("Kérek egy számot:");
    int n;
    scanf("%d",&n);
    int c=1;
    while(c<n){
        if(c%4==0){
            printf("%d\n", c);
        }
        ++c;
    }
}
