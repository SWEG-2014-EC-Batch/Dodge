#include <iostream>
using namespace std;

int main()
{
	float h, m;
	int n;
	char g;
	cout << "enter the number of calculation you want ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cout << " enter your height in meters and then your mass in Kg: ";
		cin >> h >> m;
		cout << "enter your gender 'm' for male or 'f' for female: ";
		cin >> g;
		float BMI = m / (h * h);
		cout << "your BMI is " << BMI << endl;
		int under = 18;
		int over = 23;
		if (g == 'm')
		{
			under = 20;
			over = 25;
		}
		if (BMI < under)
		{
			cout << "under weight " << endl;
		}
		else if (BMI >= under && BMI <= over)
		{
			cout << "normal " << endl;
		}
		else
		{
			cout << "over weight " << endl;
		}
	}
}