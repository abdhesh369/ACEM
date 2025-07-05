// Create a class named Centigrade and another class name Fahrenheit. Write a
// program to convert object of Centigrade class into object of another class
// Fahrenheit.
// i. Define the conversion routine in source class.
// ii. Define the conversion routine in destination class
// (For centigrade to Fahrenheit conversion, multiply by 9, then divide by 5, then add 32)
#include <iostream>
using namespace std;
class Fahrenheit;
class Centigrade
{
    float celsius;

public:
    Centigrade()
    {
        celsius = 0;
    }
    Centigrade(float x)
    {
        celsius = x;
    }
    float getCelsius()
    {
        return celsius;
    }
    void display()
    {
        cout << "Celsius is= " << celsius << "'C" << endl;
    }
};
class Fahrenheit
{
    float fahr;

public:
    Fahrenheit()
    {
        fahr = 0;
    }
    Fahrenheit(Centigrade c)
    {
        fahr = (c.getCelsius() * 9.0f / 5.0f) + 32.0f;
    }
    void display()
    {
        cout << "Fahrenheit is= " << fahr << "'f" << endl;
    }
};
int main()
{
    Fahrenheit f;
    Centigrade c(100);
    c.display();
    f = c;
    f.display();
}