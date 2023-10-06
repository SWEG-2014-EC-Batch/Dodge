#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

class Room
{
    public:
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

};

struct RType
{
    int rType;
    float price;
    string description;
};

class Reservation
{
    public:
        int id;
        string name;
        int phoneNumber;
        string kebeleId;
        int roomNo;
        string checkIn;
        string checkOut;
        string status;
    
    public:
        Reservation(int Id, string& Name, int PhoneNumber, string& KebeleId,  int roomno, const string& chein, const string& cheout,const string& stat)
            : id(Id), name(Name), phoneNumber(PhoneNumber), kebeleId(KebeleId), roomNo(roomno), checkIn(chein), checkOut(cheout), status(stat) {}
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
        string getKebeleId() const
        {
            return kebeleId;
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
        void printTitle() const
        {
            cout << left << setw(10) << "ID" << setw(15) << "Name" << setw(15) << "Phone Number" << setw(15) << "Kebele Id" << setw(15) << "Room Number" 
                << setw(15) << "Check-in" << setw(15) << "Check-out" << setw(15) << "Status" << endl;
            cout << setfill('-') << setw(115) << "-" << setfill(' ') << endl;
        }
        void printRecord() const
        {
            cout << left << setw(10) << id << setw(15) << name << setw(15) << phoneNumber << setw(15) << kebeleId << setw(15) << roomNo
                << setw(15) << checkIn << setw(15) << checkOut << setw(15) << status << endl;
        }
};

class Hotel
{
    private:
        vector<Reservation> reservations;
        vector<Room> rooms;
    public:
        //Hotel.cpp
        Hotel (vector<Reservation> Reservations = {}, vector<Room> Rooms = {}) : reservations(Reservations), rooms(Rooms) {}
        vector<Reservation> getReservations () const;
        vector<Room> getRooms () const;
        void addReservation (char* today);
        bool isValidReservationId(int reservationId) const;
        void deleteReservation();
        void deleteAllReservations();
        void modifyReservation(Hotel rooms, char* today);
        void printReservations() const;
        void checkIn(const char* today);
        bool doesNotOverlap(int roomN, const string& checkIn, const string& checkOut, int id = 0) const;
        bool isValidRoom(int roomN) const;
        void addRoom(const Room& room);
        void saveData() const;
        void loadData();
        void addReservations(const Reservation& reservation);
};

//date.cpp
bool isFuture (const string& checkIn, const char* today);
bool outPastIn(const string& checkIn, const string& checkOut);
int daysStayed (const string&  checkIn, const string& checkOut);

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
template <typename T>
bool compare(const T& a, const T& b)
{
    return (a.getid() < b.getid());
}

template <typename T,typename U>
void sort(T& records, vector<U> (T::*secfun)() const)
{
    sort((records.*secfun)().begin(), (records.*secfun)().end(), compare);
    bool first = true;
    for( const auto& record: (records.*secfun)())
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