#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int guess;
    int check = 0;
    int ans;

    srand(time(NULL));
    ans = rand()%100+1;

    while(check==0)
    {
        printf("Guess the number\n");
        scanf("%d" , &guess);
        if (guess > ans)
        {
            printf("Answer is lower than your guess\n");
        }
        else if (guess < ans)
        {
            printf("Answer is higher than your guess\n");
        }
        else
        {
            printf("You got the answer!\n");
            check = 1;
        }
    }
    return (0);

}