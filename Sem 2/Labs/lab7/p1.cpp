
#include <iostream>
#include <string>
using namespace std;
class university
{
    string name;

public:
    void getuname()
    {
        cout << "  Enter the name of university" << endl;
        getline(cin, name);
    }
    void displayu()
    {
        cout << "The university name is " << name << endl;
    }
};
class faculty : public university
{
    string namef;

public:
    void getfname()
    {
        cout << "  Enter the name of faculty" << endl;
        getline(cin, namef);
    }
    void displayf()
    {
        cout << "The faculty name is " << namef << endl;
    }
};
class lecturer : public faculty
{
    string namel;

public:
    void getlname()
    {
        cout << "  Enter the name of lecturer" << endl;
        getline(cin, namel);
    }
    void displayl()
    {
        cout << "The  lecturer name is " << namel << endl;
    }
};
int main()
{
    cout << endl;
    lecturer l;
    l.getuname();
    l.getfname();
    l.getlname();
    cout << endl;
    l.displayu();
    l.displayf();
    l.displayl();
}