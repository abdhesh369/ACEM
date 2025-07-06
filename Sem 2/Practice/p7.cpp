#include <iostream>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    virtual void showInfo() = 0;  // Pure virtual function
};

class Student : virtual public Person {
protected:
    int roll;

public:
    Student(string n, int r) : Person(n) {
        roll = r;
    }
};

class Employee : virtual public Person {
protected:
    int emp_id;

public:
    Employee(string n, int id) : Person(n) {
        emp_id = id;
    }
};

class Assistant : public Student, public Employee {
public:
    Assistant(string n, int r, int id) : Person(n), Student(n, r), Employee(n, id) {}

    void showInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll << endl;
        cout << "Employee ID: " << emp_id << endl;
    }
};

int main() {
    Assistant a("Abdhesh", 101, 5551);
    a.showInfo();
    return 0;
}
