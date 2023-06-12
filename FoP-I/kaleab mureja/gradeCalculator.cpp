// Grade Calculator

#include <iostream>
using namespace std;
int main()
{
    int test, quiz, assignment, finalExam, project, courseGrade;
    int i = 0;
    cout << "Enter your test result that you take out of 15% : ";
    cin >> test;
    while (test > 15 || test < 0)
    {
        i++;
        if (i == 5)
        {
            cout << "You have entered a wrong value five times." << endl;
            return 0;
        }
        cout << "Please enter a valid test value: ";
        cin >> test;
    }

    cout << "Enter your quiz result that you take out of 5% : ";
    cin >> quiz;
    while (quiz > 5 || quiz < 0)
    {
        i++;
        if (i == 5)
        {
            cout << "YOu have entered a wrong value five times." << endl;
            return 0;
        }
        cout << "Please enter a valid quiz value: ";
        cin >> quiz;
    }

    cout << "Enter your project result that you take out of 20% : ";
    cin >> project;
    while (project > 20 || project < 0)
    {
        i++;
        if (i == 5)
        {
            cout << "You have entered a wrong value five times." << endl;
            return 0;
        }
        cout << "Please enter a valid project value: ";
        cin >> project;
    }

    cout << "Enter your assignment result that you take out of 10% : ";
    cin >> assignment;
    while (assignment > 10 || assignment < 0)
    {
        i++;
        if (i == 5)
        {
            cout << "You have entered a wrong value five times." << endl;
            return 0;
        }
        cout << "Please enter a valid assignment value: ";
        cin >> assignment;
    }

    cout << "Enter your final exam result that you take out of 50% : ";
    cin >> finalExam;
    while (finalExam > 50 || finalExam < 0)
    {
        i++;
        if (i == 5)
        {
            cout << "You have entered a wrong value five times." << endl;
            return 0;
        }
        cout << "Please enter a valid final exam value: ";
        cin >> finalExam;
    }

    courseGrade = test + quiz + assignment + finalExam + project;
    cout << "Your total course result is: " << courseGrade << endl;
    cout << "Your grade is: ";
    if (courseGrade >= 90)
    {
        cout << "A+" << endl;
    }
    else if (courseGrade >= 80)
    {
        cout << "A" << endl;
    }
    else if (courseGrade >= 75)
    {
        cout << "B+" << endl;
    }
    else if (courseGrade >= 60)
    {
        cout << "B" << endl;
    }
    else if (courseGrade >= 55)
    {
        cout << "C+" << endl;
    }
    else if (courseGrade >= 45)
    {
        cout << "C" << endl;
    }
    else if (courseGrade >= 30)
    {
        cout << "D" << endl;
    }
    else
    {
        cout << "F" << endl;
    }

    return 0;
}
