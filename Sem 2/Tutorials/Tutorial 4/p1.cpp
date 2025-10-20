// Write a program to read and write the information of 10 p1students in a file.Also modify the
// student information according to the given rollnumber.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int age;
    float marks;

    void input()
    {
        cout << "Roll: ";
        cin >> roll;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Age: ";
        cin >> age;
        cout << "Marks: ";
        cin >> marks;
    }

    void display()
    {
        cout << "Roll: " << roll
             << ", Name: " << name
             << ", Age: " << age
             << ", Marks: " << marks << endl;
    }

    void writeToFile(ofstream &outFile)
    {
        outFile << roll << '\n'
                << name << '\n'
                << age << '\n'
                << marks << '\n';
    }

    void readFromFile(ifstream &inFile)
    {
        inFile >> roll;
        inFile.ignore();
        getline(inFile, name);
        inFile >> age >> marks;
        inFile.ignore();
    }
};

int main()
{
    const string filename = "p1students.txt";
    Student s[10];

    ofstream outFile(filename);
    for (int i = 0; i < 10; i++)
    {
        cout << "\nStudent " << i + 1 << ":\n";
        s[i].input();
        s[i].writeToFile(outFile);
    }
    outFile.close();

    ifstream inFile(filename);
    cout << "\nAll Students:\n";
    for (int i = 0; i < 10; i++)
    {
        s[i].readFromFile(inFile);
        s[i].display();
    }
    inFile.close();

    int r;
    cout << "\nEnter roll number to modify: ";
    cin >> r;

    for (int i = 0; i < 10; i++)
    {
        if (s[i].roll == r)
        {
            cout << "Enter new details:\n";
            s[i].input();
            break;
        }
    }

    outFile.open(filename);
    for (int i = 0; i < 10; i++)
    {
        s[i].writeToFile(outFile);
    }
    outFile.close();

    cout << "\nAfter modification:\n";
    for (int i = 0; i < 10; i++)
    {
        s[i].display();
    }

    return 0;
}
