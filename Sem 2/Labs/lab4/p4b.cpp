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
        real = 0;
        img = 0;
    }
    complex(int x, int y)
    {
        real = x;
        img = y;
    }
    complex operator+(complex d)
    {
        complex e;
        e.real =real + d.real;
        e.img = img + d.img;
        return e;
    }
    void display()
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
