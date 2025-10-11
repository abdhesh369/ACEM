#include <iostream>
#include <cmath>
using namespace std;
class Distance
{
private:
    float feet;
    float inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }
    Distance(float f, float i)
    {
        feet = f;
        inches = i;
    }
    void getdata()
    {
        cout << "Enter the diatance in feets:" << endl;
        cin >> feet;
        cout << "Enter the diatance in inches:" << endl;
        cin >> inches;
    }

    void operator+=(Distance d)
    {
        feet += d.feet;
        inches += d.inches;

        if (inches >= 12.0)
        {
            feet += int(inches / 12);
            inches = fmod(inches, 12);
        }
    }
    void display()
    {
        cout << "Feet: " << feet <<" f"<< endl
             << "inches: " << inches<<" i";
    }
};
int main()
{
    Distance d1, d2;
    cout << "**Enter first data #" << endl;
    d1.getdata();
    cout << "**Enter second  data #" << endl;
    d2.getdata();
    d1 += d2;
    d1.display();
    return 0;
}
