#include <iostream>
using namespace std;
class calculate
{

public:
    void cube(int num)
    {
        int a = num * num * num;
        cout << "The cube of " << num << " in int is: " << a << endl;
    }
    void cube(float num2)
    {
        float a = num2 * num2 * num2;
        cout << "The cube of " << num2 << "  in float is: " << a << endl;
    }
    void cube(double num3)
    {
        double a = num3 * num3 * num3;
        cout << "The cube of " << num3 << "  in double is: " << a << endl;
    }
};
int main()
{
    calculate c;
    int num;
    float num2;
    double num3;
    cout << "Enter numbers: ";
    cin >> num;
    cin >> num2;
    cin >> num3;
    c.cube(num);
    c.cube(num2);
    c.cube(num3);
    return 0;
}
