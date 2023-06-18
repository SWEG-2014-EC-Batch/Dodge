#include <iostream>
using namespace std;

#include <iostream>

void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortValues(int& a, int& b, int& c); 

int main() {
    int a = 5, b = 10, c = 3;

    sortValues(a, b, c);

    return 0;
}
void sortValues(int& a, int& b, int& c) {
    cout << "Before swapping: a = " << a << ", b = " << b << ", c = " << c << endl;

    // Sort the values in descending order
    if (a < b) {
        swapValues(a, b);
    }
    if (a < c) {
        swapValues(a, c);
    }
    if (b < c) {
        swapValues(b, c);
    }

    cout << "After swapping: a = " << a << ", b = " << b << ", c = " << c << endl;
}
