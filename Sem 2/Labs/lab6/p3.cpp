// Write a program to find the area of a rectangle by passing length and breadth
// as arguments after creating member function in both derived and base class
// with the same name.
#include <iostream>
using namespace std;
class Base
{
public:
    int area(int length, int breath)
    {
        int areabase = length * breath;
        cout << "area of rectangle by base class  is :" << areabase << endl;
    }
};
class Derived : public Base
{
public:
    int area(int length, int breath)
    {
        int areaderived = length * breath;
        cout << "area of rectangle  by derived class is :" << areaderived << endl;
    }
};

int main()
{
    Derived d;
    int length, breath;
    cout << "enter the length of rectangle: " << endl;
    cin >> length;
    cout << "enter the breath of rectangle: " << endl;
    cin >> breath;
    d.area(length, breath);
    d.Base::area(length, breath);

    return 0;
}