#include <iostream>
#include <string>
using namespace std;

// Base class
class Cricketer
{
protected:
    string name;
    int age;
    int no_of_matches;

public:
    void readData()
    {
        cin.ignore();
        cout << "Enter Cricketer Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Number of Matches Played: ";
        cin >> no_of_matches;
    }

    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Matches Played: " << no_of_matches << endl;
    }
};

class Bowler : public Cricketer
{
private:
    int no_of_wickets;

public:
    void readData()
    {
        Cricketer::readData();
        cout << "Enter Number of Wickets: ";
        cin >> no_of_wickets;
    }

    void displayData()
    {
        Cricketer::displayData();
        cout << "Wickets Taken: " << no_of_wickets << endl;
    }
};

class Batsman : public Cricketer
{
private:
    int no_of_runs;
    int centuries;

public:
    void readData()
    {
        Cricketer::readData();
        cout << "Enter Number of Runs: ";
        cin >> no_of_runs;
        cout << "Enter Number of Centuries: ";
        cin >> centuries;
    }

    void displayData()
    {
        Cricketer::displayData();
        cout << "Runs Scored: " << no_of_runs << endl;
        cout << "Centuries: " << centuries << endl;
    }
};

int main()
{
    cout << "------ Enter Bowler Details ------" << endl;
    Bowler b1;
    b1.readData();

    cout << "\n------ Enter Batsman Details ------" << endl;
    Batsman bats1;
    bats1.readData();

    cout << "\n===== Displaying Player Details =====\n";

    cout << "\nBowler Information:\n";
    b1.displayData();

    cout << "\nBatsman Information:\n";
    bats1.displayData();

    return 0;
}
