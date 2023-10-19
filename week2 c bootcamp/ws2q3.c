#include <stdio.h>
#include <string.h>


int str_len(char *input)
{
    int check = 0;
    for(int count = 0 ; check=0 ; count++)
    {
        if (!input[count])
        {
            check =1;
            count++;
            return (count);
        }
        else
        {
            count++;
        }
    }
    
}
int main()
{
    int wordCount;
    printf("Type in a word");
    char input[]=scanf("%s",input);
    wordCount = str_len(input);
    printf("Length of word is %d\n",wordCount);

    return(0);
}