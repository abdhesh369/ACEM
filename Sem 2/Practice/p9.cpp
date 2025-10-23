// Write a BankAccount class with :
//     Private members : accountNumber(int),
//                       balance(double)
//     Public functions :
//     deposit(double amount)
//     withdraw(double amount)
//     display() → prints account number and balance
//     Extra : Make sure withdraw doesn’t allow balance to go negative.
#include <iostream>
using namespace std;
class BankAccount
{
private:
    int accountnumber;
    double balance;

public:
    BankAccount(int x = 0, double y = 00) : accountnumber(x), balance(y) {}
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successfully completed !!" << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "withdraw successfully completed !!" << endl;
        }
        else
        {
            cout << "Insufficiant balance" << endl;
        }
    }

    void display()
    {
        cout << "Account number is : " << accountnumber << endl;
        cout << "Total balance: " << balance << endl;
    }
};

int main()
{
    BankAccount acc(12345, 1000.0);
    acc.deposit(500);
    acc.withdraw(200);
    acc.display();
    return 0;
}
