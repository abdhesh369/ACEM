// Create a class Person, create 2 derived classes Employee and Student inherited from class Person.
// Now create a class Manager which is derived from 2 base classes Employee and Student.Show the use of virtual class,
//  virtual function, virtual destructor, order of invocation of constructor.
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n = "Unknown", int a = 0)
    {
        name = n;
        age = a;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl
             << " Age: " << age << endl;
    }

    virtual ~Person()
    {
        cout << "Person destructor called\n";
    }
};

class Employee : virtual public Person
{
protected:
    int empID;

public:
    Employee(string n = "Unknown", int a = 0, int id = 0) : Person(n, a)
    {
        empID = id;
    }

    void display() override
    {
        cout << "[Employee]" << endl;
        Person::display();
        cout << "Employee ID: " << empID << endl;
    }

    ~Employee()
    {
        cout << "Employee destructor called\n";
    }
};

class Student : virtual public Person
{
protected:
    int rollNo;

public:
    Student(string n = "Unknown", int a = 0, int r = 0) : Person(n, a)
    {
        rollNo = r;
    }

    void display() override
    {
        cout << "[Student]" << endl;
        Person::display();
        cout << "Roll Number: " << rollNo << endl;
    }

    ~Student()
    {
        cout << "Student destructor called\n";
    }
};

class Manager : public Employee, public Student
{
    string department;

public:
    Manager(string n, int a, int id, int r, string dept) : Person(n, a), Employee(n, a, id), Student(n, a, r)
    {
        department = dept;
    }

    void display() override
    {
        cout << "[Manager]" << endl;
        Person::display();
        cout << "Employee ID: " << empID << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Department: " << department << endl;
    }

    ~Manager()
    {
        cout << "Manager destructor called\n";
    }
};

int main()
{
    Manager m("Abdhesh", 22, 101, 501, "IT Department");

    cout << "\n=== Display Info (using virtual function) ===" << endl;
    Person *ptr = &m;
    ptr->display();

    cout << "\n=== Object Destruction ===" << endl;

    return 0;
}
