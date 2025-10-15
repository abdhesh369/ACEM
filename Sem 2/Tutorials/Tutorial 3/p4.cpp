#include <iostream>
#include <cmath> // for M_PI
using namespace std;

class Shape
{
protected:
    int radius;

public:
    Shape(int r = 0)
    {
        radius = r;
    }

    void setRadius(int r)
    {
        radius = r;
    }

    int getRadius()
    {
        return radius;
    }
};

class Circle : public Shape
{
public:
    Circle(int r = 0) : Shape(r) {}

    double area()
    {
        return M_PI * radius * radius;
    }
};

class Sphere : public Shape
{
public:
    Sphere(int r = 0) : Shape(r) {}

    double surfaceArea()
    {
        return 4 * M_PI * radius * radius;
    }
};

int main()
{
    int r;

    cout << "Enter radius: ";
    cin >> r;

    Circle c(r);
    Sphere s(r);

    cout << "Area of Circle: " << c.area() << endl;
    cout << "Surface Area of Sphere: " << s.surfaceArea() << endl;

    return 0;
}
