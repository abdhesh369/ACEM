//  Write a program to show the use of virtual base class and pure virtual function
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class staff
{   
public:
void virtual info();
};
class Admin : virtual public staff
{   
public:
void virtual info();
};
class Teacher :virtual public staff
{   
public:
void virtual info();
};
class asistance: public Admin, public Teacher
{   
public:
void virtual info();
};


int main() 
{

    return 0;
}