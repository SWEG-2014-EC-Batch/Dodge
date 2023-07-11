#include <iostream>
using namespace std;

struct Phone {
    int areaCode;
    int exchange;
    int number;
};

int main() {
    Phone phone1 = {212, 767, 8900};

    Phone phone2;
    cout << "Enter the area code: ";
    cin >> phone2.areaCode;
    cout << "Enter the exchange: ";
    cin >> phone2.exchange;
    cout << "Enter the number: ";
    cin >> phone2.number;

    cout << "Phone 1: (" << phone1.areaCode << ") " << phone1.exchange << "-" << phone1.number << endl;
    cout << "Phone 2: (" << phone2.areaCode << ") " << phone2.exchange << "-" << phone2.number << endl;

    return 0;
}