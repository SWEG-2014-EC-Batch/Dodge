#include <iostream>
using namespace std;
void mult(float num1, float num2);
int main(){
    float number1, number2;
    cout << "Enter Two Numbers:";
    cin >> number1 >> number2; 
    mult(number1, number2);
    return 0;
}
void mult(float num1, float num2){
    float product = num1 * num2;
    cout << "Product = " << product << endl;
}