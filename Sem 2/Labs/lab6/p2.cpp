//  Develop a complete program for an institution, which wishes to maintain a
// database of its staff. The database is divided into number of classes whose
// hierarchical relationship is shown in the following diagram. Specify all the
// classes and define constructors and function to create database and retrieve the
// individual information as per the requirement.
#include <iostream>
#include <string>
using namespace std;
class STAFF
{
    int staff_id;

public:
    STAFF(int x)
    {
        staff_id = x;
    }
    void displaystaff()
    {
        cout << "staff id is : " << staff_id << endl;
    }
};
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class LECTURER : public STAFF
{
    string subject;

public:
    LECTURER(int id, string y = "not lecturer") : STAFF(id)
    {
        subject = y;
    }
    void displaylecturer()
    {
        cout << "S/He teaches : " << subject << endl;
    }
};
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

class ADMIN : public STAFF
{
    string post_department;

public:
    ADMIN(int id, string z="Fired") : STAFF(id)
    {
        post_department = z;
    }
    void displayadmin ()
    {
        cout<<"S/He is : " <<post_department<<endl;
    }
};
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

class LIBRARIAN : public STAFF
{
    string shift;

public:
    LIBRARIAN(int id, string l) : STAFF(id)
    {
        shift = l;
    }
    void displaylibrarian ()
    {
        cout<<"shift : " <<shift<<endl;
    }
};
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

int main()
{
    cout<<endl;
    cout<<"lecturer info"<<endl;
    LECTURER l(1);
    l.displaystaff();
    l.displaylecturer();
    
    cout<<endl;
    cout<<"Admin info"<<endl;
    ADMIN a(2, "Head of Department");
    a.displaystaff();
    a.displayadmin();
    // ADMIN b(2);
    // b.displaystaff();
    // b.displayadmin();
    
    cout<<endl;
    cout<<"librarian info"<<endl;
    LIBRARIAN li(3, "Morning");
    li.displaystaff();
    li.displaylibrarian();

    return 0;
}