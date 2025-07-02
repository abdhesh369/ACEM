// Write a function that passes two temperatures by reference and sets the larger
// of the two numbers to 100 by using return by reference
#include <iostream>
using namespace std;
class temperature
{
private:
    float x, y;

public:
    int &setTohundred(int &x, int &y)
    {
        if (x > y)
        {
            x = 100;
            return x;
        }
        else
        {
            y = 100;
            return y;
        }
    }
};
int main()
{
    temperature t;
    int temp1 = 99, temp2 = 50;
    t.setTohundred(temp1, temp2);
    t.setTohundred(temp1, temp2) = 777;

    cout << temp1 << endl;
    cout << temp2 << endl;
}