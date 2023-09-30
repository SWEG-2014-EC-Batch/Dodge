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

class Customer
{
private:
    string name;
    string address;
    string phone;
    int checkInDate;
    int checkOutDate;
    int roomNumber;

public:
    Customer(const string &n = "", const string &addr = "", const string &ph = "", int from = 0, int to = 0, int room = 0)
        : name(n), address(addr), phone(ph), checkInDate(from), checkOutDate(to), roomNumber(room) {}

    void displayInfo() const
    {
        cout << "-------------------------------\nCustomer Name: " << name << "\nAddress: " << address << "\nPhone: " << phone << "\n";
        cout << "Check-in Date: " << checkInDate << "\nCheck-out Date: " << checkOutDate << "\n"
             << "Room Number: " << roomNumber << "\n--------------------------------\n";
    }

    int getCheckInDate() const
    {
        return checkInDate;
    }

    int getRoomNumber() const
    {
        return roomNumber;
    }

    int getCheckOutDate() const
    {
        return checkOutDate;
    }

    string getName() const
    {
        return name;
    }

    string getAddress() const
    {
        return address;
    }

    string getPhone() const
    {
        return phone;
    }
};

int calculateDays(int checkin, int checkout)
{
    int tempCheckin = checkin;
    int tempCheckout = checkout;

    int yearin = checkin % 10000;
    int monthin = (checkin / 100) % 100;
    int dayin = checkin / 10000;

    int yearout = checkout % 10000;
    int monthout = (checkout / 100) % 100;
    int dayout = checkout / 10000;

    int in = (yearin * 365) + (monthin * 30) + dayin;
    int out = (yearout * 365) + (monthout * 30) + dayout;

    return (out - in);
}

class HotelManagement
{
private:
    vector<Room> rooms;
    vector<Customer> customers;

public:
    void addRoom(const Room &room)
    {
        rooms.push_back(room);
    }

    void addCustomer(const Customer &customer)
    {
        customers.push_back(customer);
    }

    vector<Room> &getRooms()
    {
        return rooms;
    }

    vector<Customer> &getCustomers()
    {
        return customers;
    }

    void displayRooms() const
    {
        for (const auto &room : rooms)
        {
            displayInfo(room);
        }
    }

    void displayCustomers() const
    {
        for (const auto &customer : customers)
        {
            displayInfo(customer);
        }
    }

    bool checkRoomAvailability(int roomNumber) const
    {
        return checkAvailability(rooms.data(), rooms.size(), roomNumber);
    }

    void reserveRoom(int roomNumber, const Customer &customer)
    {
        for (auto &room : rooms)
        {
            if (room.getRoomNumber() == roomNumber)
            {
                if (room.isAvailable())
                {
                    room.checkIn(customer.getCheckInDate(), customer.getCheckOutDate());
                    cout << "Room " << roomNumber << " has been reserved!" << endl;
                    room.available = false;
                    return;
                }
                else
                {
                    cout << "Room " << roomNumber << " is not available for reservation." << endl;
                    return;
                }
            }
        }
        cout << "Room " << roomNumber << " not found." << endl;
    }

    void checkOut(int roomNumber, const Customer &customer)
    {
        for (auto &room : rooms)
        {
            if (room.getRoomNumber() == roomNumber)
            {
                if (room.isCheckedIn())
                {
                    int dayStayed = calculateDays(customer.getCheckInDate(), customer.getCheckOutDate());
                    int RoomRent = DAILY_RENT * dayStayed;
                    int tax = RoomRent * TAX_RATE;
                    int serviceCharge = RoomRent * SERVICE_CHARGE_RATE;

                    cout << "Customer checked out from Room " << roomNumber << "." << endl
                         << "Room Rent: $" << DAILY_RENT << " per day" << endl
                         << "Days Stayed: " << dayStayed << " days" << endl
                         << "Total RoomRent: $" << RoomRent << endl
                         << "Tax: $" << tax << endl
                         << "Service Charge: $" << serviceCharge << endl;
                    cout << "Total Amount Due: $" << RoomRent + tax + serviceCharge << endl;

                    room.checkOut();
                    return;
                }
                else
                {
                    cout << "No customer checked in to Room " << roomNumber << "." << endl;
                    return;
                }
            }
        }
        cout << "Room " << roomNumber << " not found." << endl;
    }
};
