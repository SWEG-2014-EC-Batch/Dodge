#include <iostream>
using namespace std;

struct Phone
{
    int area_code, exchange, number;
};

struct Person
{
    string name;
    Phone phone;
};

int main()
{
    Person persons[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the name of person " << i + 1 << ": ";
        cin >> persons[i].name;

        cout << "Enter the area code, exchange, and number for " << persons[i].name << "'s phone: ";
        cin >> persons[i].phone.area_code >> persons[i].phone.exchange >> persons[i].phone.number;

        cout << endl;
    }

    cout << "Phone Number Records:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "Person " << i + 1 << ": " << persons[i].name << endl;
        cout << "Phone Number: (" << persons[i].phone.area_code << ") " << persons[i].phone.exchange << " " << persons[i].phone.number << endl;
        cout << endl;
    }

    return 0;
}
