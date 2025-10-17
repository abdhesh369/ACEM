#include <iostream>
using namespace std;

class Base
{
protected:
    int baseValue;

public:
    Base(int val = 0) : baseValue(val) {}

    virtual void increase()
    {
        baseValue += 10;
        cout << "Base value increased by 10. New baseValue: " << baseValue << endl;
    }

    void display()
    {
        cout << "Base value: " << baseValue << endl;
    }
};

class Derived : public Base
{
private:
    int derivedValue;

public:
    Derived(int bVal = 0, int dVal = 0) : Base(bVal), derivedValue(dVal) {}

    void increase() override
    {
        Base::increase();
        derivedValue += 5;
        cout << "Derived value increased by 5. New derivedValue: " << derivedValue << endl;
    }

    void display()
    {
        cout << "Base value: " << baseValue << ", Derived value: " << derivedValue << endl;
    }
};

int main()
{
    cout << "=== Base Class Object ===" << endl;
    Base b1(20);
    b1.display();
    b1.increase();
    b1.display();

    cout << "\n=== Derived Class Object ===" << endl;
    Derived d1(30, 50);
    d1.display();
    d1.increase();
    d1.display();

    cout << "\n=== Using Base Class Pointer to Derived Object ===" << endl;
    Base *ptr = &d1;
    ptr->increase();
    ptr->display();

    return 0;
}
