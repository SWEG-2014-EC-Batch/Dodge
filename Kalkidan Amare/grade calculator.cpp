#include <iostream>
using namespace std;
int main()
{
    int test, quiz, assignment, project, finalExam, courseGrade;

    cout << "Enter your test result out of 15: ";
    cin >> test;
    for (int i = 1; test > 15 || test < 0; i++)
    {
        if (i == 5)
        {
            cout << "You entered a wrong value 5 times." << endl;
            return 0;
        }
        cout << "Enter a valid test value: ";
        cin >> test;
    }

    cout << "Enter your quiz result out of 5: ";
    cin >> quiz;
    for (int i = 1; quiz > 5 || quiz < 0; i++)
    {
        if (i == 5)
        {
            cout << "You entered a wrong value 5 times." << endl;
            return 0;
        }
        cout << "Enter a valid quiz value: ";
        cin >> quiz;
    }

    cout << "Enter your project result out of 20: ";
    cin >> project;
    for (int i = 1; project > 20 || project < 0; i++)
    {
        if (i == 5)
        {
            cout << "You entered a wrong value 5 times." << endl;
            return 0;
        }
        cout << "Enter a valid project value: ";
        cin >> project;
    }

    cout << "Enter your assignment resultout of 10: ";
    cin >> assignment;
    for (int i = 1; assignment > 10 || assignment < 0; i++)
    {
        if (i == 5)
        {
            cout << "You entered a wrong value five times." << endl;
            return 0;
        }
        cout << "Enter a valid assignment value: ";
        cin >> assignment;
    }

    cout << "Enter your final exam result out of 50: ";
    cin >> finalExam;
    for (int i = 1; finalExam > 50 || finalExam < 0; i++)
    {
        if (i == 5)
        {
            cout << "You entered a wrong value 5 times." << endl;
            return 0;
        }
        cout << "Enter a valid final exam value: ";
        cin >> finalExam;
    }

    courseGrade = test + quiz + assignment + finalExam + project;

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