// Write two functions with the same name printMessage in two different namespaces
// Call both functions from main()

#include <iostream>
using namespace std;
namespace t
{
    void printMessage()
    {
        cout << "This is first function!!" << endl;
    }
}
namespace x
{
    void printMessage()
    {
        cout << "This is second function!!";
    }
}
int main()
{
    t::printMessage();
    x::printMessage();
    return 0;
}
