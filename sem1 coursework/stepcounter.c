#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <FitnessDataStruct.h>

int main()
{
    char option;
    int check = 0;
    char filename;
    int count = 0;
    int buffer_size = 50000;
    char line_buffer[buffer_size];

    while (check == 0)
    {
        printf("Enter option");
        scanf("%s" , &option);
        switch (option)
        {
            case 'A':
            printf("Input filename:");
            scanf("%s" , &filename);
            FILE *file = fopen(filename , "r");
            if (file == NULL)
            {
                printf("Error:could not open file");
                exit(1);
            }
            break;
            case 'B':
            while (fgets(line_buffer,buffer_size,file) != NULL)
            {
                count++;
            }
            printf("Total records: %d\n" , count);
            break;
            case 'C':
            FITNESS_DATA fitness_data1;
            FITNESS_DATA fitness_data2;
            int 
            

            while (fgets(line_buffer,buffer_size,file) != NULL)
            {
                while (count = 0;)
                {
                    tokeniseRecord(line_buffer , "," , fitness_data1.date , fitness_data1.time , fitness_data1.steps);
                }
                tokeniseRecord(line_buffer , "," , fitness_data2.date , fitness_data2.time , fitness_data2.steps);
                if(fitness_data2.steps<fitness_data1.steps)
                {
                    fitness_data1.steps = fitness_data2.steps;
                    fitness_data1.date = fitness_data2.date;
                    fitness_data1.time = fitness_data2.time;
                }
            }
            break;
            case 'D':

            break;
            case 'E':

            break;
            case 'F':

            break;
            case 'Q':
            check = 1;
            printf("Exit");
            exit(0);
            break;
        }
    }
}

return (0);