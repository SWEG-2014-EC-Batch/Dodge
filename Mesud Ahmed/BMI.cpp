#include <iostream>
using namespace std;

int main()
{

	void calculate_bmi() 
	{
		string gender;
		int weight;
		float height;
		float bmi;
		cout << "Enter your weight: ";
		cin >> weight;
		cout << "Enter your height: ";
		cin >> height;

		bmi = weight / (pow(height, 2));
		cout << "Your BMI is: " << bmi << endl;
		cout << "Please enter your gender(female/male): ";
		cin >> gender;

		int underLimit = 18;
		int normalLimit = 23;

		if (gender == "male") {
			underLimit = 20;
			normalLimit = 25;
		}

		if (bmi < underLimit) {
			cout << "You are underweight" << endl;
		}
		else if (bmi > normalLimit) {
			cout << "You are overweight" << endl;
		}
		else {
			cout << "Congrats, you have a great BMI" << endl;
		}
	

	int main() {
		int type;
		cout << "===================================MENU============================="
			"====\nEnter:\n\t1: Calculate BMI of a single person\n\t2: Calculate "
			"BMI of inputted number of people\n\t3: Calculate BMI until I tell "
			"you to stop\n";
		cin >> type;
		if (type == 1) {
			calculate_bmi();
		}
		else if (type == 2) {
			int numPeople;
			cout << "Enter number of people: " << endl;
			cin >> numPeople;
			while (numPeople > 0) {
				calculate_bmi();
				numPeople--;
			}
		}
		else if (type == 3) {
			while (true) {
				char c;
				cout << "Please enter q if you want to exit the program, otherwise enter any character" << endl;
				cin >> c;
				if (c == 'q') {
					break;
				}
				calculate_bmi();
			}
		}
		else {
			cout << "The program will now exit, you entered an invalid value" << endl;
		}
		return 0;
	}

}
