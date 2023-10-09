#include "main.h"

vector<Reservation> Hotel::getReservations () const
{
    return reservations;
}

vector<Room> Hotel::getRooms () const
{
    return rooms;
}

int Hotel::generateId()
{
    srand((time(nullptr))); 
    int newId;
    do {
        newId = rand() % 90000 + 10000; 
    } while (usedResId.find(newId) != usedResId.end());
    usedResId.insert(newId);
    return newId;
}

void Hotel::addReservation ()
{
    int roomNumber, phone;
    string checkin, checkout, name, customerId;
    int choice;
    cout << "Enter Your Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your Phone Number: ";
    cin >> phone;
    cout << "Enter your ID: ";
    cin >> customerId;
    cout << "Enter room number: ";
    cin >> roomNumber;
    if(!isValidRoom(roomNumber))
    {
        cout << "Room doesn't exist. Returning to Main Menu" << endl;
        return;
    }
    cout << "Enter Check-in Date(YYYY-MM-DD): ";
    cin >> checkin;
    if(!isValidDate(checkin))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    if(!isFuture(checkin))
    {
        cout << "The Check-In date must not be in the past.\n\n Returning to Main Menu" << endl;
        return;
    };
    cout << "Enter Check-out Date(YYYY-MM-DD): ";
    cin >> checkout;
    if(!isValidDate(checkout))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    if(!isPastOf(checkin, checkout))
    {
        cout << "The check out date must not be before or on the same day as the check-in date\n\n Returning to Main Menu" << endl;
        return;
    };
    if(!doesNotOverlap(roomNumber, checkin, checkout))
    {
        cout << "The room you want is already booked within this period of time \n\n Returning to Main Menu" << endl;
        return;
    };
    int id = generateId();
    reservations.push_back({id, name, phone, customerId, roomNumber, checkin, checkout, "Reserved"});

    cout << "\nReservation added successfully. Reservation ID is " << id << endl;

}

void Hotel::modifyReservation() 
{
    int reservationId;
    char choice;
    cout << "Enter reservation ID: ";
    cin >> reservationId;

    for (int i = 0; i < reservations.size(); ++i) 
    {
        if (reservations[i].getId() == reservationId) 
        {
            if(!(isFuture(reservations[i].getCheckIn())))
            {
                cout << "Changing reservations is prohibited after the check-in date has passed." <<endl;
                return;
            }
            string name = reservations[i].getName();
            int phone = reservations[i].getPhone();
            string custId = reservations[i].getCustomerId();
            int roomNo = reservations[i].getRoomNo();
            string checkIn = reservations[i].getCheckIn();
            string checkOut = reservations[i].getCheckOut();
            cout << "Do you want to change the name? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, name);
            }
            cout << "Do you want to change the phone number? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new phone number: ";
                cin >> phone;
            }
            cout << "Do you want to change the ID? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new ID: ";
                cin >> custId;
            }          
            cout << "Do you want to change the room? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new room number: ";
                cin >> roomNo;
                if(!isValidRoom(roomNo))
                {
                    cout << "Room " << roomNo << " doesn't exist. Reservation change cancelled." << endl;
                    return;
                }

            }
            cout << "Do you want to change the check-in date? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new check-in date(YYYY-MM-DD): ";
                cin >> checkIn;
                if(!isValidDate(checkIn))
                {
                    cout << "Invalid Date" << endl;
                    return;
                }
                if(!isFuture(checkIn))
                {
                    cout << "Check-In Date must not be in the past. Reservation change cancelled. " << endl;
                    return;
                }
            }
            cout << "Do you want to change the check-out date? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new check-out date(YYYY-MM-DD): ";
                cin >> checkOut;
                if(!isValidDate(checkOut))
                {
                    cout << "Invalid Date" << endl;
                    return;
                }
            }
            if(!isPastOf(checkIn, checkOut))
            {
                cout << "Check-out date must not be before or on the same day as the check-in date. Reservation change cancelled. "<< endl;
                return;
            }
            if(!doesNotOverlap(roomNo, checkIn, checkOut, reservationId))
            {
                cout << "The room is already booked on some days. Reservation change cancelled." << endl;
                return;
            }
            reservations[i].setName(name);
            reservations[i].setPhoneNumber(phone);
            reservations[i].setCustomerId(custId);
            reservations[i].setRoomNo(roomNo);
            reservations[i].setCheckIn(checkIn);
            reservations[i].setCheckOut(checkOut);

            cout << "Reservation with ID " << reservationId << " has been modified successfully." << endl;
            return;
        }
    }
    cout << "Reservation with ID " << reservationId << " not found." << endl;
}

void Hotel::deleteReservation() 
{
    int id;
    cout << "Enter reservation ID: ";
    cin >> id;
    for(int i = 0; i < reservations.size(); ++i)
    {
        if (reservations[i].getId() == id) 
        {
            if(!isFuture(reservations[i].getCheckIn()))
            {
                cout << "Deleting Reservation is prohibited after check-in date has passed. " << endl;
            }
            reservations.erase(reservations.begin() + i);
            cout << "Reservation with ID " << id << " has been deleted successfully." << endl;
            return;
        }
    }
    cout << "Reservation with ID " << id << " not found." << endl;
}

void Hotel::deleteAllReservations() 
{
    reservations.clear();
}

void Hotel::checkIn()
{
    int reservationId;
    cout << "Enter reservation ID: ";
    cin >> reservationId;
    for ( Reservation& reservation : reservations) 
    {
        if (reservation.getId() == reservationId) 
        {
            if(reservation.getstatus() != "Reserved")
            {
                cout << "Error: Reservation status was not \"Reserved\". " << endl;
                return;
            }
            reservation.setStatus("Checked-In");
            int dayStayed = daysStayed(reservation.getCheckIn(), reservation.getCheckOut());
            int dailyRate = dailyPrice(reservation.getRoomNo());

            cout << "Customer checked into Room " << reservation.getRoomNo() << "." << endl << endl
                 << "Room price: $" << dailyRate << " per day" << endl
                 << "Days Reserved: " << dayStayed << " days" << endl
                 << "Total Stay Price: $" << dayStayed * dailyRate  << endl;
            return;
        }
    }
    cout << "Reservation ID " << reservationId << " not found" << endl;
    return;    
}

bool Hotel::doesNotOverlap(int roomN, const string& checkIn, const string& checkOut, int id) const
{
    for (const Reservation& reservation : reservations)
    {
        if(reservation.getRoomNo() == roomN && reservation.getId() != id)
        {
            if(!(checkOut <= reservation.getCheckIn() || checkIn >= reservation.getCheckOut()))
                return false;
        }
    }
    return true;
}

bool Hotel::isValidRoom(int roomN) const
{
    for (const Room& room : rooms) 
    {
        if (room.getRoomNo() == roomN) 
        {
            return true;
        }
    }
    return false;
}

void Hotel::addRoom(const Room& room) {
    rooms.push_back(room);
}

void Hotel::addReservations(const Reservation& reservation)
{
    reservations.push_back(reservation);
}

void Hotel::saveData() const {
    ofstream fout("hotel.txt", ios::out);
    if (fout) {
        for (const Reservation& reservation : reservations) {
            fout << reservation.getId() << "," << reservation.getName() << "," << reservation.getPhone() << ","
                    << reservation.getCustomerId() << "," << reservation.getRoomNo() << ","
                    << reservation.getCheckIn() << "," << reservation.getCheckOut() << ","
                    << reservation.getstatus() << endl;
        }
        fout.close();
    } else {
        cout << "Unable to save data" << endl;
    }
}

void Hotel::loadData() 
{
    ifstream fin("hotel.txt", ios::in);
    if (fin) {
        reservations.clear(); 
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            string id, name, phone, customerId, roomNo, checkIn, checkOut, status;

            if (getline(ss, id, ',') && getline(ss, name, ',') && getline(ss, phone, ',') &&
                getline(ss, customerId, ',') && getline(ss, roomNo, ',') && 
                getline(ss, checkIn, ',') && getline(ss, checkOut, ',') && getline(ss, status, ',')) 
            {

                int intId = stoi(id);
                int intPhone = stoi(phone);
                int intRoomNo = stoi(roomNo);

                addReservations({intId, name, intPhone, customerId, intRoomNo, checkIn, checkOut, status});
            } 
            else 
            {
                cout << "Invalid data format in the file." << endl;
            }
        }
        fin.close();
    }
    else 
    {
        cout << "Error: Unable to open the file." << endl;
    }
}

set<int> Hotel::busyRooms(const string& checkin, const string& checkout)
{
    set<int> roomNumbers;
    
    for (const Reservation& reservation : reservations)
    {
        if(!(checkin > reservation.getCheckOut() || checkout < reservation.getCheckIn()))
        {
            roomNumbers.insert(reservation.getRoomNo());
        }
    }
    return roomNumbers;
}

void Hotel::checkAvailableRoom()
{
    string checkin, checkout;
    cout << "Enter check-in date(YYYY-MM-DD): ";
    cin >> checkin;
    if(!isValidDate(checkin))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    cout << "Enter check-out date(YYYY-MM-DD): ";
    cin >> checkout;
    if(!isValidDate(checkout))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    if(checkin > checkout)
    {
        cout << "End date can't be before start date" << endl;
        return;
    }
    set<int> busyRoom = busyRooms(checkin, checkout);
    bool first = true;
    for (const Room& room: rooms)
    {
        if(busyRoom.find(room.getRoomNo()) == busyRoom.end())
        {
            if(first)
            {
                room.printTitle();
                first = false;
            }
            room.printRecord();
        }
    }
    if(first)
        cout << "No rooms available within this time period." << endl;
}

float Hotel::dailyPrice (int roomNo)
{
    for(const Room& room: rooms)
    {
        if(roomNo == room.getRoomNo())
        {
            for (const RType& roomtype: roomTypes)
            {
                if(room.getRType() == roomtype.rType)
                    return roomtype.price;
            }
        }
    }
    return 0;
}

void Hotel::checkOut()
{
    int reservationId;
    cout << "Enter reservation ID: ";
    cin >> reservationId;
    for(Reservation& reservation: reservations)
    {
        if(reservationId == reservation.getId())
        {
            if(reservation.getstatus() != "Checked-In")
            {
                cout << "Can't check out a reservation that is not currently checked in" << endl;
                return;
            }
            reservation.setStatus("Checked-Out");
            cout << "\tCheck Out Successful\n Thank you for choosing to stay with us!" << endl;
            return;
        }
    }
    cout << "There is no reservation with ID " << reservationId << "." << endl;
}

map<int, int> Hotel::occupancy (const string& start, const string& end)
{
    
    int occ;
    map<int, int> roomOcc;

    for(const Room& room: rooms)
        roomOcc[room.getRoomNo()] = 0;
    for (const Reservation& reservation: reservations)
    {
        if(!(start >= reservation.getCheckOut() || end <= reservation.getCheckIn()))
        {
            if(reservation.getCheckIn() > start)
            {
                if(reservation.getCheckOut() < end)
                    occ = daysStayed(reservation.getCheckIn(), reservation.getCheckOut()) + 1;
                else
                    occ = daysStayed(reservation.getCheckIn(), end) + 1;
            } else {
                if(reservation.getCheckOut() < end)
                    occ = daysStayed(start, reservation.getCheckOut()) + 1;
                else
                    occ = daysStayed(start, end) + 1;
            }

            roomOcc[reservation.getRoomNo()] += occ;
        }
    }
    roomOcc[0] = daysStayed(start, end) + 1;
    return roomOcc;
}

void Hotel::printOccupancy()
{
    string start, end;
    cout << "Enter start date(YYYY-MM-DD): ";
    cin >> start;
    if(!isValidDate(start))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    cout << "Enter end date(YYYY-MM-DD): ";
    cin >> end;
    if(!isValidDate(end))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    if(start > end)
    {
        cout << "End date can't be before start date" << endl;
        return;
    }
    map<int,int> print = occupancy(start, end);
    int total = 0;

    cout << left << setw(10) << "Room" << setw(10) << "Days" << setw(20) << "Occupancy Rate(%)" << endl;
    cout << setfill('-') <<setw(40) << "-" << setfill(' ') <<endl;
    
    auto iter = print.begin();
    ++iter;

    for (; iter != print.end(); ++iter) 
    {
        int roomNumber = iter->first;
        int daysOccupied = iter->second;
        double occupancyRate = ((double)(daysOccupied) / print[0]) * 100.0;

        total += daysOccupied;

        cout << left << setw(10) << roomNumber << setw(10) << daysOccupied << setw(20) 
             << fixed << setprecision(2) << occupancyRate << endl;
    }

    double avgOcc = ((double)(total)/(print[0]*print.size())) * 100;

    cout << setfill('-') <<setw(40) << "-" << setfill(' ') <<endl;
    cout << left << setw(10) << "TOTAL" << setw(10) << total << setw(20) << fixed << setprecision(2) <<avgOcc << endl;
}

map<string, double> Hotel::dailyRevenues(const string& start, const string& end)
{
    
    map <string, double> dailyRevenue;
    vector<string> betweendays = generateDateRange(start, end);
    for(const string& day: betweendays)
        dailyRevenue[day] = 0.0;

    for (const Reservation& reservation: reservations)
    {
        if(start <= reservation.getCheckIn() && end >= reservation.getCheckIn() && reservation.getstatus() == "Checked-In")
        {
            double reservationRevenue = daysStayed(reservation.getCheckIn(), reservation.getCheckOut()) * dailyPrice(reservation.getRoomNo());
            dailyRevenue[reservation.getCheckIn()] += reservationRevenue; 
        }
    }
    return dailyRevenue;
}

void Hotel::printRevenue()
{
    string start, end;
    cout << "Enter start date(YYYY-MM-DD): ";
    cin >> start;
    if(!isValidDate(start))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    cout << "Enter end date(YYYY-MM-DD): ";
    cin >> end;
    if(!isValidDate(end))
    {
        cout << "Invalid Date" << endl;
        return;
    }
    if(start > end)
    {
        cout << "End date can't be before start date" << endl;
        return;
    }
    map<string,double> print = dailyRevenues(start, end);
    double total = 0.0;

    cout << left << setw(15) << "Date" << setw(15) << "Revenue" << endl;
    cout << setfill('-') <<setw(30) << "-" << setfill(' ') <<endl;    

    for (auto iter = print.begin(); iter != print.end(); ++iter) 
    {
        total += iter->second;

        cout << left << setw(15) << iter->first << setw(15) << fixed << setprecision(2) << iter->second << endl;
    }
    cout << setfill('-') <<setw(30) << "-" << setfill(' ') <<endl;
    cout << left << setw(15) << "TOTAL" << setw(15) << fixed << setprecision(2) << total << endl;

}