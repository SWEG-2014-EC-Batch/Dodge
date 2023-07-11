#include <iostream>
#include <iomanip>
using namespace std;

struct Student {
    string id;
    string name;
    float testMark;
    float finalMark;
    float totalMark;
};

int main() {
    int num;
    cout << "Enter the number of students: ";
    cin >> num;

    Student* students = new Student[num];

    for (int i = 0; i < num; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Test Mark: ";
        cin >> students[i].testMark;
        cout << "Final Mark: ";
        cin >> students[i].finalMark;
        cout << endl;

        students[i].totalMark = students[i].testMark + students[i].finalMark;
    }
    cout << endl;
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(15) << "Test Mark" << setw(15) << "Final Mark" << setw(15) << "Total Mark" << endl;
 

    for (int i = 0; i < num; i++) {
        cout <<left << setw(10) << students[i].id << setw(20) << students[i].name << setw(15) << students[i].testMark << setw(15) << students[i].finalMark << setw(15) << students[i].totalMark << endl;
    }

    cout << endl;

    delete[] students;

    return 0;
}