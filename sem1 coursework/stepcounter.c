#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

int main()
{
    char option;
    int check = 0;
    int count = 0;
    int buffer_size = 50000;
    char line_buffer[buffer_size];
    FITNESS_DATA fitness_data1;

    while (check == 0)
    {
        printf("Enter option");
        scanf("%s" , &option);
        switch (option)
        {
            //Case A
            case 'A':
            printf("Input filename:");
            char filename[100];
            scanf("%s" , filename);
            FILE *file = fopen(filename , "r");
            if (file == NULL)
            {
                printf("Error:could not open file");
                exit(1);
            }
            break;

            //case B
            case 'B':
            while (fgets(line_buffer,buffer_size,file) != NULL)
            {
                count++;
            }
            printf("Total records: %d\n" , count);
            count = 0;
            break;

            //case C
            case 'C':
            FITNESS_DATA fitness_data1;
            FITNESS_DATA fitness_data2;
            int MinSteps;
            char* date;
            char* time;

            while (fgets(line_buffer,buffer_size,file) != NULL)
            {
                if (count == 0)
                {
                    tokeniseRecord(line_buffer , "," , fitness_data1.date , fitness_data1.time , fitness_data1.steps);
                    MinSteps = atoi(fitness_data1.steps);
                    date = fitness_data1.date;
                    time = fitness_data1.time;
                }
                count++;
                tokeniseRecord(line_buffer , "," , fitness_data2.date , fitness_data2.time , fitness_data2.steps);
                if(fitness_data2.steps<MinSteps)
                {
                    MinSteps= atoi(fitness_data2.steps);
                    date = fitness_data2.date;
                    time = fitness_data2.time;
                }
            }
            printf("Fewest steps: %s %s\n" , date , time);
            count = 0;
            break;

            //case D
            case 'D':
            FITNESS_DATA fitness_data1;
            FITNESS_DATA fitness_data2;
            int MaxSteps;
            char date;
            char time;

            while (fgets(line_buffer,buffer_size,file) != NULL)
            {
                if (count == 0)
                {
                    tokeniseRecord(line_buffer , "," , fitness_data1.date , fitness_data1.time , fitness_data1.steps);
                    MaxSteps = atoi(fitness_data1.steps);
                    date = fitness_data1.date;
                    time = fitness_data1.time;
                }
                count++;
                tokeniseRecord(line_buffer , "," , fitness_data2.date , fitness_data2.time , fitness_data2.steps);
                if(fitness_data2.steps>MaxSteps)
                {
                    MaxSteps= atoi(fitness_data2.steps);
                    date = fitness_data2.date;
                    time = fitness_data2.time;
                }
            }
            printf("Largest steps: %s %s\n" , date , time);
            count = 0;
            break;

            //case E
            case 'E':
            float stepsum = 0;
            float averageStep;
            int roundedsteps;
            FITNESS_DATA fitness_data1;
            while(fgets(line_buffer,buffer_size,file) != NULL)
            {
                tokeniseRecord(line_buffer , "," , fitness_data1.date , fitness_data1.time , fitness_data1.steps);
                stepsum = stepsum + atoi(fitness_data1.steps);
                count++;
            }
            averageStep = stepsum / count;
            roundedsteps = round(averageStep);
            printf("Mean step count: %d\n" , roundedsteps);
            count = 0;
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

    return (0);
}

