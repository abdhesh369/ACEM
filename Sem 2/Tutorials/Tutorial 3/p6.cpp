#include <iostream>
using namespace std;

class Shape
{
protected:
    string name;

public:
    Shape(string n = "Unknown Shape")
    {
        name = n;
    }

    virtual void area() = 0;

    virtual void display()
    {
        cout << "Shape: " << name << endl;
    }
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r = 0) : Shape("Circle")
    {
        radius = r;
    }

    void area() override
    {
        float a = 3.1416 * radius * radius;
        cout << "Area of Circle: " << a << endl;
    }

    void display() override
    {
        cout << "Shape: " << name << endl;
        cout << "Radius: " << radius << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, breadth;

public:
    Rectangle(float l = 0, float b = 0) : Shape("Rectangle")
    {
        length = l;
        breadth = b;
    }

    void area() override
    {
        float a = length * breadth;
        cout << "Area of Rectangle: " << a << endl;
    }

    void display() override
    {
        cout << "Shape: " << name << endl;
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
    }
};

class Trapezoid : public Shape
{
private:
    float base1, base2, height;

public:
    Trapezoid(float b1 = 0, float b2 = 0, float h = 0) : Shape("Trapezoid")
    {
        base1 = b1;
        base2 = b2;
        height = h;
    }

    void area() override
    {
        float a = 0.5 * (base1 + base2) * height;
        cout << "Area of Trapezoid: " << a << endl;
    }

    void display() override
    {
        cout << "Shape: " << name << endl;
        cout << "Base1: " << base1 << ", Base2: " << base2 << ", Height: " << height << endl;
    }
};

int main()
{
    Shape *s;

    Circle c(5);
    Rectangle r(4, 6);
    Trapezoid t(3, 5, 4);

    s = &c;
    s->display();
    s->area();
    cout << endl;

    s = &r;
    s->display();
    s->area();
    cout << endl;

    s = &t;
    s->display();
    s->area();

    return 0;
}
