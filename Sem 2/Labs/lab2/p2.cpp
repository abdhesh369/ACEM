// Write a program to display n characters by using default arguments for all
// parameters. Assume that the function takes two arguments (one character to be
// printed and other number of characters to be printed)
#include <iostream>
using namespace std;

void display(char ch = 'n', int n = 5)
{
    for (int i = 0; i < n; i++)
    {
        cout << ch << " ";
    }
    cout << endl;
}

int main()
{
    cout << "Display using no arguments:" << endl;
    display(); 

    cout << "Display using one argument:" << endl;
    display('#'); 

    cout << "Display using two arguments:" << endl;
    display('@', 3); 

    return 0;
}
