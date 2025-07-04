// WAP to overload an increment operator (++) in prefix notation
#include <iostream>
using namespace std;
class count
{
    int x;
public:
count()
{
x=0;
}
count(int y)
{
x=y;
}
count operator++()
{
    ++x;
    return *this;
}
void display()
{
    cout<<x;
}
};

int main() {
    count a(12);
    ++a;
    a.display();

    return 0;
}
