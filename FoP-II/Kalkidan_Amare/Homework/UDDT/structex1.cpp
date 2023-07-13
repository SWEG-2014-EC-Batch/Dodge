#include <iostream>
#include <iomanip>
using namespace std;

struct student
{
    string id;
    string name;
    float *testMark;
    float final_mark;
};
int main()
{
    int num, x;
    cout << "enter the number of students: " << endl;
    cin >> num;
    cout << "enter the number of test mark:\n";
    cin >> x;

    student *std = new student[num];

    for (int i = 0; i < num; i++)
    {
        std[i].testMark = new float[x];
        cout << "Enter the student" << i + 1 << "\nId: ";
        cin >> std[i].id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, std[i].name);
        cout << "Final_Mark: ";
        cin >> std[i].final_mark;

        for (int j = 0; j < x; j++)
        {
            cout << "Enter the test mark: " << j + 1 << endl;
            cin >> std[i].testMark[j];
        }
    }
    cout << left << setw(5) << "Id" << setw(15) << "Name"
         << "Total" << endl;

    for (int i = 0, sum = 0; i < num; i++, sum = 0)
    {
        for (int j = 0; j < x; j++)
        {
            sum += std[i].testMark[j];
        }
        cout << setw(5) << std[i].id << setw(15) << std[i].name << sum + std[i].final_mark << "\n";
    }
    for (int i = 0; i < num; i++)
    {
        delete[] std[i].testMark;
    }

    delete[] std;
}