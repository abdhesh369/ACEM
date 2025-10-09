// 9. Create a class Product which has details of Product code, price, customer name and salesID.
//  There should be a serial number that indicates the number of sales made which will also be salesID for that sales.
//  Finally display the list the details of all the sales made so far.
#include <iostream>
#include <vector>
using namespace std;
class product
{
private:
    int code;
    int price;
    string customer_name;
    int sales_id;
    static int count;

public:
    void getdata()
    {
        cout << "Enter the code of product" << endl;
        cin >> code;
        cout << "Enter the price of product" << endl;
        cin >> price;
        cout << "Enter the name of  customer" << endl;
        cin.ignore();
        getline(cin, customer_name);

        count++;
        sales_id = count;
    }
    void display()
    {

        cout << "The serial number of product is " << sales_id << endl;
        cout << "The product code is " << code << endl;
        cout << "The product price is " << price << endl;
        cout << "The name of customer who bought it is " << customer_name << endl;
    }
    static void totalsales()
    {
        cout << "The total  number of product sold is " << count << endl;
    }
};
int product::count = 0;
int main()
{
    int n;
    cout << "Enter the number of product sold" << endl;
    cin >> n;
    std::vector<product> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i].getdata();
    }
    for (int i = 0; i < n; i++)
    {
        p[i].display();
    }
    product::totalsales();
    return 0;
}