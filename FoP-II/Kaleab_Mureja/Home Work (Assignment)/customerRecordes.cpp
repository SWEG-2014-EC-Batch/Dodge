#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Customer {
    int accountNumber;
    string firstName;
    string lastName;
    double accountBalance;
};

void createCustomerRecordsFile() {
    ofstream file("customer_records.txt");
    if (!file) {
        cout << "Failed to create the file." << endl;
        return;
    }

    Customer customers[5] = {
        {1000, "John", "Doe", 1500.50},
        {1001, "Jane", "Smith", 2500.25},
        {1002, "Michael", "Johnson", 3500.75},
        {1003, "Emily", "Davis", 4500.40},
        {1004, "David", "Wilson", 5500.90}
    };

    for (int i = 0; i < 5; i++) {
        file << customers[i].accountNumber << " " << customers[i].firstName << " "
             << customers[i].lastName << " " << customers[i].accountBalance << endl;
    }

    file.close();
}

void searchCustomerRecord(int accountNumber) {
    ifstream file("customer_records.txt");
    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    Customer customer;
    bool found = false;

    while (file >> customer.accountNumber >> customer.firstName >> customer.lastName >> customer.accountBalance) {
        if (customer.accountNumber == accountNumber) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        cout << "Account Number: " << customer.accountNumber << endl;
        cout << "Name: " << customer.firstName << " " << customer.lastName << endl;
        cout << "Account Balance: " << customer.accountBalance << endl;
    } else {
        cout << "Customer record not found." << endl;
    }
}

int main() {
    createCustomerRecordsFile();

    int accountNumber;
    cout << "Enter the account number: ";
    cin >> accountNumber;

    searchCustomerRecord(accountNumber);

    return 0;
}
