// Write a program to read the information of a file named "data.txt" and write its contents to another file "record.txt".
#include <stdio.h>
int main()
{
    char line[100];
    FILE *file, *file1;
    file = fopen("data.txt", "r");
    if (!file)
    {
        printf("Error in opening file data.txt:\n");
        return 1;
    }

    file1 = fopen("record.txt", "w");
    if (!file1)
    {
        printf("Error in opening file record.txt:\n");
        return 1;
    }
    while (fgets(line, sizeof(line), file) != NULL)
    {
        fprintf(file1, "%s", line);
    }
    fclose(file1);
    fclose(file);

    return 0;
}
