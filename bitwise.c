#include <stdio.h>

int ques0(int x, int y){
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return !(temp);
}

/* question 1 */
int ques1(int x) {
    int z;
    int y  = ~x+1;
    z= (~(y|x));
    z = (z >> 31);
    return (z & 1);  
}

/* question 2 */
int ques2(int x) {
    int mask = x>>31;
    int y= (x ^ mask);
    int z = (~mask + 1);
    return (y+z);
}

/* question 3 */
int ques3(int x, int y){
    return ~(~x | ~y);
}

/* question 4 */
int ques4(int x, int y) {

    int sum = x+y;
    int x_neg = x>>31;
    int y_neg = y>>31;
    int s_neg = sum>>31;

    int temp = (~(x_neg ^ y_neg) & (x_neg ^ s_neg));
    int out = !temp;

    return out;
}

/* question 5 */
int ques5(int x) {
    int result = (x<<31);
    result = (result >> 31);
    return result;
}

/* question 6 */
int ques6(void) {
    int byte = 0x55;
    int word = byte | byte<<8;
    return word | word<<16;
}

/* question 7 */
int ques7(int x) {
    return x & (~x+1);
}

/* question 8 */
int ques8(int x) {
    int y= ~x+1;
    int z= ((y|x) >> 31);
    return (z & 1);
}

/* question 9 */
int ques9(int x, int n, int c) {
    int n8 = n << 3;
    int mask = 0xff << n8;
    int cshift = c << n8;
    int z= (x & ~mask);
    return (z  | cshift);
}

/* question 10 */
int ques10(void) {
    int byte = 0xAA;
    int word = byte | byte<<8;
    return word | word<<16;
}

/* question 11 */
int ques11(int x) {
    int m8  = 0xAA;
    int m16 = m8  | m8  << 8;
    int m32 = m16 | m16 <<16;
    int fillx = x | m32;
    return !~fillx;
}

/* question 12 */
int ques12(int x, int m, int n) {
    int a = ~m+1;
    int b = ~x +1;
    a = x + a;
    b = b + n;
    return !((a|b) >> 31);
}

/* question 13 */
int ques13(int x) {
    int mask1, mask2, mask4, mask8, mask16;
        
    mask2 = 0x33 + (0x33 << 8);
    mask2 += mask2 << 16;
    mask1 = mask2 ^ (mask2 << 1);
    mask4 = 0x0F + (0x0F << 8);
    mask4 += mask4 << 16;
    mask8 = 0xFF + (0xFF << 16);
    mask16 = 0xFF + (0xFF << 8);
        
    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask4) + ((x >> 4) & mask4);
    x = (x & mask8) + ((x >> 8) & mask8);
    x = (x & mask16) + ((x >> 16) & mask16);
 
    return x;
}

/* question 14 */
int ques14(int x) {
    int result = 0;
    int i;
    for (i = 0; i < 32; i++)
        result ^=  (x >> i) & 0x1;
    return result;
}

/* question 15 */
int ques15(int x, int n) {
    /* for ques15 only, assume n is not a negative number  */
    int temp = (1 << n);
    int z = temp + ~0;
    return (z & x);
}

int main(){
    int a, b;

 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20: ");
 	scanf ("%d",&a);
 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20: ");
 	scanf ("%d", &b);
	printf("\n");
 	
	printf("you entered a= %d b= %d  \n", a,b);

	printf("00: %d\n", ques0(a,b));
    printf("01: %d\n", ques1(a));
    printf("02: %d\n", ques2(a));
    printf("03: %d\n", ques3(a, b));
    printf("04: %d\n", ques4(a, b));
    printf("05: %d\n", ques5(a));
    printf("06: %d\n", ques6());
    printf("07: %d\n", ques7(a));
    printf("08: %d\n", ques8(a));
    printf("09: %d\n", ques9(a, b, 1));
    printf("10: %d\n", ques10());
    printf("11: %d\n", ques11(a));
    printf("12: %d\n", ques12(a,b,2));
    printf("13: %d\n", ques13(a));
    printf("14: %d\n", ques14(a));
    printf("15: %d\n", ques15(a, b));

	return 0;
}
