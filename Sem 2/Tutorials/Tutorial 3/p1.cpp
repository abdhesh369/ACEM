#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int id;

public:
    void getdata()
    {
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee ID: ";
        cin >> id;
    }

    void putdata()
    {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }
};

class Manager : public Employee
{
    string department;

public:
    void getdata()
    {
        Employee::getdata();
        cin.ignore();
        cout << "Enter Department Name: ";
        getline(cin, department);
    }

    void putdata()
    {
        Employee::putdata();
        cout << "Department: " << department << endl;
    }
};

class ComputerOperator : public Employee
{
    float typing_speed;

public:
    void getdata()
    {
        Employee::getdata();
        cout << "Enter Typing Speed (words per minute): ";
        cin >> typing_speed;
    }

    void putdata()
    {
        Employee::putdata();
        cout << "Typing Speed: " << typing_speed << " wpm" << endl;
    }
};

int main()
{
    cout << "------ Manager Details ------" << endl;
    Manager m1;
    m1.getdata();

    cout << "\n------ Computer Operator Details ------" << endl;
    ComputerOperator c1;
    c1.getdata();

    cout << "\n===== Displaying Details =====\n";

    cout << "\nManager Information:" << endl;
    m1.putdata();

    cout << "\nComputer Operator Information:" << endl;
    c1.putdata();

    return 0;
}
