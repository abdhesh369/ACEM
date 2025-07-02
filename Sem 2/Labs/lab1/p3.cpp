// Write a program to read two numbers from user and display the largest number
// using the concept of OOP.
#include <iostream>
using namespace std;
class larger
{
private:
    float a, b;

public:
    void setnumber(float c, float d)
    {
        a = c;
        b = d;
    }

    int display()
    {
        cout << "The number are :"<<endl << a << "," << b << endl;
    }
    float findlargest()
    {
        if (a > b)
        {
            cout << "the largest number is :" << a;
        }
        else
            cout << "the largest number is :" << b;
    }
};
int main()
{
    larger l1;
    float x, y;
    cout << "enter two numbers :"<<endl;
    cin >> x >> y;
    l1.setnumber(x, y);
    l1.display();
    l1.findlargest();
    return 0;
}