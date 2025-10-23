// Write code to find and print the factorial of a number using a for loop
#include <iostream>
using namespace std;

int main()
{
    int x;
    unsigned long long y = 1;

    cout << "Enter the number: ";
    cin >> x;

    if (x < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    for (int i = 1; i <= x; i++)
    {
        y *= i;
    }

    cout << "The factorial of " << x << " is: " << y << endl;
    return 0;
}