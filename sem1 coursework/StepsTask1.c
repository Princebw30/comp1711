#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[100];
} FITNESS_DATA;

// Define any additional variables here


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) 
{
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() 
{
    char filename[] = "FitnessData_2023.csv";
    FILE *file = fopen(filename , "r" );

    FITNESS_DATA fitness_data1;
    FITNESS_DATA fitness_data2;
    FITNESS_DATA fitness_data3;

    int count = 0;
    int line_limit = 3;

    int buffer_size = 500;
    char line_buffer[buffer_size];
    while(fgets(line_buffer,buffer_size,file) != NULL)
    {
        count++;
        if(count==1)
        {
            tokeniseRecord(line_buffer , "," , fitness_data1.date , fitness_data1.time , fitness_data1.steps);
        }
        else if (count ==2)
        {
            tokeniseRecord(line_buffer , "," , fitness_data2.date , fitness_data2.time , fitness_data2.steps);
        }
        else if (count == 3)
        {
            tokeniseRecord(line_buffer , "," , fitness_data3.date , fitness_data3.time , fitness_data3.steps);
        }
    }
    printf("Number of records in file: %d\n" , count);
    printf("%s/%s/%d\n" , fitness_data1.date , fitness_data1.time , atoi(fitness_data1.steps));
    printf("%s/%s/%d\n" , fitness_data2.date , fitness_data2.time , atoi(fitness_data2.steps));
    printf("%s/%s/%d\n" , fitness_data3.date , fitness_data3.time , atoi(fitness_data3.steps));
        

    

    

}
