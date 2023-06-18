#include <iostream>
// #include <array>
using namespace std;
int main()
{
	int num[] = {1, 2, 3, 4, 5, 6, 7};
	int *ptr = num;
	cout << num << endl;
	cout << ptr << endl;
	cout << &num[0] << endl;
}