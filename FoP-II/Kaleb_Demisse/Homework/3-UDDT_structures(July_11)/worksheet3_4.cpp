#include <iostream>
#include <string>
using namespace std;

struct Phone {
    int areaCode;
    int exchange;
    int number;
};

struct Person {
    string name;
    Phone phoneNumber;
};

int main() {
    Person persons[10];

    for (int i = 0; i < 10; i++) {
        cout << "Enter the name of Person " << i + 1 << ": ";
        getline(cin >> ws, persons[i].name);

        cout << "Enter the area code: ";
        cin >> persons[i].phoneNumber.areaCode;
        cout << "Enter the exchange: ";
        cin >> persons[i].phoneNumber.exchange;
        cout << "Enter the number: ";
        cin >> persons[i].phoneNumber.number;

        cout << endl;
    }

    cout << "Phone Number Records:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Person " << i + 1 << ": " << persons[i].name << endl;
        cout << "Phone Number: (" << persons[i].phoneNumber.areaCode << ") " 
             << persons[i].phoneNumber.exchange << "-" << persons[i].phoneNumber.number << endl;
        cout << endl;
    }

    return 0;
}