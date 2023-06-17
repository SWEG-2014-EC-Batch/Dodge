#include <iostream>

using namespace std;

int fibonacci(int n = 10);

int main() {
    int number;
    
    cout << "Enter a number to find the Fibonacci series: ";
    cin >> number;
    
    cout << "Fibonacci series without parameter: ";
    fibonacci();
    
    cout << "Fibonacci series with parameter: ";
    fibonacci(number);
    
    return 0;
}

int fibonacci(int n) {
    int num1 = 0, num2 = 1, nextTerm;
    
    for (int i = 1; i <= n; ++i) {
        cout << num1 << " ";
        nextTerm = num1 + num2;
        num1 = num2;
        num2 = nextTerm;
    }
    
    cout << endl;
    
    return num1;
}

