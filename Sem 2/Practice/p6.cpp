#include <iostream>
using namespace std;
int main()
{
    int p,t,r;
    float si;
    cout << "Enter the value of principal amount,rate and time:\n ";
    cin>>p>>t>>r;
    si=(p*t*r)/100;
    cout<<"simple interest is:"<<si;
    return 0;
}