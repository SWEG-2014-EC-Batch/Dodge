#include <iostream>
using namespace std;

void reverse_num() {
  int num, reverse;
  cout << "Enter number: ";
  cin >> num;

  while (num > 0) {
    cout << num % 10;
    num /= 10;
  }
  cout << endl;
}

void num_digits() {
	int num;
	cout << "Enter number: ";
	cin >> num;
	int count = 0;

	while (num > 0) {
		count++;
		num = num / 10;
	}

	cout << "Number of digits: " << count << endl;
}

void sum_digits() {
	int num;
	cout << "Enter number: ";
	cin >> num;

	int sum = 0;
	while (num > 0) {
		sum += num % 10;
		num = num / 10;
	}

	cout << "Sum: " << sum << endl;
}

int main() {
	reverse_num();
	num_digits();
	sum_digits();
	return 0;
}
