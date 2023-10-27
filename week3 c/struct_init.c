#include <stdio.h>
#include <string.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    int mark;
};

int main () {
    struct student new_student ;
    char name [200];
    char student_id [11];
    int mark;

    printf("Enter student name\n");
    scanf("%s" , name);

    printf("Enter student ID\n");
    scanf("%s" , student_id);

    printf("Enter student mark\n");
    scanf("%d", &mark);

    strcpy(new_student.name , name);
    strcpy(new_student.student_id , student_id);
    new_student.mark = mark;

    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);


    return 0;
}