// Write a program that display the total time in 24-hour clock format having
// fixed time 12:34:56 and 10:35:14. One constructor should initialize member
// data hour, minute and second to 0 and another should initialize it to fixed
// values. Other two member functions should add two objects of type time
// passed as arguments and display the result.
#include <iostream>
using namespace std;
class time
{
private:
    int hour;
    int minute;
    int second;

public:
    time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    time(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    time timeadd(time t1, time t2)
    {
        time t3;
        t3.second = t1.second + t2.second;
        t3.minute = t1.minute + t2.minute + (t3.second / 60);
        t3.second = t3.second % 60;
        t3.hour = t1.hour + t2.hour + (t3.minute / 60);
        t3.minute = t3.minute % 60;
        return t3;
    }
        void displayTime()
        {
            cout << "Total Time = ";
            cout << (hour < 10 ? "0" : "") << hour << ":"
                 << (minute < 10 ? "0" : "") << minute << ":"
                 << (second < 10 ? "0" : "") << second << endl;
        }
};
int main()
{
    time t1{12, 34, 56};
    time t2{10, 35, 14};
    time c=c.timeadd(t1,t2);
    c.displayTime();
}
