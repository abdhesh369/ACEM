#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const string FILENAME = "store.dat";

class Item
{
private:
    int itemCode;
    char itemName[30];
    float price;
    int quantity;

public:
    void input()
    {
        cout << "Enter Item Code: ";
        cin >> itemCode;
        cin.ignore();
        cout << "Enter Item Name: ";
        cin.getline(itemName, 30);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void display() const
    {
        cout << left << setw(10) << itemCode
             << setw(25) << itemName
             << right << setw(10) << fixed << setprecision(2) << price
             << setw(10) << quantity
             << setw(12) << fixed << setprecision(2) << price * quantity
             << endl;
    }

    int getItemCode() const { return itemCode; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    const char *getName() const { return itemName; }

    friend void addItem();
    friend void displayItems();
    friend void generateBill();
};

void addItem()
{
    ofstream fout(FILENAME, ios::binary | ios::app);
    if (!fout)
    {
        cout << "Error opening file!\n";
        return;
    }

    Item item;
    item.input();
    fout.write((char *)&item, sizeof(item));
    fout.close();

    cout << "Item added successfully.\n";
}

void displayItems()
{
    ifstream fin(FILENAME, ios::binary);
    if (!fin)
    {
        cout << "No records found.\n";
        return;
    }

    Item item;
    cout << "\n-------------------------------------------- STORE INVENTORY --------------------------------------------\n";
    cout << left << setw(10) << "Code"
         << setw(25) << "Item Name"
         << right << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(12) << "Total"
         << endl;
    cout << "----------------------------------------------------------------------------------------------------------\n";

    while (fin.read((char *)&item, sizeof(item)))
    {
        item.display();
    }

    fin.close();
    cout << "----------------------------------------------------------------------------------------------------------\n";
}

void generateBill()
{
    ifstream fin(FILENAME, ios::binary);
    if (!fin)
    {
        cout << "No records found!\n";
        return;
    }

    int code;
    char choice;
    float total = 0;
    Item item;

    cout << "\n========= Generate Bill =========\n";
    cout << left << setw(10) << "Code"
         << setw(25) << "Item Name"
         << right << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(12) << "Amount"
         << endl;
    cout << "---------------------------------------------------------------------\n";

    do
    {
        cout << "Enter item code to purchase: ";
        cin >> code;

        fin.clear();
        fin.seekg(0, ios::beg); 

        bool found = false;
        while (fin.read((char *)&item, sizeof(item)))
        {
            if (item.getItemCode() == code)
            {
                found = true;
                int qty;
                cout << "Enter quantity to purchase: ";
                cin >> qty;

                if (qty > item.getQuantity())
                {
                    cout << "Not enough stock available.\n";
                }
                else
                {
                    float amt = qty * item.getPrice();
                    cout << left << setw(10) << item.getItemCode()
                         << setw(25) << item.getName()
                         << right << setw(10) << fixed << setprecision(2) << item.getPrice()
                         << setw(10) << qty
                         << setw(12) << fixed << setprecision(2) << amt << endl;
                    total += amt;
                }
                break;
            }
        }

        if (!found)
            cout << "Item code not found!\n";

        cout << "Add another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "---------------------------------------------------------------------\n";
    cout << setw(55) << "Total Amount: " << setw(12) << fixed << setprecision(2) << total << endl;
    cout << "=====================================================================\n";

    fin.close();
}

int main()
{
    int choice;
    do
    {
        cout << "\n========== Department Store Billing System ==========\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addItem();
            break;
        case 2:
            displayItems();
            break;
        case 3:
            generateBill();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
