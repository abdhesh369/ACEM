// Write a program that can store Department ID and Departrnent name with constructor. Also write destructor
//  in the same class and show that objects are destroyed in reverse order of creation with suitable message
#include <iostream>
using namespace std;

class department
{
    int id;
    string name;

public:
    department(int x = 0, string xx = "xxx")
    {
        id = x;
        name = xx;

        cout << "id :" << id << endl
             << "name of department :" << name << endl;
    }
    ~department()
    {
        cout << "destructor is called" << endl;

        cout << "id :" << id << endl
             << "name of department :" << name << endl;
    }
};
int main()
{
    department d1(111, "science");
    department d2(222, "math");
    department d3(333, "electronic");
    return 0;
}