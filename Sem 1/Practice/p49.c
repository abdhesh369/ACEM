#include <stdio.h>
#include <string.h>
struct Student
{
    char name[30];
    int age;
    int mark;
};
void sortbyname(int x, struct Student s[x])
{
    struct Student temp;
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (strcmp(s[j].name, s[j + 1].name) > 0)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void sortbyage(int x, struct Student s[x])
{
    struct Student temp;
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (s[j].age > s[j + 1].age)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void sortbymark(int x, struct Student s[x])
{
    struct Student temp;
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - i - 1; j++)
        {
            if (s[j].mark < s[j + 1].mark)
            {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
void printdetail(int x, struct Student s[x])
{
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < x; i++)
    {
        printf("%-20s  %-5d  %-5d\n", s[i].name, s[i].age, s[i].mark);
    }
}
int main()
{
    int n;
    printf("Enter the number of students\n");
    scanf("%d", &n);
    struct Student s[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of student %d\n", i + 1);
        getchar();
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = '\0';
        printf("Enter the age of student %d\n", i + 1);
        scanf("%d", &s[i].age);
        printf("Enter the toatal mark of student %d\n", i + 1);
        scanf("%d", &s[i].mark);
    }
    int choice;
    printf("How you want to sort:\n1.By name\n2.By age\n3.By mark\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:

        sortbyname(n, s);
        break;

    case 2:
        sortbyage(n, s);
        break;
    case 3:
        sortbymark(n, s);
        break;
    default:
        break;
    }

    printdetail(n, s);
    return 0;
}
