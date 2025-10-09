// 8. Create a class called carport that has int member data for car id, int member data for charge/hour
// and float member data for time. Set the data and show the charges and parked hours of corresponding car id.
//  Make two members for setting and showing the data. Member function should be called from other functions.
#include <iostream>
using namespace std;
class carport
{
    int car_id;
    int charge;
    float time;

public:
    void setdata()
    {
        cout << "Enter car ID: ";
        cin >> car_id;
        cout << "Enter charge per hour: ";
        cin >> charge;
        cout << "Enter time parked (in hours): ";
        cin >> time;
    }
    void display()
{
    cout << "\n--- Car Parking Details ---\n";
    cout << "Car ID: " << car_id << endl;
    cout << "Charge per hour: Rs. " << charge << endl;
    cout << "Time parked: " << time << " hr" << endl;
    cout << "Total charge: Rs. " << charge * time << endl;
}

};
void xyz()
{
    carport obj;
    obj.setdata();
    obj.display();
}
int main()
{
    cout << "=== Car Parking Information ===\n";
    xyz();
    return 0;
}