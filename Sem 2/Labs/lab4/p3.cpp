// WAP to overload unary minus operator using friend function.
#include <iostream>
using namespace std;
class Number
{
    int y;

public:
    Number()
    {
        y = 0;
    }
    Number(int x)
    {
        y = x;
    }
    friend Number operator-(Number f);
    void display();
};

Number operator-(Number f)
{
    f.y = -f.y;
    return f;
}

void Number::display()
{
    cout << "Number after minus : " << y << endl;
}
int main()
{
    Number n(-12);
    Number result = -n;
    result.display();
}
