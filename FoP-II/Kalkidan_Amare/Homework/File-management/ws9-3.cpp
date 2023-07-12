#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Customer
{
    int account_num;
    string firstName;
    string lastName;
    double balance;
};

void displayCustomerInfo(const Customer &customer)
{
    cout << "Account Number: " << customer.account_num << endl;
    cout << "Name: " << customer.firstName << " " << customer.lastName << endl;
    cout << "Account Balance: $" << customer.balance << endl;
}

int main()
{
    int searchAccountNumber;

    cout << "Enter an account number: ";
    cin >> searchAccountNumber;

    ifstream file("customer_records.txt");

    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return 0;
    }

    Customer customer;
    bool found = false;

    while (file >> customer.account_num >> customer.firstName >> customer.lastName >> customer.balance)
    {
        if (customer.account_num == searchAccountNumber)
        {
            displayCustomerInfo(customer);
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "Account number not found." << endl;
    }

    return 0;
}