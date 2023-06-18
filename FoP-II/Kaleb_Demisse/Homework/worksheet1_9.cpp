#include <iostream>

using namespace std;

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortNumbers(int& a, int& b, int& c) {
    cout << "The numbers before sorting: " << a << " " << b << " " << c << endl;
    if (a > b) {
        swapValues(a, b);
    }
    if (a > c) {
        swapValues(a, c);
    }
    if (b > c) {
        swapValues(b, c);
    }
    cout << "The numbers after sorting: " << a << " " << b << " " << c << endl;
}

int main() {
    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;
    sortNumbers(a, b, c);
    return 0;
}
