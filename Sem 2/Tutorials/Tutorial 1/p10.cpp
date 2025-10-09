// Create a class College which has data of student's name, id, marks.
// Create another class Company which is a friend of class College.
//  Get the students' details for 20 students. Class Company should be able to identify
//  the student who scored marks more than 80% and eligible to get internship. Finally print the details
//  of the students who are eligible for internship in the company.
#include <iostream>
using namespace std;
class company;
class collage
{
private:
    string name;
    int id;
    int marks;

public:
    void getdata()
    {
        cin.ignore();
        cout << "Enter the name of student" << endl;
        getline(cin, name);
        cout << "Enter the id of student" << endl;
        cin >> id;
        cout << "Enter the marks of student" << endl;
        cin >> marks;
    }
    void display()
    {
        cout << "\nThe name of student: " << name << endl;
        cout << "\nThe id of student :" << id << endl;
        cout << "\nThe marks of student :" << marks << endl;
    }
    friend class company;
};
class company
{
public:
    void eligibleStudents(int n, collage c[])
    {
        cout << "\n--- Students Eligible for Internship (Marks > 80%) ---\n";
        for (int i = 0; i < n; i++)
        {
            if (c[i].marks > 80)
            {
                c[i].display();
            }
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of student" << endl;
    cin >> n;
    collage c[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Enter details of student " << i + 1 << " ---\n";
        c[i].getdata();
    }
    company com;
    com.eligibleStudents(n, c);
    return 0;
}