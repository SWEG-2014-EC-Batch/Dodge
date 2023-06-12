#include <iostream>
#include <cmath>
using namespace std;

double sum(double num1, double num2);

int main(){
	double num1, num2;
	cout << "Enter first number: ";
	cin >> num1;
	cout << "Enter second number: ";
	cin >> num2;
	cout << " The result is " << sum(num1, num2) << endl;
	return 0;
}

double sum( double num1, double num2){
	double answer = pow(num1, 3) + sqrt(num2);
	return answer;
}
