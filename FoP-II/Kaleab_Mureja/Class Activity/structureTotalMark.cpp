#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct student
{
  string id;
  string name;
  float testMark;
  float finalMark;
  float totalMark;
};

int main()
{
  int numberOfStud;
  cout << "Enter the number of student: ";
  cin >> numberOfStud;
  student *std = new student[numberOfStud];
  for (int i = 0; i < numberOfStud; i++)
  {
    cout << "Enter id: ";
    cin.ignore();
    getline(cin, std[i].id);
    cout << "Enter name: ";
    getline(cin, std[i].name);
    cout << "Enter textMark: ";
    cin >> std[i].testMark;
    cout << "Enter finalMark: ";
    cin >> std[i].finalMark;
    std[i].totalMark = std[i].testMark + std[i].finalMark;
    cout << endl;
    cout << "Enter " << i+ 2 << " Student Information for the following: " << endl;
  }

  cout << left << setw(20) <<"Your name " << setw(30) << "Your id number "<< setw(10) << "Total mark ";
  for (int i = 0 ; i < numberOfStud ; i++ ){
  cout << endl;
  cout << left << setw(20) <<std[i].name<< setw(30) << std[i].id<< setw(10) << std[i].totalMark;
  }

  return 0;
}