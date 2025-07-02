// Write a program to find the volume of cube, cylinder and rectangular box by
// suing the concept of function of overloading.
#include <iostream>
using namespace std;
class volume
{
private:
    float volumevalue;

public:
    // void setvalue(float a,float b,float c)
    // {
    //     x=a;
    //     y=b;
    //     z=c;
    // }
    float vol(float x)
    {
        volumevalue = x * x * x;
        cout << "Volume of cube :" << endl<<volumevalue<<endl;
    }
    float vol(float r, float h, double pi=3.337)
    {
        volumevalue = r*r * h * pi;
        cout << "Volume of cylinder :" << endl<<volumevalue<<endl;
    }
    float vol(float x, float y, float z)
    {
        volumevalue = x * y * z;
        cout << "Volume of rectangular box :" << endl<<volumevalue<<endl;
    }
};
int main()
{
    volume v;
    float length,breath, hight;
    cout<<"enter the value of mesurement of object :"<<endl;
    cin>>length>>breath>>hight;
    v.vol(length);
    v.vol(length,breath);
    v.vol(length,breath,hight);

    return 0;
}