// Create a class first with data member data1 and another class second with data
// member data2. Display the largest number. Use friend function.
#include <iostream>
using namespace std;
class second;
class First
{

    int data1;

public:
    friend void display(First f, second s);
    First()
    {
        data1 = 0;
    }
    First(int x)
    {
        data1 = x;
    }
};
class second
{

    int data2;

    friend void display(First f, second s);

public:
    second()
    {
        data2 = 0;
    }
    second(int y)
    {
        data2 = y;
    }
};
void display(First f, second s)
{
    if (f.data1 > s.data2)
    {
        cout << "largest number " << f.data1;
    }
    else
    {
        cout << "largest number " << s.data2;
    }
}
int main()
{
    First f;
    second s = (88,77);
    display(f, s);
    return 0;
}
