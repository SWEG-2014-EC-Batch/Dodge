#include <iostream>
#include <fstream>
using namespace std;

void readFileIntoArray(const char* fileName, int array[], int& count) {
    ifstream file(fileName);

    if (file.is_open()) {
        int number;
        count = 0;

        while (file >> number) {
            array[count] = number;
            count++;
        }

        file.close();
    } else {
        cout << "Error opening file." << endl;
    }
}

int main() {
    const char* fileName = "data.txt";
    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];
    int count = 0;

    readFileIntoArray(fileName, numbers, count);

    cout << "Numbers read from the file:" << endl;
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Total numbers read: " << count << endl;

    return 0;
}
