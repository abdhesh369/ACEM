// Write a program to find the area of a rectangle by passing length and breadth
// as arguments after creating member function in both derived and base class
// with the same name.
#include <iostream>
using namespace std;
class base
{
    public:
int area(int length,int breath)
{
   int areabase= length *breath;

}

};
class Derived: public base
{
    public:
int area(int length,int breath)
{
   int areaderived= length *breath;

}

};

int main() {

    return 0;
}