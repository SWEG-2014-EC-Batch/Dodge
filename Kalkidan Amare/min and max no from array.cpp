
#include <iostream>
using namespace std;

int main()
{
	int max, size, min;
	int array[10]{};
	cout << "enter no size ";
	cin >> size;
	cout << "enter each " << size << " elements ";
	for (int i = 0; i < size; i++)
		cin >> array[i];
	max = array[0];
	min = array[0];
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	cout << "max= " << max << endl;
	cout << "min= " << min << endl;
}
