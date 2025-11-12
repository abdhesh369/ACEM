// Write a program to read name and roll number of 48 students from user and store them in
// file. If the file already contains data, your program should add new data at the end of the
// file.
#include <stdio.h>

int main()
{
    char name[50];
    int roll;

    FILE *file;
    file = fopen("student.txt", "a");
    if (!file)
    {
        printf("Error in opening file:\n");
        return 1;
    }
    for (int i = 1; i <= 48; i++)
    {
        printf("Enter the roll number of student %d \n", i);
        scanf("%d", &roll);
        printf("Enter the name of student %d\n", i);
        scanf(" %[^\n]", name);


        
        fprintf(file, "The roll number of student %d is: %d\n", i, roll);
        fprintf(file, "The name of student %d: %s\n", i, name);
    }
    fclose(file);
    printf("Data updated:");
    return 0;
}
