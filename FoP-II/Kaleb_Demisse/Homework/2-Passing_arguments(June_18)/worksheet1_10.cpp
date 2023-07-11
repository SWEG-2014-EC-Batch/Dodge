#include <iostream>

using namespace std;

void input(int& feet, double& inches);
void output(int feet, double inches, int meters, double centimeters);
void process(int& feet, double& inches, int& meters, double& cenimeters);

int main(){
	char cont;
	do{
		int meters, feet;
		double inches, centimeters;
		input(feet, inches);
		output(feet, inches, meters, centimeters);
		cout << "Enter \"Q\" to quit and any other key to continue: ";
		cin >> cont;
	}while(cont != 'q' && cont != 'Q');
	return 0;
}

void input(int& feet, double& inches){
	cout << "Enter number of feet: ";
	cin >> feet;
	cout << "Enter number of inches: ";
	cin >> inches;
}
void output(int feet, double inches, int meters, double centimeters){
	process(feet, inches, meters, centimeters);
	cout << feet << " feet and " << inches << " inches is equal to " << meters << " meters and " << centimeters << " centimeters" << endl;
}
void process(int& feet, double& inches, int& meters, double& centimeters){
	centimeters = ((12 * feet) + inches) * 2.54 ;
	meters = centimeters/100;
	centimeters -= 100*meters;
}
