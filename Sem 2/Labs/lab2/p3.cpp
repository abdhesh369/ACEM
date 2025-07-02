// Assume that employee will have to pay 10 percent income tax to the
// government. Ask user to enter the employee salary. Use inline function to
// display the net payment to the employee by the company.
#include <iostream>
using namespace std;
class company
{
private:
    float netsalary;
    float tax;

public:
   inline float salary(int x)
    {
        tax = 0.1 * x;
        return netsalary=x-tax;
    }
};
int main()
{
    company c;
    int Salary;
    cout<<"Enter your salary before tax"<<endl;
    cin>>Salary;
    float netincome=c.salary(Salary);
    cout <<"salary after tax :"<<netincome;
    return 0;
}

