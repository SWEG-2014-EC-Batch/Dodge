// net salary.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

int main()
{
    int total_income, worked_hours, overtime_payment, gross_salary, turn;
    float tax, rateperhr, net_salary;
    const float pension = 0.07;
    cout << "enter the number of times you want to excute this program ";
    cin >> turn;
    for (int i = 0; i < turn; i++)
    {
        cout << "enter 'gross salary' and then 'worked hours' ";
        cin >> gross_salary >> worked_hours;
        if (worked_hours > 40)
        {
            cout << "enter over time bonus rate/hour ";
            cin >> rateperhr;
            overtime_payment = rateperhr * (worked_hours - 40);
        }
        total_income = gross_salary + overtime_payment;
        if (total_income <= 200 && total_income >= 0)
        {
            tax = total_income * 0;
        }
        else if (total_income > 200 && total_income <= 600)
        {
            tax = total_income * 0.1;
        }
        else if (total_income > 600 && total_income <= 1200)
        {
            tax = total_income * 0.15;
        }
        else if (total_income > 1200 && total_income <= 2000)
        {
            tax = total_income * 0.2;
        }
        else if (total_income > 2000 && total_income <= 3500)
        {
            tax = total_income * 0.25;
        }
        else if (total_income > 3500)
        {
            tax = total_income * 0.3;
        }
        net_salary = (total_income - (gross_salary * pension) - (tax));
        cout << "Net salary= " << net_salary << endl;
    }
}
