// Write a recursive function to calculate the nth Fibonacci number.
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Fibonacci is not defined for negative numbers." << endl;
        return 1;
    }

    cout << "Fibonacci = " << fibonacci(n) << endl;
    return 0;
}