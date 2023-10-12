#include <stdio.h>

int main()
{
    int num1;
    int num2;
    printf( "enter first number\n");
    scanf( "%d" , &num1);
    printf( "enter second number\n");
    scanf( "%d" , &num2);
    int ans = num1+num2;
    printf( "The answer is %d\n" , ans);
    return 0;
}