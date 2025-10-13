// Create a class having an array as mernber.Overload index operator([]) to input and display the elements in the array
#include <iostream>
using namespace std;

class array {
    int arr[5];
public:
    int &operator[](int index) {
        if (index < 0 || index >= 5) {
            cout << "Index out of range!" << endl;
            return arr[0];
        }
        return arr[index];
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    array a1;
    cout << "Enter 5 array elements:\n";
    for (int i = 0; i < 5; i++)
        cin >> a1[i];  

    cout << "\nDisplaying elements using overloaded []:\n";
    for (int i = 0; i < 5; i++)
        cout << "a1[" << i << "] = " << a1[i] << endl;

    cout << "\nAll elements: ";
    a1.display();

    return 0;
}