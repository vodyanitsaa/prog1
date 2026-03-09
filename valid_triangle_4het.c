#include <stdio.h>
int valid_triangle(int a, int b, int c){
    if(a+b<c || a+c<b || b+c<a){
        return 0;
    }
    return 1;
}
int main(){
    printf("%d\n", valid_triangle(1,2,10));
}
