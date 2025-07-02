// Write a program to calculate the distance between two points using the concept
// of OOP
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    float x, y;

public:
    void setCoordinates(float a, float b) {
        x = a;
        y = b;
    }

    int display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    friend float calculateDistance(Point p1, Point p2);
};

float calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    Point p1, p2;
    float x1, y1, x2, y2;

    cout << "Enter coordinates of first point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter coordinates of second point (x2 y2): ";
    cin >> x2 >> y2;

    p1.setCoordinates(x1, y1);
    p2.setCoordinates(x2, y2);

    cout << "Point 1: ";
    p1.display();
    cout << "Point 2: ";
    p2.display();

    float distance = calculateDistance(p1, p2);
    cout << "Distance between the two points is: " << distance << endl;

    return 0;
}
