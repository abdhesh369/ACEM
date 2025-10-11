// Create a class called Length that has data members meter and centimeter.
// Overload operator to add two objects of class Length (For example L3 = L1 + L2)
// Also facilitate the operations like L4 = L1 + 5 and L5 = 5 + L4
// Use constructors and member functions to initialize and display values.

#include <iostream>
using namespace std;

class Length
{
    int meter;
    int centimeter;

public:
    Length()
    {
        meter = 0;
        centimeter = 0;
    }

    Length(int m, int cm)
    {
        meter = m;
        centimeter = cm;
        normalize();
    }

    void getlength()
    {
        cout << "Enter meter: ";
        cin >> meter;
        cout << "Enter centimeter: ";
        cin >> centimeter;
        normalize();
    }

    void normalize()
    {
        if (centimeter >= 100)
        {
            meter += centimeter / 100;
            centimeter = centimeter % 100;
        }
    }

    Length operator+(Length l)
    {
        Length temp;
        temp.meter = meter + l.meter;
        temp.centimeter = centimeter + l.centimeter;
        temp.normalize();
        return temp;
    }

    Length operator+(int x)
    {
        Length temp;
        temp.meter = meter;
        temp.centimeter = centimeter + x;
        temp.normalize();
        return temp;
    }

    friend Length operator+(int x, const Length &l);

    void display() const
    {
        cout << meter << " meter " << centimeter << " centimeter" << endl;
    }
};

Length operator+(int x, const Length &l)
{
    Length temp;
    temp.meter = l.meter;
    temp.centimeter = l.centimeter + x;
    temp.normalize();
    return temp;
}

int main()
{
    Length L1, L2, L3, L4, L5;
    int x;

    cout << "Enter first length:\n";
    L1.getlength();

    cout << "\nEnter second length:\n";
    L2.getlength();

    cout << "\nEnter an integer to add: ";
    cin >> x;

    L3 = L1 + L2; 
    L4 = L1 + x;  
    L5 = x + L4;  

    cout << "\nResult (L3 = L1 + L2): ";
    L3.display();

    cout << "Result (L4 = L1 + " << x << "): ";
    L4.display();

    cout << "Result (L5 = " << x << " + L4): ";
    L5.display();

    return 0;
}
