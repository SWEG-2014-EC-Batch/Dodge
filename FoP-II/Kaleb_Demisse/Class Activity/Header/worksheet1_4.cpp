#include "header.h"
#include "header2.h"
using namespace std;
int main(){
    int firstNum;
    double secondNum;
    cout << "Enter an integer: ";
    cin >> firstNum;
    cout << "Enter an decimal: ";
    cin >> secondNum;
    cout << "Their product is " << getProduct(firstNum, secondNum) <<endl;

    check();

    return 0;
}

