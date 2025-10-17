#include <iostream>
#include <string>
using namespace std;

class Book
{
protected:
    string authorName;
    float price;

public:
    void getData()
    {
        cin.ignore();
        cout << "Enter Author Name: ";
        getline(cin, authorName);
        cout << "Enter Price of Book: ";
        cin >> price;
    }

    void displayData()
    {
        cout << "Author Name: " << authorName << endl;
        cout << "Price: " << price << endl;
    }
};

class Stock
{
protected:
    int noOfBooks;
    string category;

public:
    void getData()
    {
        cout << "Enter Number of Books: ";
        cin >> noOfBooks;
        cin.ignore();
        cout << "Enter Category: ";
        getline(cin, category);
    }

    void displayData()
    {
        cout << "Number of Books: " << noOfBooks << endl;
        cout << "Category: " << category << endl;
    }
};

class Library : public Book, public Stock
{
public:
    void getData()
    {
        cout << "Enter Book Details:\n";
        Book::getData();
        cout << "\nEnter Stock Details:\n";
        Stock::getData();
    }

    void displayData()
    {
        cout << "\nBook Details:\n";
        Book::displayData();
        cout << "\nStock Details:\n";
        Stock::displayData();
    }
};

int main()
{
    Library lib;

    lib.getData();
    lib.displayData();

    return 0;
}
