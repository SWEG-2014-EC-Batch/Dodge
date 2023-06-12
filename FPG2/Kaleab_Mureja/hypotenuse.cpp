#include <iostream>
#include <cmath>

using namespace std;

double hypotenuse(double side1, double side2);

int main()
{
  double side1, side2;
  cout << "Enter the length of side1: ";
  cin >> side1;
  cout << "Enter the length of side2: ";
  cin >> side2;
  double hyp = hypotenuse(side1, side2);
  cout << "The length of the hypotenuse is: " << hyp << endl;
  return 0;
}

double hypotenuse(double side1, double side2)
{
  double hyp = sqrt(pow(side1, 2) + pow(side2, 2));
  return hyp;
}
