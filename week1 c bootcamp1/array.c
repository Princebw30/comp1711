#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int count;
    int array[10];
    srand(time(NULL));
    
    for (count=0 ; count <10 ; count ++)
    {
        int temp = rand()%1000 +1;
        array[count] = temp;
        printf("array[%d] : %d\n" , count , array[count]);
    }
    return(0);
}
