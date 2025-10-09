// Write a program to create a class that takes 10 data from user. Create two sets of objects from the class.
// Use a friend function that compares data from both the objects and display the list of the largest ones.
#include <iostream>
using namespace std;
class data
{
    int num[10];

public:
    void getdata()
    {
        cout << "Enter the 10 numbers" << endl;
        for (int i = 0; i < 10; i++)
        {
            cin >> num[i];
        }
    }
    friend void comparedata(data objone, data objtwo);
};
void comparedata(data objone, data objtwo)
{
    cout << "The largest one between two data" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (objone.num[i] > objtwo.num[i])
        {
            cout << objone.num[i] << endl;
        }
        else if (objone.num[i] < objtwo.num[i])
        {
            cout << objtwo.num[i] << endl;
        }
        else
        {
            cout << objtwo.num[i] << endl;
        }
    }
}
int main()
{
    data obj1, obj2;
    cout << "Enter the data for first object\n ";
    obj1.getdata();
    cout << "Enter the data for second object \n";
    obj2.getdata();
    comparedata(obj1, obj2);
    return 0;
}