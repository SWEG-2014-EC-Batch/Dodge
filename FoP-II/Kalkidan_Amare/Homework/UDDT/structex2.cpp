#include <iostream>
using namespace std;

struct person
{
    string name;
    char gender;
    int age;
    float weight;
    float height;
} p1;
int main()
{
    cout << "enter the person's name gender age weight height:" << endl;
    cin >> p1.name >> p1.gender >> p1.age >> p1.weight >> p1.height;
    cout << p1.name << " is " << p1.age << " years old and " << p1.gender << " and the BMI is " << p1.weight / (p1.height * p1.height);
}