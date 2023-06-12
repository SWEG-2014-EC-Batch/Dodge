#include <iostream>
using namespace std;
int main()
{
	float incometaxrate, overtimerate, workedhours, tot, salary, net_income;
	int bonus;
	cout << "enter your gross salary";
	
	cin >> salary;
	cout << "enter your worked hours ";
	cin >> workedhours;
	
	if (workedhours > 40)
	{
		cout << "enter over time bonus rate per hour";
		cin >> overtimerate;
		bonus = (workedhours - 40) * overtimerate;
		

	}
	tot = salary + bonus;
	float difference;
	if (tot <= 200 && tot >= 0)
	{
		difference = tot * 0;

	}
	else if (tot <= 600 && tot >= 200)
	{
		difference = tot * 0.1;

	}
	else if (tot <= 1200 && tot >= 600)
	{
		difference = tot * 0.15;

	}
	else if (tot <= 2000 && tot >=1200)
	{
		difference = tot * 0.2;

	}
	else if (tot <= 3500 && tot >= 2000)
	{
		difference = tot * 0.25;

	}
	else if (tot >= 3500)
	{
		difference = tot * 0.3;

	}

	net_income = tot - (salary * 0.07) - difference;
	
	cout << "you net salary is" <<net_income<< endl;
		return 0;
}
