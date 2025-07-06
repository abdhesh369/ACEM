//  Write a program to show the use of virtual base class and pure virtual function
#include <iostream>
using namespace std;

class staff
{
protected:
    string name;

public:
    staff(string n)
    {
        name = n;
    }
virtual void showinfo() = 0;
};

//::::::::::::::::::::::::::::::::::::::::

class Admin : virtual public staff

{
protected:
    int id;

public:
    Admin(string n, int i) : staff(n)
    {
        id = i;
    }
};

//:::::::::::::::::::::::::::::::::::::::::::::::::::

class Teacher : virtual public staff
{
protected:
    int id_card;

public:
    Teacher(string n, int idcard) : staff(n), id_card(idcard)
    {
    }
};

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class Assistant : public Admin, public Teacher

{
public:
    Assistant(string n, int id, int idcard) : staff(n), Admin(n, id), Teacher(n, idcard) {}
     virtual void showinfo()
    {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "id card: " << id_card << endl;
    }
};
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int main() {
    Assistant a("Abdhesh", 101, 5551);
    a.showinfo();
    return 0;
}
