// Write a program to calculate the area and perimeter of a rectangle by using the
// concept of OOP
#include <iostream>
using namespace std;
class calculate
{
    float Area, Perimeter;
    public:
    void area(float l , float b)
    {
        Area=l*b;
        cout<< "Area of rectangle :"<<Area <<endl;
    }
    void perimeter(float l , float b)
    {
        Perimeter=2*(l+b);
        cout<< "perimeter of rectangle :"<< Perimeter <<endl;
    }
};
int main()
{
    calculate c;
    float l=4 , b=5;
    c.perimeter(l,b);
    c.area(l,b);
    
    return 0;
}

