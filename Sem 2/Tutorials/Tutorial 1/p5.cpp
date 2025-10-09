// Create a class mdistance to store the values in meter and centimeter and class edistance to store values in feet and inches.
// Perform addition of object of mdistance and object of edistance by using friend function.
#include <iostream>
#include <cmath>
using namespace std;
class edistance;
class mdistance
{
    float meter;
    float centimeter;

public:
    mdistance(float m = 0.0, float cm = 0.0)
    {
        meter = m;
        centimeter = cm;
    }
    void display()
    {
        cout << "meter :" << meter << endl
             << "centimeter" << " :" << centimeter << endl;
    }
    friend mdistance add(mdistance m, edistance e);
};
class edistance
{
    float feet;
    float inches;

public:
    edistance(float f = 0.0, float i = 0.0)
    {
        feet = f;
        inches = i;
    }
    friend mdistance add(mdistance m, edistance e);
};
mdistance add(mdistance m, edistance e)
{
    float totalcem = m.centimeter + m.meter * 100 + (e.feet * 30.48 + e.inches * 2.54);
    mdistance temp;
    temp.meter = totalcem / 100;
    temp.centimeter = fmod(totalcem, 100);
    return temp;
}

int main()
{
    int m;
    float cm;
    cout << "Enter distance in meters and centimeters: ";
    cin >> m >> cm;
    mdistance md(m, cm);

    int f;
    float in;
    cout << "Enter distance in feet and inches: ";
    cin >> f >> in;
    edistance ed(f, in);

    mdistance result = add(md, ed);
    result.display();
    return 0;
}
