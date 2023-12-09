#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char date[11];
    char time[6];
    int steps;
} FitnessData;

int ValidDate(const char *date)
{
    if(strlen(date) == 10 && date[4] == '-' && date[7] == '-')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ValidTime(const char *time)
{
    if(strlen(time) == 5 && time[2] == ':')
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ValidSteps(int steps)
{
    if(steps>=0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

// Function to tokenize a record
void tokeniseRecord( const char *record, const char *delimiter, char *date, char *time, int steps) 
{
    char *ptr = strtok((char *)record, delimiter);
    if (ptr != NULL) 
    {
        strcpy(date, ptr);
        ptr = strtok(NULL, delimiter);
        if (ptr != NULL) 
        {
            strcpy(time, ptr);
            ptr = strtok(NULL, delimiter);
            if (ptr != NULL) 
            {
                steps = atoi(ptr);
            }
        }
    }
}

//main
int main() 
{
    FILE *file = NULL;
    int check = 0;
    int buffer_size = 200;
    char line_buffer[buffer_size];

    while (check == 0)
    {
        printf("Enter filename: ");
        char filename[100];
        scanf("%s" , filename);
        file = fopen(filename , "r");
        if (file==NULL)
        {
            printf("Error: invalid file");
            return(1);
            exit (1);
        }
        else
        {
            check = 1;
        }
    }
    int maxsize = 59;
    int i = 0;
    int x = 0;
    int check1 = 0;
    char *temp;
    FitnessData fitness_data[maxsize];
    while(fgets(line_buffer, buffer_size, file))
    {
        tokeniseRecord(line_buffer , "," , fitness_data[i].date , fitness_data[i].time , fitness_data[i].steps);
        if(!ValidDate || !ValidTime || !ValidSteps)
        {
            printf("Error: invalid file\n");
            return(1);
        }
        i++;
    }
    while ( check1 != 1)
    {
        check1 = 1;
        for (int y = 0 ; y < maxsize ; y++ )
        {
            if(fitness_data[y].steps < fitness_data[y+1].steps)
            {
                int temp = fitness_data[y].steps;
                fitness_data[y].steps = fitness_data[y+1].steps;
                fitness_data[y+1].steps = temp;
                check1 = 0;
            }
        }
    }
    fclose(file);
    char *file1name = "FitnessData_2023.csv.tsv";
    file = fopen(file1name , "w+");
    for (int y = 0 ; y < maxsize ; y++)
    {
        fprintf(file , "%s\t%s\t%d\n" , fitness_data[y].date , fitness_data[y].time , fitness_data[y].steps);
    }
    fclose(file);

    return(0);
}