#include <iostream>
#include <string>
using namespace std;

class Lecturer
{
protected:
    int id;
    string name;

public:
    void readdata()
    {
        cout << "Enter Lecturer ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Lecturer Name: ";
        getline(cin, name);
    }

    void printdata()
    {
        cout << "Lecturer ID: " << id << endl;
        cout << "Lecturer Name: " << name << endl;
    }
};

class PartTime : public Lecturer
{
private:
    float pay_per_hour;

public:
    void readdata()
    {
        Lecturer::readdata();
        cout << "Enter Pay Per Hour: ";
        cin >> pay_per_hour;
    }

    void printdata()
    {
        Lecturer::printdata();
        cout << "Pay Per Hour: " << pay_per_hour << endl;
    }
};

class FullTime : public Lecturer
{
private:
    float pay_per_month;

public:
    void readdata()
    {
        Lecturer::readdata();
        cout << "Enter Pay Per Month: ";
        cin >> pay_per_month;
    }

    void printdata()
    {
        Lecturer::printdata();
        cout << "Pay Per Month: " << pay_per_month << endl;
    }
};

int main()
{
    cout << "------ Enter Full-Time Lecturer Details ------" << endl;
    FullTime f1;
    f1.readdata();

    cout << "\n------ Enter Part-Time Lecturer Details ------" << endl;
    PartTime p1;
    p1.readdata();

    cout << "\n===== Lecturer Details =====\n";

    cout << "\nFull-Time Lecturer:\n";
    f1.printdata();

    cout << "\nPart-Time Lecturer:\n";
    p1.printdata();

    return 0;
}
