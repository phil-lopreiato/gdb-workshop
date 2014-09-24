#include <stdio.h>

int func (int a, int b ){
    int result=0;
    while(b != 0){
        if (b&1){
            result=result+a;
        }
        a<<=1;
        b>>=1;
    }
}

int main(void){
    int x, y;
    printf("Bitwise inspection program!\nEnter one number: ");
    scanf("%d", &x);
    printf("Enter another number: ");
    scanf("%d", &y);

    printf("The function output: %d\n", func(x, y));
}
