// WAP to show operator function returns object of type complex.
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
    complex operator+(complex c)
    {
        complex d;
        d.real = real + c.real;
        d.img = img + c.img;
        return d;
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
