#include <iostream>
#include <iomanip>
using namespace std;

struct person{
    string name;
    char gender;
    int age;
    float weight, height, BMI;
};

int main(){
    
    person person1;
    cout << "Enter name: ";
    getline(cin, person1.name);
    cout << "Enter gender: ";
    cin >> person1.gender;
    cout << "Enter age: ";
    cin >> person1.age;
    cout << "Enter weight: ";
    cin>> person1.weight;
    cout << "Enter Height: ";
    cin >> person1.height;

    person1.BMI = person1.weight/(person1.height*person1.height);

    cout << left << setw(20) << "NAME" << setw(10) << "GENDER" << setw(10) << "AGE" << setw(10) << "WEIGHT" << setw(10) << "HEIGHT" << setw(10) << "BMI" << endl;

    cout << left << setw(20) << person1.name << setw(10) << person1.gender << setw(10) << person1.age << setw(10) << person1.weight << setw(10) << person1.height << setw(10) << person1.BMI << endl;
    return 0;
}