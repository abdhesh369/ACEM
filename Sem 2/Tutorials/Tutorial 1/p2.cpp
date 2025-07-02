#include <iostream>
using namespace std;
class Finder
{
public:
  
    void findsmalleest(int arr[], int n)
    {
        int min = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        cout << "The smallest element is: " << min << endl;
    }
    void findlargest(int arr[], int n)
    {
        int max = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        cout << "The largest element is: " << max << endl;
    }
};
 int main()
{
    Finder obj1;
    int n;
    cout << " enter a number of member of array : ";
    cin >> n;
    int* arr = new int[n];
    cout << " enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    obj1.findsmalleest(arr, n);
    obj1.findlargest(arr, n);
    return 0;
}
