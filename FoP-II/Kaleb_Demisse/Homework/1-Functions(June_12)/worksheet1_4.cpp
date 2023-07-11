#include <iostream>
using namespace std;
double getProduct(int num1, double num2);
int main(){
    int firstNum;
    double secondNum;
    cout << "Enter an integer: ";
    cin >> firstNum;
    cout << "Enter an decimal: ";
    cin >> secondNum;
    cout << "Their product is " << getProduct(firstNum, secondNum) <<endl;
    return 0;
}
double getProduct(int num1, double num2){
    return num1*num2;
}
