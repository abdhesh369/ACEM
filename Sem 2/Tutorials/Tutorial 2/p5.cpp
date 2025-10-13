// Create a class named City that will have two member variables CityName(char[20]) and DistFromKtm(float).
// Add member functions to set and retrieve the CityName and DistFromKtm separetely.Add operator overloading
// to find the distance between the cities(just find the difference of DistFromKtm) and sum of distance of
// those cities from Kathmandu.In the main function, initialise three city objects.Set the first and second
// city to be Pokhara and Dhangadi.Display the surn of DistFromKtm of Pokhara and Dhangadi and distance between Pokhara and Dhangadi
#include <iostream>
#include <cmath>
using namespace std;
class city
{
    char cityname[20];
    float DistFromKtm;

public:
    void getdata()
    {
        cout << "Enter the city name" << endl;
        cin >> cityname;
        cout << "Enter the distance from city" << endl;
        cin >> DistFromKtm;
    }

    float operator-(const city &c) const
    {
        return fabs(DistFromKtm - c.DistFromKtm);
    }

    float operator+(const city &c) const
    {
        return (DistFromKtm + c.DistFromKtm);
    }
    // void display() const
    // {
    //     cout << "City Name: " << cityname << endl;
    //     cout << "Distance from Kathmandu: " << DistFromKtm << " km" << endl;
    // }
};
int main()
{
    city c1, c2;
    cout << "Enter the first  city details" << endl;
    c1.getdata();
    cout << "Enter the second city details" << endl;
    c2.getdata();
    float totalDistance = c1 + c2;
    float diffDistance = c2 - c1;

    cout << "\n=== Calculations ===\n";
    cout << "Sum of distances from Kathmandu: " << totalDistance << " km" << endl;
    cout << "Distance between Pokhara and Dhangadi: " << diffDistance << " km" << endl;

    return 0;
}