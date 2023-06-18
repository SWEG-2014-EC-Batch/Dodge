#include <iostream>
using namespace std;
bool leapyear();

int main(){
    cout << leapyear() << endl;
    return 0;
}
bool leapyear(){
    int year;
    cout <<"Enter a year: ";
    cin >> year;
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}