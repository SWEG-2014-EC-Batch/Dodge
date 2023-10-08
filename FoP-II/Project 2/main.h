#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
#include <map>

using namespace std;

class Room
{
    private:
        int roomNo;
        int rType;
    
    public:
        Room(int roomno, int rtype): roomNo(roomno), rType(rtype) {}

        int getRoomNo() const
        {
            return roomNo;
        }
        int getRType() const
        {
            return rType;
        }
        void printTitle() const
        {
            cout << left << setw(15) << "Room Number" << setw(15) << "Room Level" << endl;
            cout << setfill('-') <<setw(30) << "-" << setfill(' ') <<endl;
        }
        void printRecord() const
        {
            cout << left << setw(15) << roomNo << setw(15) << rType << endl;
        }


};

struct RType
{
    int rType;
    float price;
    string description;
};

class Reservation
{
    private:
        int id;
        string name;
        int phoneNumber;
        string customerId;
        int roomNo;
        string checkIn;
        string checkOut;
        string status;
    
    public:
        Reservation(int Id, string& Name, int PhoneNumber, string& KebeleId,  int roomno, const string& chein, const string& cheout,const string& stat)
            : id(Id), name(Name), phoneNumber(PhoneNumber), customerId(KebeleId), roomNo(roomno), checkIn(chein), checkOut(cheout), status(stat) {}
        int getId() const
        {
            return id;
        }
        string getName() const
        {
            return name;
        }
        int getPhone() const
        {
            return phoneNumber;
        }
        string getCustomerId() const
        {
            return customerId;
        }
        int getRoomNo() const
        {
            return roomNo;
        }
        string getCheckIn() const
        {
            return checkIn;
        }
        string getCheckOut() const
        {
            return checkOut;
        }
        string getstatus() const
        {
            return status;
        }
        void setId(int newId) 
        {
            id = newId;
        }
        void setName(const string& newName) 
        {
            name = newName;
        }
        void setPhoneNumber(int newPhoneNumber) 
        {
            phoneNumber = newPhoneNumber;
        }
        void setCustomerId(const string& newCustomerId) 
        {
            customerId = newCustomerId;
        }
        void setRoomNo(int newRoomNo) 
        {
            roomNo = newRoomNo;
        }
        void setCheckIn(const string& newCheckIn)
        {
            checkIn = newCheckIn;
        }
        void setCheckOut(const string& newCheckOut) 
        {
            checkOut = newCheckOut;
        }
        void setStatus(const string& newStatus) 
        {
            status = newStatus;
        }
        void printTitle() const
        {
            cout << left << setw(10) << "ID" << setw(15) << "Name" << setw(15) << "Phone Number" << setw(15) << "Kebele Id" << setw(15) << "Room Number" 
                << setw(15) << "Check-in" << setw(15) << "Check-out" << setw(15) << "Status" << endl;
            cout << setfill('-') << setw(115) << "-" << setfill(' ') << endl;
        }
        void printRecord() const
        {
            cout << left << setw(10) << id << setw(15) << name << setw(15) << phoneNumber << setw(15) << customerId << setw(15) << roomNo
                << setw(15) << checkIn << setw(15) << checkOut << setw(15) << status << endl;
        }
};

class Hotel
{
    private:
        vector<Reservation> reservations;
        vector<Room> rooms;
        set<int> usedResId;
    public:
        vector<RType> roomTypes = {
            {1, 100.00, "Standard Room"},
            {2, 150.00, "Deluxe Room"},
            {3, 250.00, "Family Suite"}
        };
        
        //Hotel.cpp
        Hotel (vector<Reservation> Reservations = {}, vector<Room> Rooms = {}) : reservations(Reservations), rooms(Rooms) {}
        vector<Reservation> getReservations () const;
        vector<Room> getRooms () const;
        int generateId();
        void addReservation ();
        void deleteReservation();
        void deleteAllReservations();
        void modifyReservation();
        void checkIn();
        bool doesNotOverlap(int roomN, const string& checkIn, const string& checkOut, int id = 0) const;
        bool isValidRoom(int roomN) const;
        void addRoom(const Room& room);
        void saveData() const;
        void loadData();
        void addReservations(const Reservation& reservation);
        set<int> busyRooms();
        float dailyPrice (int roomNo);
        void checkAvailableRoom();
        void checkOut();
        map <int, int> occupancy();
        void printOccupancy();
        map<string, double> dailyRevenues();
        void printRevenue();

};

//date.cpp
bool isFuture (const string& checkIn);
bool isPastOf(const string& checkIn, const string& checkOut);
int daysStayed (const string&  checkIn, const string& checkOut);
vector<string> generateDateRange(const string& startDate, const string& endDate);

//about.cpp
void about();

template <typename T,typename U, typename Z>
void search(T& records, Z (U::*func)() const, const Z& value, vector<U> (T::*secfun)() const)
{
    bool found = false;
    for( const auto& record: (records.*secfun)())
    {
        if ((record.*func)() == value)
        {
            if(!found)
            {
                record.printTitle();
                found = true;
            }
            record.printRecord();
        }
    }
    if(!found)
    {
        cout <<"No matching result found.\n" << endl;
    }
}

template <typename T,typename U>
void printSorted(T& records, vector<U> (T::*secfun)() const, bool asc = true)
{
    vector<U> rec = (records.*secfun)();
    if(asc)
        sort(rec.begin(), rec.end(), [](const Reservation& a, const Reservation& b) {
            return a.getId() < b.getId();
        });
    else
        sort(rec.begin(), rec.end(), [](const Reservation& a, const Reservation& b) {
            return a.getId() > b.getId();
        });
    bool first = true;
    for( const auto& record: rec)
    {
        if(first)
        {
            record.printTitle();
            first = false;
        }
        record.printRecord();
    }
}

#endif /*MAIN_H*/