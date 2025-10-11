// Define a class to hold rectangular co-ordinates, ie. x and y co-ordinates.
// Let P1 and P2 be the objects of this class where Pl is initialized to (20, 30).
// Facilitate the operation P 2=P1++ in such a way that the value in P2 is (21, 31) afterward.
#include <iostream>
using namespace std;
class Rectangle
{
    int x;
    int y;

public:
    // Rectangle()
    // {
    //     x = 0;
    //     y = 0;
    // }
    Rectangle(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
    void getdata()
    {
        cout << "Enter x cordinate:" << endl;
        cin >> x;
        cout << "Enter y cordinate:" << endl;
        cin >> y;
    }
    Rectangle operator++(int)
    {
        Rectangle temp;
        temp.x = x + 1;
        temp.y = y + 1;
        return temp;
    }

    void display()
    {
        cout << "X cordinate is :" << x << endl;
        cout << "y cordinate is :" << y << endl;
    }
};

int main()
{
    Rectangle p1, p2;
    p1.getdata();
    
    p2 = p1++;
    cout << "***Cordinates after incresment***" << endl;
    p2.display();

    return 0;
}