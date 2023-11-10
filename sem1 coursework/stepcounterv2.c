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
    char line_buffer[500]; 
    FITNESS_DATA fitness_data1;
    FILE *file = NULL; 

    while (check == 0) {
        printf("Enter option: ");
        scanf(" %c", &option); 

        switch (option) {
            case 'A':
                printf("Input filename: ");
                char filename[100];
                scanf("%s", filename);
                file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error: Could not open file\n");
                    exit(1);
                }
                break;

            case 'B':
                if (file == NULL) 
                {
                    printf("Error: File not opened\n");
                } 
                else 
                {
                    int countB = 0;
                    while (fgets(line_buffer, buffer_size, file) != NULL) {
                        countB++;
                    }
                    printf("Total records: %d\n", countB);
                }
                rewind(file);
                break;

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

                while (fgets(line_buffer, buffer_size, file) != NULL) {
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
            case 'F':
            rewind(file);
            break;

            case 'Q':
                check = 1;
                printf("Exit\n");
                if (file != NULL) 
                {
                    fclose(file); 
                }
                break;

            default:
                printf("Invalid option: %c\n", option);
        }
    }

    return 0;
}