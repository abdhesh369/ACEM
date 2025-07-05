// WAP to convert Time expressed in minute and second into single value hour.
#include <iostream>
using namespace std;
class Time
{
private:
    float hours;

public:
    Time(float min, float sec)
    {
        hours = (min / 60 )+( sec / 3600);
    }
    void display()
    {
        cout << "Hours= " << hours << endl;
    }
};
int main()
{
    Time t(120,3600);
    t.display();
};