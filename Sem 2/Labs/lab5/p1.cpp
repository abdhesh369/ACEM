// WAP to convert hour into object of a class Time which has minute and second as members
#include <iostream>
using namespace std;
class Time
{
private:
    float min;
    float sec;

public:
    Time(float hours)
    {
        min = hours * 60;
        sec = hours * 3600;
    }
    void display()
    {
        cout << "Minute= " << min << endl
             << "Second= " << sec << endl;
    }
};
int main()
{
    Time t(12.5);
    t.display();
};