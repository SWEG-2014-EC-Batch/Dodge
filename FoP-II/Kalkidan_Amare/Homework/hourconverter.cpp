#include <iostream>
using namespace std;

int input();
void converter(int &hr, int &min);
void output(int &hour, int &min, string &c, int &hr);

int main()
{
    input();
    return 0;
}

int input()
{

    int hr, min;
    cout << "Enter the time in 24 hr notation. First the hour and then the minute: ";
    cin >> hr >> min;
    converter(hr, min);
    char status;
    cout << "Do you want to exit? (Y/N):";
    cin >> status;
    if (status == 'Y' || status == 'y')
    {
        return 0;
    }
    input();
    return 0;
}

void converter(int &hr, int &min)
{
    int hour = hr % 12;
    string c;
    if (hr >= 12)
    {
        c = "PM";
        if (hr == 12)
        {
            hour = 12;
        }
    }
    else
    {
        c = "AM";
        if (hr == 0)
        {
            hour = 12;
        }
    }
    output(hour, min, c, hr);
}

void output(int &hour, int &min, string &c, int &hr)
{
    cout << "The time in 24 hr notation: " << hr << ":" << min << endl;
    cout << "The time in 12 hr notation: " << hour << ":" << min << " " << c << endl;
    cout << "----------------------------------------------------------------\n";
}
