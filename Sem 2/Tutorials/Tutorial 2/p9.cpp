// write a program to overload the relational operators to compare the Length(in meter and centimeter) of two objects.
#include <iostream>
using namespace std;
class Length
{
private:
    int meter;
    int centimeter;

public:
    Length(int m = 0, int cm = 0)
    {
        meter = m;
        centimeter = cm;
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
    void getdata()
    {
        cout << "Enter the meter:" << endl;
        cin >> meter;
        cout << "Enter the centimeter:" << endl;
        cin >> centimeter;
        normalize();
    }
    int totalcm() const
    {
        return meter * 100 + centimeter;
    }

    bool operator==(const Length &l) const
    {
        return totalcm() == l.totalcm();
    }

    bool operator<(const Length &l) const
    {
        return totalcm() < l.totalcm();
    }

    bool operator>(const Length &l) const
    {
        return totalcm() > l.totalcm();
    }
};
int main()
{
    Length l1, l2, l3;

    cout << "Enter the first data:" << endl;
    l1.getdata();
    cout << "Enter the second data:" << endl;
    l2.getdata();
    if (l1 > l2)
        cout << "Length 1 is greater than Length 2" << endl;
    else if (l1 < l2)
        cout << "Length 1 is less than Length 2" << endl;
    else if (l1 == l2)
        cout << "Both lengths are equal" << endl;

    return 0;
}