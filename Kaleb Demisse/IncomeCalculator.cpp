//income calculator

#include <iostream> 
using namespace std;
int main(){
    int totalIncome, totalHours, overtime, grossSalary;
    float tax, bonus, netSalary;
    const float pension = 0.07;
    cout << "Enter your gross salary: ";
    cin >> grossSalary;
    cout << "Enter your total work hours: ";
    cin >>totalHours;
        if (totalHours > 40){
            cout << "Enter your over time bonus rate per hour: ";
            cin >> bonus;
            overtime= bonus * (totalHours - 40);
        }
        totalIncome = grossSalary + overtime;
        if (totalIncome > 200 && totalIncome <= 600){
            tax = totalIncome * 0.1;
        }
        else if (totalIncome > 600 && totalIncome <= 1200){
            tax = totalIncome * 0.15;
        }
        else if (totalIncome > 1200 && totalIncome <= 2000){
            tax = totalIncome * 0.2;
        }
        else if (totalIncome > 2000 && totalIncome <= 3500){
            tax = totalIncome * 0.25;
        }
        else if (totalIncome > 3500){
            tax = totalIncome * 0.3;
        }
        else{
            tax =0.0;
        }
        netSalary = (totalIncome - (grossSalary * pension) - (tax));
        cout << "Your net salary is " << netSalary << endl;
}