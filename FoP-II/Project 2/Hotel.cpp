#include "main.h"

vector<Reservation> Hotel::getReservations () const
{
    return reservations;
}

vector<Room> Hotel::getRooms () const
{
    return rooms;
}

void Hotel::addReservation (char* today)
{
    int customerId, roomNumber, phone;
    string checkin, checkout, name, kebeleId;
    int choice;
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter your Phone Number: ";
    cin >> phone;
    cout << "Enter your Kebele Id: ";
    cin >> kebeleId;
    cout << "Enter room number: ";
    cin >> roomNumber;
    if(!isValidRoom(roomNumber))
    {
        cout << "Room doesn't exist. Returning to Main Menu" << endl;
        return;
    }
    cout << "Enter Check-in Date(YYYY-MM-DD): ";
    cin >> checkin;
    if(!isFuture(checkin, today))
    {
        cout << "The Check-In date must not be in the past.\n\n Returning to Main Menu" << endl;
        return;
    };
    cout << "Enter Check-out Date(YYYY-MM-DD): ";
    cin >> checkout;
    if(!outPastIn(checkin, checkout))
    {
        cout << "The check out date must not be before or on the same day as the check-in date\n\n Returning to Main Menu" << endl;
        return;
    };
    if(!doesNotOverlap(roomNumber, checkin, checkout))
    {
        cout << "The room you want is already booked within this period of time \n\n Returning to Main Menu" << endl;
        return;
    };
    static int count = 1;
    reservations.push_back({count, name, phone, kebeleId, roomNumber, checkin, checkout, "Reserved"});

    cout << "\nReservation added successfully. Reservation ID is " << count << endl;
        count++;
}

void Hotel::modifyReservation(Hotel rooms, char* today) 
{
    int reservationId;
    char choice;
    cout << "Enter reservation ID: ";
    cin >> reservationId;

    for (size_t i = 0; i < reservations.size(); ++i) 
    {
        if (reservations[i].id == reservationId) 
        {
            int roomNo = reservations[i].roomNo;
            string checkIn = reservations[i].checkIn;
            string checkOut = reservations[i].checkOut;

            cout << "Do you want to change the room? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new room number: ";
                cin >> roomNo;
                if(!rooms.isValidRoom(roomNo))
                {
                    cout << "Room " << roomNo << " doesn't exist. Reservation change cancelled." << endl;
                    return;
                }

            }
            cout << "Do you want to change the check-in date? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new check-in date: ";
                cin >> checkIn;
                if(!isFuture(checkIn, today))
                {
                    cout << "Check-In Date must not be in the past. Reservation change cancelled. " << endl;
                    return;
                }
            }
            cout << "Do you want to change the check-out date? (y/n): ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "Enter new check-out date: ";
                cin >> checkOut;
            }
            if(!outPastIn(checkIn, checkOut))
            {
                cout << "Check-out date must not be before or on the same day as the check-in date. Reservation change cancelled. "<< endl;
                return;
            }
            if(!doesNotOverlap(roomNo, checkIn, checkOut, reservationId))
            {
                cout << "The room is already booked on some days. Reservation change cancelled." << endl;
                return;
            }
            reservations[i].roomNo = roomNo;
            reservations[i].checkIn = checkIn;
            reservations[i].checkOut = checkOut;

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

    auto del = reservations.begin();
    for(; del != reservations.end(); ++del) 
    {
        if (del->id == id) 
        {
            del = reservations.erase(del);
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

void Hotel::printReservations() const
{
    reservations[0].printTitle();
    for (const Reservation& reservation : reservations) 
    {
        reservation.printRecord();
    }
}

void Hotel::checkIn(const char* today)
{
    int reservationId;
    cout << "Enter reservation ID: ";
    cin >> reservationId;
    for ( Reservation& reservation : reservations) 
    {
        if (reservation.id == reservationId) 
        {
            reservation.status = "Checked In";
            return;
        }
    }
    cout << "No ID found" << endl;
    return;    
}

bool Hotel::doesNotOverlap(int roomN, const string& checkIn, const string& checkOut, int id) const
{
    for (const Reservation& reservation : reservations)
    {
        if(reservation.roomNo == roomN && reservation.id != id)
        {
            if(!(strcmp(checkOut.c_str(), reservation.checkIn.c_str()) < 0 || strcmp(checkIn.c_str(), reservation.checkOut.c_str()) > 0))
                return false;
        }
    }
    return true;
}

bool Hotel::isValidRoom(int roomN) const
{
    for (const Room& room : rooms) 
    {
        if (room.roomNo == roomN) 
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
    ofstream outfile("hotel.txt");
    if (outfile.is_open()) {
        for (const Reservation& reservation : reservations) {
            outfile << reservation.getId() << "\t" << reservation.getName() << "\t" << reservation.getPhone() << "\t"
                    << reservation.getKebeleId() << "\t" << reservation.getRoomNo() << "\t"
                    << reservation.getCheckIn() << "\t" << reservation.getCheckOut() << "\t"
                    << reservation.getstatus() << endl;
        }
        outfile.close();
        cout << "Data saved successfully." << endl;
    } else {
        cout << "Error: Unable to save data." << endl;
    }
}

void Hotel::loadData() 
{
    ifstream fin("hotel.txt");
    if (fin.is_open()) {
        reservations.clear(); 
        string line;
        while (getline(fin, line)) {
            stringstream ss(line);
            int id, phone, roomNo;
            string name, kebeleId, checkIn, checkOut, status;

            if (ss >> id >> name >> phone >> kebeleId >> roomNo >> checkIn >> checkOut >> status) {
                addReservations({id, name, phone, kebeleId, roomNo, checkIn, checkOut, status});
            } else {
                cout << "Error: Invalid data format in the file." << endl;
            }
        }
        fin.close();
        cout << "Data loaded successfully." << endl;
    } else {
        cout << "Error: Unable to open the file." << endl;
    }
}
