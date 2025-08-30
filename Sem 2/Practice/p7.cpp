#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("students.txt");  // open file for writing

    int n;
    cout << "How many students? ";
    cin >> n;
    cin.ignore();  // clear newline from input buffer

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Enter name of student " << (i+1) << ": ";
        getline(cin, name);
        cout << "Enter age of student " << (i+1) << ": ";
        cin >> age;
        cin.ignore(); // clear newline before next getline

        outFile << name << endl;  // write name
        outFile << age << endl;   // write age
    }


    ifstream inFile("students.txt");  // open file for reading
    if (!inFile) {
        cout << "File not found!\n";
        return 1;
    }

    string name;
    int age;
    int studentNo = 1;

    cout << "\nReading data from file:\n";

    while (getline(inFile, name)) {      // read name
        inFile >> age;                    // read age
        inFile.ignore();                  // clear newline
        cout << "Student " << studentNo << ": " << name << ", Age: " << age << endl;
        studentNo++;
    }

    inFile.close();
    return 0;
}

