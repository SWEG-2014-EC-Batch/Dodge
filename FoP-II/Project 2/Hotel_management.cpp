#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

const int DAILY_RENT = 100;
const double TAX_RATE = 0.15;
const double SERVICE_CHARGE_RATE = 0.1;

template <typename T>
void displayInfo(const T &obj)
{
    obj.displayInfo();
}

template <typename T>
bool checkAvailability(const T *arr, int size, int value)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i].getRoomNumber() == value)
        {
            return arr[i].isAvailable();
        }
    }
    return false;
}

class Room
{
private:
    char type;
    int roomNumber;
    int capacity;
    bool checkedIn;
    int fromDate;
    int toDate;

public:
    bool available;

    Room(char t = ' ', int num = 0, int r = 0) : type(t), roomNumber(num), capacity(r), available(t != ' '), checkedIn(false) {}

    void displayInfo() const
    {
        cout << "-----------------\nRoom Type: " << type << "\nRoom Number: " << roomNumber << "\nCapacity: " << capacity << "\n"
             << "Available: " << (available ? "Yes" : "No") << "\n"
             << "Checked In: " << (checkedIn ? "Yes" : "No") << "\n";
        if (checkedIn)
        {
            cout << "From Date: " << fromDate << "\nTo Date: " << toDate << "\n";
        }
    }

    int getRoomNumber() const
    {
        return roomNumber;
    }

    bool isCheckedIn() const
    {
        return checkedIn;
    }

    bool isAvailable() const
    {
        return available && !checkedIn;
    }

    void checkIn(int from, int to)
    {
        if (!checkedIn)
        {
            checkedIn = true;
            fromDate = from;
            toDate = to;
        }
    }

    void checkOut()
    {
        checkedIn = false;
    }
};

template <typename T>
void saveRoomInformation(const vector<T> &rooms, const string &filename)
{
    ofstream outFile(filename);

    if (!outFile)
    {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }

    for (const auto &room : rooms)
    {
        outFile << room.getRoomNumber() << " " << room.isAvailable() << " " << room.isCheckedIn() << endl;
    }

    outFile.close();
}

template <typename T>
void loadRoomInformation(vector<T> &rooms, const string &filename)
{
    ifstream inFile(filename);

    if (!inFile)
    {
        cerr << "Failed to open the file for reading." << endl;
        return;
    }

    int roomNumber;
    bool available, checkedIn;

    while (inFile >> roomNumber >> available >> checkedIn)
    {
        T room(' ', roomNumber, 0);
        room.available = available;
        if (checkedIn)
        {
            int fromDate, toDate;
            inFile >> fromDate >> toDate;
            room.checkIn(fromDate, toDate);
        }
        rooms.push_back(room);
    }

    inFile.close();
}