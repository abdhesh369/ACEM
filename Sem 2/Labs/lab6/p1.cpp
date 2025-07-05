// Write a program to illustrate single, multiple, multilevel, hierarchial inheritance
#include <iostream>
using namespace std;
class Single
{
public:
    void displaysingle()
    {
        cout << "this is single inheritance" << endl;
    }
};
class singleA : public Single
{
public:
    void displaysingleA()
    {
        cout << "i inherit class single" << endl;
    }
};
//---------------------------------------------------------------
class Multiple
{
public:
    void displaymultiple()
    {
        cout << "this is multiple inheritance" << endl;
    }
};
class MultipleA
{
public:
    void displaymultipleA()
    {
        cout << "this is multiple A inheritance" << endl;
    }
};

class MultipleB : public Multiple, public MultipleA
{
public:
    void displaymultipaleB()
    {
        cout << "i inherit class multiple and multiple A" << endl;
    }
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Multilevel
{
public:
    void displaymultilevel()
    {
        cout << "this is multilevel inheritance" << endl;
    }
};

class MultilevelA : public Multilevel
{
public:
    void displaymultilevelA()
    {
        cout << "i inherit class Multilevel" << endl;
    }
};
class MultilevelB : public MultilevelA
{
public:
    void displaymultilevelB()
    {
        cout << "i inherit class Multilevel A" << endl;
    }
};
class MultilevelC : public MultilevelB
{
public:
    void displaymultilevelC()
    {
        cout << "i inherit class Multilevel B" << endl;
    }
};
//******************************************************************************************
class Hierarchial
{
public:
    void displayhierarchial()
    {
        cout << "this is hierarchial inheritance" << endl;
    }
};
class HierarchialA : public Hierarchial
{
public:
    void displayhierarchialA()
    {
        cout << "this is hierarchial A inheritance" << endl;

        cout << "i inherit class hierarchial" << endl;
    }
};

class HierarchialB : public Hierarchial
{
public:
    void displayhierarchialB()
    {
        cout << "this is hierarchial B inheritance" << endl;

        cout << "i inherit class hierarchial" << endl;
    }
};
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int main()
{
    singleA s;
    s.displaysingle();
    s.displaysingleA();

    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

    MultipleB mb;
    mb.displaymultiple();
    mb.displaymultipleA();
    mb.displaymultipaleB();

    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

    MultilevelC mla;
    mla.displaymultilevel();
    mla.displaymultilevelA();
    mla.displaymultilevelB();
    mla.displaymultilevelC();

    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

    class HierarchialA ha;
    ha.displayhierarchial();
    ha.displayhierarchialA();
    
    HierarchialB hb;
    hb.displayhierarchial();
    hb.displayhierarchialB();

    

        return 0;
}