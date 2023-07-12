#include <iostream>
#include <fstream>
using namespace std;

void read(const char *fileName, int *array, int *count)
{
    ifstream file(fileName);
    if (!file)
    {
        cout << "Error opening file: " << fileName << endl;
        return;
    }

    int entry;
    *count = 0;
    while (file >> entry)
    {
        array[*count] = entry;
        (*count)++;
    }

    file.close();
}

int main()
{
    const char *fileName = "data.txt";
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int count = 0;

    read(fileName, numbers, &count);

    cout << "Numbers read from the file:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Total numbers read: " << count << endl;

    return 0;
}
