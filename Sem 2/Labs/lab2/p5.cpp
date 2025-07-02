// WAP to find the sum and average of the number by using new and delete
// operator. Also use static_cast casting operator.
#include <iostream>
using namespace std;
class calculate
{
public:
    int add, average;
    int sum(int arr[], int x)
    {
        add=0;
        for (int i = 0; i < x; i++)
        {
            add += arr[i];
        }
        return add;
    }
    float avg(int sum, int y)
    {
        average =static_cast<float>( sum) / y;
        return average;
    }
  
};

int main()
{
    calculate c;
    int n ;
    float a,b;
    cout << "Enter how many numbers: ";
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   a= c.sum(arr,n);
   b= c.avg(a,n);
   cout<<"Sum : "<<a<<endl;
   cout<<"Average : "<<b<<endl;
   delete[] arr;

    return 0;
}
