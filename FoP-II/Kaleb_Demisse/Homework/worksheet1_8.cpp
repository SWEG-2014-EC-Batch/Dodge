#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int number);
int main(){
	int number;
	cout << "Enter an integer from 1-1000 to check if it's prime: ";
	cin >> number;
	cout <<boolalpha<< isPrime(number) << endl;
	return 0;
}

bool isPrime(int number){
	if(1 > number|| number > 1000){
		return false;
	}
	for(int i = 2; i <= sqrt(number); i++){
		if(number % i == 0)
			return false;
	}
	return true;
}
