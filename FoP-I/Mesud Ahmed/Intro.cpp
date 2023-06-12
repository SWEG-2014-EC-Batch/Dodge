#include <iostream>
using namespace std;
int main()
{
	int score;
	cout << "enter your score";
	cin >> score;
	if (score > 100 || score < 0)
	{
		cout << "please enter a valid score";
		return 0;
	}
	if (score >= 90) {
		cout << "A+" << endl;
	}
	if (score >= 80) {
		cout << "A" << endl;
	}if (score >= 75) {
		cout << "B+" << endl;
	}if (score >= 60) {
		cout << "B" << endl;
	}if (score >= 55) {
		cout << "C+" << endl;
	}if (score >= 45) {
		cout << "C" << endl;
	}if (score >= 30) {
		cout << "D" << endl;
	}
	else
		cout << "F" << endl;
	
}
