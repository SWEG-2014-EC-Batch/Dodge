
#include <iostream>
using namespace std;

int main()
{
	int sum = 0, number, remainder;
	cout << "enter no ";
	cin >> number;
	while (number != 0)
	{
		remainder = number % 10;
		number /= 10;
		sum += remainder;
	}
	cout << sum;
}
