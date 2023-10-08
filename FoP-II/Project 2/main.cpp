#include "main.h"

int main ()
{
    int choice = 1, choice2 = 1, choice3 = 1, choice4= 1;;
    int roomNumber, customerId, reservationId;
    string checkin, checkout, name, status;

    Hotel hotel;

    for (int i = 1; i < 21; ++i)
    {
        hotel.addRoom({i, (i % 3) + 1});
    }

    hotel.loadData();

    string adminPassword = "0000";
    string test = " ";

    cout << "\n==============================\n"
            "    WELCOME TO DODGE HOTEL\n"
            "==============================\n";

    while (choice)
    {
        cout << "\tMAIN MENU\n\n";
        cout << "1. Guest\n";
        cout << "2. Admin\n";
        cout << "3. About Hotel\n";
        cout << "0. Exit\n";
        cin >> choice;
        cout << endl;
        choice2 = 1;
        switch(choice)
        {
            case 1: //guest
                while(choice2)
                {
                    cout << "\tGUEST MENU\n\n";
                    cout << "1. Check Available Rooms\n";
                    cout << "2. Reservations\n";
                    cout << "3. Check-In\n";
                    cout << "4. Check-Out\n";
                    cout << "0. Return to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> choice2;
                    cout << endl;
                    choice3 = 1;
                    switch(choice2)
                    {
                        case 1:
                            hotel.checkAvailableRoom();
                            break;
                        case 2:
                            while(choice3)
                            {
                                cout << "\tRESERVATION MENU\n\n";
                                cout << "1. Add reservation\n";
                                cout << "2. Change reservation\n";
                                cout << "3. Delete reservation\n";
                                cout << "0. Return to previous menu\n";
                                cout << "Enter your choice: ";
                                cin >> choice3;
                                cout << endl;
                                switch(choice3)
                                {
                                    case 1:
                                        hotel.addReservation();
                                        break;
                                    case 2:
                                        hotel.modifyReservation();
                                        break;
                                    case 3:
                                        hotel.deleteReservation();
                                        break;
                                    case 0:
                                        break;
                                    default:
                                        cout << "Invalid choice. Please input a proper value." << endl;
                                }
                            }
                            break;
                        case 3:
                            hotel.checkIn();
                            break;
                        case 4:
                            hotel.checkOut();
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice. Please input a proper value." << endl;

                    }
                }
                break;
            case 2: //admin
                cout << "Enter the admin Password: ";
                cin >> test;
                if(adminPassword != test)
                {
                    cout << "Wrong Password" << endl;
                    break;
                }

                while(choice2)
                {
                    cout << "\tADMINSTRATOR MENU\n\n";
                    cout << "1. Reservations\n";
                    cout << "2. Statistics\n";
                    cout << "0. Return to main" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice2;
                    cout << endl;
                    choice3 = 1;
                    switch(choice2)
                    {
                        case 1:
                            while(choice3)
                            {
                                cout << "\tRESERVATION MENU\n\n";
                                cout << "1. Delete all reservations\n";
                                cout << "2. Search through reservations\n";
                                cout << "3. List all reservations\n";
                                cout << "0. Return to previous menu\n";
                                cout << "Enter your choice: ";
                                cin >> choice3;
                                cout << endl;
                                choice4 = 1;
                                switch(choice3)
                                {
                                    case 1:
                                        hotel.deleteAllReservations();
                                        break;
                                    case 2:
                                        while(choice4)
                                        {
                                            cout << "\tSEARCH RESERVATION\n\n";
                                            cout << "1. Search by reservation ID\n";
                                            cout << "2. Search by customer name\n";
                                            cout << "3. Search by room number\n";
                                            cout << "4. Search by check-in date\n";
                                            cout << "5. Search by check-out date\n";
                                            cout << "6. Search by status\n";
                                            cout << "7. Return to previous Menu\n";
                                            cout << "Enter Choice: ";
                                            cin >> choice4;
                                            switch(choice4)
                                            {
                                                case 1:
                                                    cout << "Enter  reservation Id: ";
                                                    cin >> customerId;
                                                    search (hotel, &Reservation::getId, customerId, &Hotel::getReservations);
                                                    break;
                                                case 2:
                                                    cout << "Enter Customer Name: ";
                                                    cin >> name;
                                                    search (hotel, &Reservation::getName, name, &Hotel::getReservations);
                                                    break;
                                                case 3:
                                                    cout << "Enter Room Number: ";
                                                    cin >> roomNumber;
                                                    search (hotel, &Reservation::getRoomNo, roomNumber, &Hotel::getReservations);
                                                    break;
                                                case 4:
                                                    cout << "Enter Check-in date(YYYY-MM-DD): ";
                                                    cin >> checkin;
                                                    search (hotel, &Reservation::getCheckIn, checkin, &Hotel::getReservations);
                                                    break;
                                                case 5:
                                                    cout << "Enter Check-out date(YYYY-MM-DD): ";
                                                    cin >> checkout;
                                                    search (hotel, &Reservation::getCheckOut, checkout, &Hotel::getReservations);
                                                    break;
                                                case 6:
                                                    cout << "Enter Status: ";
                                                    cin >> status;
                                                    search (hotel, &Reservation::getstatus, status, &Hotel::getReservations);
                                                    break;
                                                case 7:
                                                    break;
                                                default:
                                                    cout << "Invalid choice. Please input a proper value." << endl;
                                            }
                                        }
                                        break;
                                    case 3:
                                        while(choice4)
                                        {
                                            cout << "\tLIST RESERVATIONS\n\n";
                                            cout << "1. Sorted by Reservation ID\n";
                                            cout << "2. Sorted by Reservation ID in descending\n";
                                            cout << "0. Return to Previous Menu\n";
                                            cout << "Enter your choice: ";
                                            cin >> choice4;
                                            switch(choice4)
                                            {
                                                case 1:
                                                    printSorted(hotel, &Hotel::getReservations);
                                                    break;
                                                case 2:

                                                    printSorted(hotel, &Hotel::getReservations, false);                                                    break;
                                                case 0:
                                                    break;
                                                default:
                                                    cout << "Invalid choice. Please input a proper value." << endl;
                                            }
                                        }
                                        break;
                                    case 0:
                                        break;
                                    default:
                                        cout << "Invalid choice. Please input a proper value." << endl;
                                }
                            }
                            break;
                        case 2:
                            while(choice3)
                            {
                                cout << "\tREPORTS MENU\n\n";
                                cout << "1. Occupancy Rate\n";
                                cout << "2. Total Revenue\n";
                                cout << "0. Return to previous menu\n";
                                cout << "Enter your choice: ";
                                cin >> choice3;
                                switch(choice3)
                                {
                                    case 1:
                                        hotel.printOccupancy();
                                        break;
                                    case  2:
                                        hotel.printRevenue();
                                        break;
                                    case 0:
                                        break;
                                    default:
                                        cout << "Invalid choice. Please input a proper value." << endl;
                                }
                            }
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Invalid choice. Please input a proper value." << endl;
                    }
                }
                break;
            case 3:
                about();
                break;
            case 0:
                hotel.saveData();
                break;
        }
    }
    return 0;
}