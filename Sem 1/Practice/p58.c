// Write a program to create a file named ‘student.txt’ and write name, roll, address and
// marks of a student to a file.
#include <stdio.h>

struct student
{
    char name[100];
    int roll;
    char address[100];
    float marks;
};

int main()
{
    struct student s;
 
    FILE *std;
    std = fopen("student.txt", "w");
    if (std == NULL)
    {
        printf("Error in opening file\n");
        return 1;
    }
    printf("Enter student name: ");
    fgets(s.name, sizeof(s.name), stdin);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter address: ");
    scanf(" %[^\n]", s.address);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fprintf(std, "Name of student %s \n", s.name);
    fprintf(std, "Roll number of student %d \n", s.roll);
    fprintf(std, "Address of student %s \n", s.address);
    fprintf(std, "Marks of student %f \n", s.marks);

    fclose(std);
    printf(" Data Recorded ");

    return 0;
}
