// Declare an integer variable x = 10
// Create a pointer to it
// Change its value to 20 using the pointer
// Print the value before and after.

#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *y = &x;
    cout << " The value befor change is: " << *y << endl;
    *y = 20;
    cout << " The value after change is: " << *y << endl;

    return 0;
}
