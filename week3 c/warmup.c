#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename [] = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int num[200];
    int count = 0;

    int buffer_size = 200;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));
        num[count] = atoi(line_buffer);
        count++;
    }

    for (int i = 0; i<=200 ; i++)
    {
        if num[count] > 1000;
        bignumcount++;
    }

    fclose(file);
    return 0;
}