#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("number_groups.txt");
    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int num;
    while (inputFile >> num) {
        vector<int> group;
        int groupSize = num;

        for (int i = 0; i < groupSize; i++) {
            if (inputFile >> num) {
                group.push_back(num);
            } else {
                cout << "Invalid file format." << endl;
                return 1;
            }
        }

        if (groupSize > 0) {
            double sum = 0.0;
            for (int number : group) {
                sum += number;
            }
            double average = sum / groupSize;
            cout << "Average of group size " << groupSize << ": " << average << endl;
        }
    }

    inputFile.close();

    return 0;
}
