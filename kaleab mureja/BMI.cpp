#include <iostream>
using namespace std;
int main()
{
	char forOnePerson, formultiplePerson, forUnkownNumber;
	int i, n;
	cout << "for how many people do you want\n\t n = ";
	cin >> n;
	for (int i = 1; i <= 10; ++i)
	{
		i++;
		float weight, height;
		cout << "enter your weight in kg\n\t weight = ";
		cin >> weight;
		cout << "enter your height in meter\n\t hight =  ";
		cin >> height;
		float BMI;
		BMI = weight / (height * height);
		cout << "your BMI = " << BMI << endl;
		char Gender, m, f;
		cout << " enter gender either m or f \n\t Gender =  ";
		cin >> Gender;

		if (Gender == 'm')
		{
			if (BMI >= 20 && BMI <= 25)
			{
				cout << " you are normal " << endl;
			}
			else if (BMI < 20)
			{
				cout << "you are under weight" << endl;
			}
			else if (BMI > 25)
			{
				cout << "you are over weight " << endl;
			}
		}
		else if (Gender == 'f')
		{
			if (BMI >= 18 && BMI <= 23)
			{
				cout << " you are normal " << endl;
			}
			else if (BMI < 18)
			{
				cout << "you are under weight" << endl;
			}
			else if (BMI > 23)
			{
				cout << "you are over weight " << endl;
			}
		}
	}
	return 0;
}