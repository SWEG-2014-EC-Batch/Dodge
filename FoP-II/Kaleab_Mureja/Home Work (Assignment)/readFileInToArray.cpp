#include <fstream>
#include <iostream>
using namespace std;

void readFileIntoArray(const char* fileName, int array[], int* count) {
    ifstream file(fileName);
    if (!file) {
        cout << "Failed to open the file." << endl;
        return;
    }

    *count = 0;
    int num;
    while (file >> num) {
        array[*count] = num;
        (*count)++;
    }

    file.close();
}

int main() {
    const char* fileName = "records.txt";
    int array[100];  // Assuming the array has enough space for the file
    int count;

    readFileIntoArray(fileName, array, &count);

    cout << "Number of entries: " << count << endl;
    cout << "Array contents:" << endl;
    for (int i = 0; i < count; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
