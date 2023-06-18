
#include <iostream>
using namespace std;

int main()
{
	int x, y, z;
	cout << "enter 3 numbers to get the largest: ";
	cin >> x >> y >> z;
	if (x > y)
	{
		if (x > z)
		{
			cout << x;
		}
		else if (z > y)
		{
			cout << z;
		}
	}
	else if (y > z)
	{
		cout << y;
	}
	else
	{
		cout << z;
	}
	cout << "\n";
	system("pause");
}
