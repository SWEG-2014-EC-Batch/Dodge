#include <iostream>
using namespace std;

struct phone
{
    int area_code, exchange, number;
} ph1 = {212, 767, 8900};
int main()
{
    phone ph2;
    cout << "enter the area code, exchange, number of the second phone" << endl;
    cin >> ph2.area_code >> ph2.exchange >> ph2.number;
    cout << "The first phone number is:\n "
         << "(" << ph1.area_code << ") " << ph1.exchange << " " << ph1.number << endl;
    cout << "The second phone number is:\n "
         << "(" << ph2.area_code << ") " << ph2.exchange << " " << ph2.number << endl;
}