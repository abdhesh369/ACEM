// An industry seals lorry and taxi.Create a class Automobile that stores production date and price.
// From this class derive another two classes : Lorry, which adds weight capacity in kilogram and Taxi, which adds seat - capacity in number.
// Each of these classes should have member functions to get data and set data.Use user defined constructors to initialize these objects.
#include <iostream>
using namespace std;

class Automobile
{
protected:
    int date;
    float price;

public:
    Automobile(int d = 0, float p = 0.0)
    {
        date = d;
        price = p;
    }

    void setData(int d, float p)
    {
        date = d;
        price = p;
    }

    void getData()
    {
        cout << "Date of Production: " << date << endl;
        cout << "Price of Vehicle: " << price << endl;
    }
};

class Lorry : public Automobile
{
private:
    float weight;

public:
    Lorry(int d = 0, float p = 0.0, float w = 0.0) : Automobile(d, p)
    {
        weight = w;
    }

    void setData(int d, float p, float w)
    {
        Automobile::setData(d, p);
        weight = w;
    }

    void getData()
    {
        Automobile::getData();
        cout << "Weight Capacity: " << weight << " kg" << endl;
    }
};

class Taxi : public Automobile
{
private:
    int seat;

public:
    Taxi(int d = 0, float p = 0.0, int s = 0) : Automobile(d, p)
    {
        seat = s;
    }

    void setData(int d, float p, int s)
    {
        Automobile::setData(d, p);
        seat = s;
    }

    void getData()
    {
        Automobile::getData();
        cout << "Seat Capacity: " << seat << " seats" << endl;
    }
};

int main()
{
    cout << "----- Lorry Details -----" << endl;
    Lorry l1(2022, 2500000, 8000);
    l1.getData();

    cout << "\nUpdating Lorry data using setData()...\n";
    l1.setData(2023, 2700000, 9000);
    l1.getData();

    cout << "\n----- Taxi Details -----" << endl;
    Taxi t1(2023, 1500000, 5);
    t1.getData();

    cout << "\nUpdating Taxi data using setData()...\n";
    t1.setData(2024, 1600000, 6);
    t1.getData();

    return 0;
}
