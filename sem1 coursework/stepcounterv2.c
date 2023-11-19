#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include "FitnessDataStruct.h"

int main() {
    char option;
    int check = 0;
    
    int buffer_size = 500;
    char line_buffer[100]; 
    //char line_buffer[500]; 
    FITNESS_DATA fitness_data1;
    FILE *file = NULL; 

    while (check == 0) 
    {
        printf("Menu options: \n");
        printf("A: Specify the filename to be imported\n");
        printf("B: Dislay the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the date andtime of the timeslot with the largest number of steps\n");
        printf("E: Find te mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &option); 

        switch (option) 
        {

            //case A
            case 'A':
                printf("Input filename: ");
                char filename[100];
                scanf("%s", filename);
                file = fopen(filename, "r");
                if (file == NULL) 
                {
                    printf("Error: Could not open file\n");
                    exit(1);
                }
                printf("File successfully loaded.");
                break;

            //case B
            case 'B':
                if (file == NULL) 
                {
                    printf("Error: File not opened\n");
                } 
                else 
                {
                    int countB = 0;
                    while (fgets(line_buffer, buffer_size, file) != NULL) 
                    {
                        countB++;
                    }
                    printf("Total records: %d\n", countB);
                }
                rewind(file);
                break;

            // //case C
            case 'C':
            if (file == NULL) 
            {
                printf("Error: File not opened\n");
            } 
            else 
            {
                FITNESS_DATA fitness_data2;
                int MinSteps = INT_MAX;
                char date[50];
                char time[50];
                int countC = 0;

                while (fgets(line_buffer, buffer_size, file) != NULL) 
                {
                    tokeniseRecord(line_buffer, ",", fitness_data2.date, fitness_data2.time, fitness_data2.steps);
                    int steps = atoi(fitness_data2.steps);
                    if (steps < MinSteps) 
                    {
                        MinSteps = steps;
                        strcpy(date, fitness_data2.date);
                        strcpy(time, fitness_data2.time);
                    }
                    countC++;
                }
                printf("Fewest steps: %s %s\n", date, time);
            }
            rewind(file);
            break;

            // //case D
            case 'D':
            if (file == NULL) 
            {
                printf("Error: File not opened\n");
            } 
            else 
            {
                FITNESS_DATA fitness_data2;
                int MaxSteps = INT_MIN;
                char date[50];
                char time[50];
                int countD = 0;

                while (fgets(line_buffer, buffer_size, file) != NULL) 
                {
                    tokeniseRecord(line_buffer, ",", fitness_data2.date, fitness_data2.time, fitness_data2.steps);
                    int steps = atoi(fitness_data2.steps);
                    if (steps > MaxSteps) 
                    {
                        MaxSteps = steps;
                        strcpy(date, fitness_data2.date);
                        strcpy(time, fitness_data2.time);
                    }
                    countD++;
                }
                printf("Largest steps: %s %s\n", date, time);
            }
            rewind(file);
            break;

            // //case E
            case 'E':
            if (file == NULL) 
            {
                printf("Error: File not opened\n");
            } 
            else 
            {
                float stepsum = 0;
                float averageStep;
                int countE = 0;

                while (fgets(line_buffer, buffer_size, file) != NULL) 
                {
                    tokeniseRecord(line_buffer, ",", fitness_data1.date, fitness_data1.time, fitness_data1.steps);
                    stepsum += atof(fitness_data1.steps); 
                    countE++;
                }
                averageStep = stepsum / countE;
                int intAverageStep = round(averageStep);
                printf("Mean step count: %d\n", intAverageStep);
            }
            rewind(file);
            break;

            // //case F
            case 'F':
            if (file == NULL)
            {
                printf("Error: File not opened\n");
            }
            else 
            {
                char startDate[11];
                char startDate1[11];
                char endDate[11];
                char endDate1[11];
                char startTime[7];
                char startTime1[7];
                char endTime[7];
                char endTime1[7];
                int periodCount = 0;
                int periodCount1 = 0;
                int check = 0;

                FITNESS_DATA fitness_data2;

                while(fgets(line_buffer, buffer_size, file) != NULL)
                {
                    tokeniseRecord(line_buffer, ",", fitness_data2.date, fitness_data2.time, fitness_data2.steps);
                    if ( check == 0)
                    {
                        if (atoi(fitness_data2.steps) > 500)
                        {
                            strcpy( startDate1 , fitness_data2.date);
                            strcpy( startTime1 , fitness_data2.time);
                            strcpy( endDate1 , fitness_data2.date);
                            strcpy(endTime1 , fitness_data2.time);
                            check = 1;
                            periodCount1 = 1;
                        }
                    }
                    else
                    {
                        if (atoi(fitness_data2.steps) > 500)
                        {
                            strcpy( endDate1 , fitness_data2.date);
                            strcpy( endTime1 , fitness_data2.time);
                            periodCount1++;
                        }
                        else
                        {
                            if (periodCount1 > periodCount)
                            {
                                strcpy( startDate , startDate1);
                                strcpy( startTime , startTime1);
                                strcpy( endDate , endDate1);
                                strcpy( endTime , endTime1);
                                periodCount = periodCount1;
                            }
                            periodCount1 = 0;
                            check = 0;
                        }
                    }
                }
                if (periodCount1 > periodCount)
                {
                    strcpy( startDate , startDate1);
                    strcpy( startTime , startTime1);
                    strcpy( endDate , endDate1);
                    strcpy( endTime , endTime1);
                    periodCount = periodCount1;
                }
                printf("Longest period start: %s %s\n" , startDate , startTime);
                printf("Longest period end: %s %s\n" , endDate , endTime);
                
            }
            rewind(file);
            break;

            // //case Q
            case 'Q':
                check = 1;
                printf("Exit\n");
                if (file != NULL) 
                {
                    fclose(file); 
                }
                break;

            //default
            default:
                printf("Invalid choice. Try again");
        }
    }

    return 0;
}