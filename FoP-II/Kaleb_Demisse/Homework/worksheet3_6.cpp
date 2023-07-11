#include <iostream>
using namespace std;

struct Coordinate {
    int X;
    int Y;
};

Coordinate readCoordinates() {
    Coordinate coord;
    cout << "Enter the X coordinate: ";
    cin >> coord.X;
    cout << "Enter the Y coordinate: ";
    cin >> coord.Y;
    return coord;
}

void printCoordinates(Coordinate coord) {
    cout << "Coordinate: (" << coord.X << ", " << coord.Y << ")" << endl;
}

int main() {
    Coordinate point = readCoordinates();
    printCoordinates(point);
    return 0;
}
