// Write two overloaded functions named multiply :
//     multiply(int a, int b) → returns product of integers
//     multiply(double a, double b) → returns product of doubles
//     Test both functions in main()
#include <iostream>
using namespace std;

int multiply(int a, int b)
{
    return a * b;
}

double multiply(double a, double b)
{
    return a * b;
}

int main()
{
    int x, y;
    double m, n;

    cout << "Enter two integer values: ";
    cin >> x >> y;

    cout << "Enter two double values: ";
    cin >> m >> n;

    int r = multiply(x, y);
    double t = multiply(m, n);

    cout << "Product of integers: " << r << endl;
    cout << "Product of doubles: " << t << endl;

    return 0;
}