#include <iostream>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks;

public:
    // Default Constructor
    Student() {
        roll = 0;
        name = "";
        marks = 0.0;
    }

    // Input function
    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();  // To clear newline from buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // Display function
    void display() {
        cout << "\nRoll Number: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }
};

int main() {
    Student s[5]; // Array of 5 student objects

    cout << "=== Enter Student Records ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        s[i].input();
    }

    cout << "\n=== Displaying Student Records ===\n";
    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        s[i].display();
    }

    return 0;
}