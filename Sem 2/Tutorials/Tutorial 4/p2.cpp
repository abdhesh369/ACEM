// Write a program for transaction processing that writes and reads random objects to and
// from a random access file so that user can add, update, delete and display the account
// information (accountnumber, lastname, firstname, totalbalance)

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const string file = "accountinfo.dat";

class Account
{
private:
    int accountNumber;
    char lastName[20];
    char firstName[20];
    float totalBalance;

public:
    void input()
    {
        cout << "Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Last Name: ";
        cin.getline(lastName, 20);
        cout << "First Name: ";
        cin.getline(firstName, 20);
        cout << "Total Balance: ";
        cin >> totalBalance;
    }

    void display() const
    {
        cout << setw(15) << accountNumber
             << setw(20) << lastName
             << setw(20) << firstName
             << setw(15) << totalBalance << endl;
    }

    friend void updateAccount();
    friend void deleteAccount();
    friend void displayAccounts();
};

void addAccount()
{
    Account a;
    a.input();

    ofstream fout(file, ios::binary | ios::app);
    if (!fout)
    {
        cout << "Error opening file!\n";
        return;
    }

    fout.write((char *)&a, sizeof(a));
    fout.close();

    cout << "✅ Account added successfully.\n";
}

void displayAccounts()
{
    ifstream fin(file, ios::binary);
    if (!fin)
    {
        cout << "No file found.\n";
        return;
    }

    Account A;
    cout << setw(15) << "Account No"
         << setw(20) << "Last Name"
         << setw(20) << "First Name"
         << setw(15) << "Balance" << endl;

    while (fin.read((char *)&A, sizeof(A)))
    {
        A.display();
    }

    fin.close();
}

void updateAccount()
{
    fstream fboth(file, ios::binary | ios::in | ios::out);
    if (!fboth)
    {
        cout << "Error opening file!\n";
        return;
    }

    int num;
    cout << "Enter the account number to update: ";
    cin >> num;

    Account acc;
    bool found = false;

    while (fboth.read((char *)&acc, sizeof(acc)))
    {
        if (acc.accountNumber == num)
        {
            cout << "\nEnter new details for this account:\n";
            acc.input();

            fboth.seekp(-sizeof(acc), ios::cur);
            fboth.write((char *)&acc, sizeof(acc));

            cout << "Account updated successfully.\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Account not found.\n";

    fboth.close();
}

void deleteAccount()
{
    ifstream fin(file, ios::binary);
    if (!fin)
    {
        cout << "Error opening file!\n";
        return;
    }

    ofstream fout("temp.dat", ios::binary);
    if (!fout)
    {
        cout << "Error creating temp file!\n";
        fin.close();
        return;
    }

    int num;
    cout << "Enter account number to delete: ";
    cin >> num;

    Account acc;
    bool found = false;

    while (fin.read((char *)&acc, sizeof(acc)))
    {
        if (acc.accountNumber != num)
        {
            fout.write((char *)&acc, sizeof(acc));
        }
        else
        {
            found = true;
        }
    }

    fin.close();
    fout.close();

    remove(file.c_str());
    rename("temp.dat", file.c_str());

    if (found)
        cout << "Account deleted successfully.\n";
    else
        cout << "Account not found.\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n===== Transaction Processing Menu =====\n";
        cout << "1. Add Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Update Account\n";
        cout << "4. Delete Account\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAccount();
            break;
        case 2:
            displayAccounts();
            break;
        case 3:
            updateAccount();
            break;
        case 4:
            deleteAccount();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
