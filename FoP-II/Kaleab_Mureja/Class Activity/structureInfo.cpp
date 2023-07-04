#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct person
{
  string name;
  string gender;
  int age;
  float weight;
  float height;
  float BMI;
};

int main()
{
  int numberOfPeople;
  cout << "Enter the number of people: ";
  cin >> numberOfPeople;
  person *bmi = new person[numberOfPeople];

  for (int i = 0; i < numberOfPeople; i++)
  {
    cout << endl;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, bmi[i].name);
    cout << "Enter your gender: ";
    getline(cin, bmi[i].gender);
    cout << "Enter your age: ";
    cin >> bmi[i].age;
    cout << "Enter your weight: ";
    cin >> bmi[i].weight;
    cout << "Enter your height in meter: ";
    cin >> bmi[i].height;
    bmi[i].BMI = ((bmi[i].weight) / pow(bmi[i].height, 2));
  }
  cout << left << setw(20) << "Your name " << setw(20) << "Your gender " << setw(15) << "Your age" << setw(15) << "Your BMI ";

  for (int i = 0; i < numberOfPeople; i++)
  {
    cout << endl;
    cout << left << setw(20) << bmi[i].name << setw(20) << bmi[i].gender << setw(15) << bmi[i].age << setw(15) << bmi[i].BMI;
  }
}