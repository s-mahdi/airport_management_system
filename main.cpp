#include <iostream>
#include <ctime>
#include <string>

using namespace std;

class Ticket {
public:
    Ticket(int flightNumber, time_t flightDate) : flightNumber(flightNumber), flightDate(flightDate) {}

private:
    int flightNumber;
    time_t flightDate;
    time_t flightTime;
    string origin;
    string destination;
    string passengerName;
    string passengerLastName;
    long long int passengerID;
    int planeSerial;
    int ticketPrice;
};

class Passenger {
private:
    string name;
    string lastName;
    string parentName;
    long long ID;
    time_t birthday;

};

class Plane {
private:
    int planeSerial;
    int numberOfSeats;
};

class Flight {
private:
    int flightNumber;
    int planeSerial;
    string origin;
    string destination;
    time_t date;
    time_t time;
    int numberOfPassengers;

public:
    Flight(int flightNumber, int planeSerial, const string &origin, const string &destination, time_t date, time_t time,
           int numberOfPassengers) : flightNumber(flightNumber), planeSerial(planeSerial), origin(origin),
                                     destination(destination), date(date), time(time),
                                     numberOfPassengers(numberOfPassengers) {}

};

void show_menu();

void addFlight();

void addTicket();

void removeFlight();

void removeTicket();

void editFlight();

void editPassenger();

void flightReport();

void passengerList();

int main() {
    int item = 0;
    while (true) {
        show_menu();
        cin >> item;
        switch (item) {
            case 1:
                addFlight();
                break;
            case 2:
                addTicket();
                break;
            case 3:
                removeFlight();
                break;
            case 4:
                removeTicket();
                break;
            case 5:
                editFlight();
                break;
            case 6:
                editPassenger();
                break;
            case 7:
                flightReport();
                break;
            case 8:
                passengerList();
                break;
            case 9:
                break;
            default:
                cout << "not an item! try again";
                continue;
        }
        if (item == 9) {
            break;
        }

    }

}

void passengerList() {

}

void flightReport() {

}

void editPassenger() {

}

void editFlight() {

}

void removeTicket() {

}

void removeFlight() {

}

void addTicket() {

}

void addFlight() {

}

void show_menu() {
    cout << "select one item" << endl;
    cout << "1. add flight" << endl;
    cout << "2. add ticket" << endl;
    cout << "3. remove flight" << endl;
    cout << "4. remove ticket" << endl;
    cout << "5. edit flight" << endl;
    cout << "6. edit passenger" << endl;
    cout << "7. specific day flights report" << endl;
    cout << "8. specific flight passengers list" << endl;
    cout << "9. exit" << endl;
}