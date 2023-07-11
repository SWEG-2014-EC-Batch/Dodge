#include <iostream>

using namespace std;

void input(int& Hours, int& Minutes);
void convert(int& Hours, char& AmPm);
void output(int Hours, int Minutes, char AmPm);

int main() {
    
    char Choice;
    do {
        int Hours, Minutes;
        char AmPm;

        input(Hours, Minutes);

        convert(Hours, AmPm);

        output(Hours, Minutes, AmPm);


        cout << "Do you want to continue (y/n)? ";
        cin >> Choice;
    } while (Choice != 'n');

    return 0;
}
void input(int& Hours, int& Minutes) {
    cout << "Enter the time in 24-hour notation (hh:mm): ";
    cin >> Hours >> Minutes;
}

void convert(int& Hours, char& AmPm) {
    if (Hours >= 12) {
        AmPm = 'P';
        Hours -= 12;
    } else {
        AmPm = 'A';
    }
}

void output(int Hours, int Minutes, char AmPm) {
    cout << "The time in 12-hour notation is " << Hours << ":" << Minutes << " " << AmPm << endl;
}