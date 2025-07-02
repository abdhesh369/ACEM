// Write a simple program that convert the temperature in degree centigrade to
// degree Fahrenheit and vice-versa using the basic concept of classes and
// objects. Make separate class for centigrade and Fahrenheit which have the
// private member to hold the values and add conversion function in each class
// from centigrade to Fahrenheit
#include <iostream>
using namespace std;
class centigrade
{
private:
    float celc;

public:
    centigrade()
    {
        celc = 0;
    }
    centigrade(float x)
    {
        celc = x;
    }
    float toFahrenheit()
    {
        return (celc * 9.0 / 5.0) + 32;
    }
    void display()
    {
        float f =toFahrenheit();
        cout << "Celsius: " << celc << endl;
        cout << "fahrenheit: " << f << endl;
    }
};
class Fahrenheit
{
private:
    float fahr;

public:
    Fahrenheit()
    {
     fahr = 0;
    }
    Fahrenheit(float x)
    {
     fahr = x;
    }
    float toCelcus()
    {
        return (fahr - 32) * 5.0 / 9.0;
    }
    void display()
    {
        float f =toCelcus();
        cout << "fahrenheit: " << fahr << endl;
        cout << "Celsius: " << f << endl;
    }
};
int main()
{
    centigrade c(35);
    Fahrenheit f(330);
    c.display();
    f.display();
}