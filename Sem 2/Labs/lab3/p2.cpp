// WAP to perform the addition of distance in the feet and inches format. Use
// objects as argument.
#include <iostream>
using namespace std;
class Distance
{
    int feet;
    int inches;
    public:
    Distance() {
        feet = 0;
        inches = 0;
    }
    Distance (int f, int i)
    {
        feet=f;
        inches=i;

    }
    Distance adddistance(Distance x, Distance y)
    {
        Distance z;
        z.inches=x.inches+y.inches;
        z.feet=x.feet+y.feet+z.inches/12;
        z.inches=z.inches%12;
        return z;

    }
    void display()
    {
        cout<<"Distance addition is "<<endl<<feet<<" f"<<endl<<inches<<" i"<<endl;
    }

};
int main()
{
    Distance d1( 12,13);
    Distance d2( 11,12);
    Distance d3=d3.adddistance(d1,d2);
    d3.display();
    return 0;
}