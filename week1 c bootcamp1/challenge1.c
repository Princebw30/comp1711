#include <stdio.h>

int main()
{
    int a = 1;
    int b = 0;
    int c = 11;
    int d = 100;

    //1.1
    while(a<=10)
    {
        printf(a);
        a++;
    }

    //1.2
    while(b<= 50)
    {
        printf(b);
        b+=2;
    }

    //1.3
    while(c<=1000)
    {
        printf(c);
        c*=11;
    }

    //1.4
    while(d>=0)
    {
        printf(d);
        d-=5;
    }
    return(0);
}