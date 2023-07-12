#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("ws9-5.txt");

    if (!file.is_open())
    {
        cout << "Error opening file." << endl;
        return 0;
    }

    int numItems;
    double sum, average;
    int count = 0;

    while (file >> numItems)
    {
        sum = 0;

        for (int i = 0; i < numItems; i++)
        {
            double number;
            file >> number;
            sum += number;
        }

        average = sum / numItems;
        cout << "Average of Group " << count + 1 << ": " << average << endl;
        count++;
    }

    file.close();

    return 0;
}