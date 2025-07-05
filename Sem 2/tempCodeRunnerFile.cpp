// WAP to overload plus operator to add two complex number with out using friend function
#include <iostream>
using namespace std;
class complex
{
    int real;
    int img;

public:
    complex()
    {
        int real = 0;
        int img = 0;
    }
    complex(int x, int y)
    {
        real = x;
        img = y;
    }
    complex operator+(complex c, complex d)
    {
        complex e;
        e.real = d.real + c.real;
        e.img = d.img + c.img;
        return e;
    }
    void complex :: display()
    {
        cout << "complex number is: " << real << "+" << img << "i" << endl;
    }
};
int main()
{
    int num1, num2;
    complex a(2, 4), b(2, 4), c;
    c = a + b;
    c.display();
    return 0;
}