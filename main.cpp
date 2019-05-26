#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Passenger {
public:
    Passenger(const string &name, const string &lastName, const string &parentName, long long int &ID,
              const string &birthday) : name(name), lastName(lastName), parentName(parentName), ID(ID),
                                        birthday(birthday) {}

    ~Passenger() {
    }

    const string &getName() const {
        return name;
    }

    const string &getLastName() const {
        return lastName;
    }

    const string &getParentName() const {
        return parentName;
    }

    long long int getID() const {
        return ID;
    }

    const string &getBirthday() const {
        return birthday;
    }

private:
    string name;
    string lastName;
    string parentName;
    long long ID;
    string birthday;

    friend class Ticket;
};

class Ticket {
public:

    Ticket(int &flightNumber, const string &flightDate, const string &flightTime, const string &origin,
           const string &destination, const string &passengerName, const string &passengerLastName,
           long long int &passengerID, int &planeSerial, int &ticketPrice) : flightNumber(flightNumber),
                                                                             flightDate(flightDate),
                                                                             flightTime(flightTime), origin(origin),
                                                                             destination(destination),
                                                                             passengerName(passengerName),
                                                                             passengerLastName(passengerLastName),
                                                                             passengerID(passengerID),
                                                                             planeSerial(planeSerial),
                                                                             ticketPrice(ticketPrice),
                                                                             passenger(passengerName, passengerLastName,
                                                                                       "Unknown", passengerID,
                                                                                       "Unknown") {}

    ~Ticket() {
    }

    void setPassenger() {
        cout << "enter passenger birthday:\n";
        cin >> passenger.birthday;

        cout << "enter passenger parent name:\n";
        cin >> passenger.parentName;
    }

    long long int getPassengerID() const {
        return passenger.getID();
    }

    const Passenger &getPassenger() const {
        return passenger;
    }

    void editPassenger() {
        cout << "enter Passenger name\n";
        cin >> passenger.name;

        cout << "enter Passenger last name\n";
        cin >> passenger.lastName;

        cout << "enter passenger parent name\n";
        cin >> passenger.parentName;

        cout << "enter passenger ID\n";
        cin >> passenger.ID;

        cout << "enter passenger birthday\n";
        cin >> passenger.birthday;
    };


private:
    int flightNumber;
    string flightDate;
    string flightTime;
    string origin;
    string destination;
    string passengerName;
    string passengerLastName;
    long long int passengerID;
    int planeSerial;
    int ticketPrice;
    Passenger passenger;

    friend class Flight;
};

class Plane {
public:

    Plane(int planeSerial, int numberOfSeats) : planeSerial(planeSerial), numberOfSeats(numberOfSeats) {}

    ~Plane() {
    }

    int getPlaneSerial() const {
        return planeSerial;
    }

    void setOnFlight(bool onFlight) {
        Plane::onFlight = onFlight;
    }

    bool isOnFlight() const {
        return onFlight;
    }


private:
    int planeSerial;
    int numberOfSeats;
    bool onFlight = false;

    friend class Flight;
};

class Flight {
private:
    int flightNumber;
    int planeSerial;
    string origin;
    string destination;
    string date;
    string time;
    int numberOfPassengers;
    vector<Ticket> ticketList;
    Plane *plane;
    bool full;

public:
    Flight(Plane *plane) : plane(plane), origin("Unknown"), destination("NY"),
                           date("2001/11/9"), time("13"), numberOfPassengers(0),
                           planeSerial(plane->planeSerial), flightNumber(0), full(false) {}

    ~Flight() {
    }

    void setFlight() {

        cout << "enter flight number" << endl;
        cin >> flightNumber;

        cout << "enter origin" << endl;
        cin >> origin;

        cout << "enter destination" << endl;
        cin >> destination;

        cout << "enter flight date" << endl;
        cin >> date;

        cout << "enter flight time" << endl;
        cin >> time;

        plane->onFlight = true;

    };


    int getFlightNumber() const {
        return flightNumber;
    }

    bool isFull() const {
        return full;
    }

    Plane *getPlane() const {
        return plane;
    }

    void setFlightNumber(int flightNumber) {
        Flight::flightNumber = flightNumber;
    }

    void setFlightPlane(Plane *plane) {
        Flight::plane->setOnFlight(false); // free previous plane
        Flight::plane = plane; // set new flight plane
        plane->setOnFlight(true);// set new plane busy
    }

    void setOrigin(const string &origin) {
        Flight::origin = origin;
    }

    void setDestination(const string &destination) {
        Flight::destination = destination;
    }

    void setDate(const string &date) {
        Flight::date = date;
    }

    void setTime(const string &time) {
        Flight::time = time;
    }

    void setNumberOfPassengers(int &numberOfPassengers) {
        Flight::numberOfPassengers = numberOfPassengers;
    }

    const string &getDate() const {
        return date;
    }


    const string &getOrigin() const {
        return origin;
    }

    const string &getDestination() const {
        return destination;
    }

    const string &getTime() const {
        return time;
    }

    int getNumberOfPassengers() const {
        return numberOfPassengers;
    }

    const vector<Ticket> &getTicketList() const {
        return ticketList;
    }

    void addTicket() {
        if (plane->numberOfSeats > ticketList.size()) { // if plane is not full

            cout << "enter passenger name\n";
            string passengerName;
            cin >> passengerName;

            cout << "enter passenger last name\n";
            string passengerLastName;
            cin >> passengerLastName;

            cout << "enter passenger id\n";
            long long passengerID;
            cin >> passengerID;

            cout << "enter ticket price\n";
            int ticketPrice;
            cin >> ticketPrice;

            Ticket ticket(flightNumber, date, time,
                          origin, destination, passengerName,
                          passengerLastName, passengerID, planeSerial,
                          ticketPrice);
            ticket.setPassenger();
            ticketList.push_back(ticket);

            ++numberOfPassengers;

            cout << "ticket added.\n";

        }
        if (plane->numberOfSeats == ticketList.size()) {
            cout << "ticket was not added: plane is full\n";
            full = true;
        }

    };

    void removeTicketFromFlight() {
        cout << "enter passenger ID:\n";
        int inputPassengerID;
        cin >> inputPassengerID;
        bool isFound = false;
        for (int i = 0; i < ticketList.size(); ++i) {
            if (ticketList[i].getPassengerID() == inputPassengerID) {
                ticketList.erase(ticketList.begin() + i);
                isFound = true;
                cout << "ticket removed\n";
            }
        }

        if (!isFound) {
            cout << "invalid passenger id\n";
        }

    };

    void editPassenger(long long &passengerID) {
        bool isPassengerFound = false;
        for (auto &ticket: ticketList) {
            if (ticket.getPassengerID() == passengerID) {
                isPassengerFound = true;
                ticket.editPassenger();
            }
        }

        if (!isPassengerFound) {
            cout << "passenger not found!\n";
        }
    };


};

void show_menu();

void printAvailablePlanes(vector<Plane> &);

void printFightList(vector<Flight> &);

void addTicket(vector<Flight> &);

void removeFlight(vector<Flight> &);

void removeTicket(vector<Flight> &);

void editFlight(vector<Flight> &, vector<Plane> &planeList);

void editPassenger(vector<Flight> &);

void flightReport(vector<Flight> &);

void passengerList(vector<Flight> &);

void addFlight(vector<Plane> &planeList, vector<Flight> &flightsList);

void showEditFlightMenu();

void editFlightMenu(Flight &flight, vector<Plane> &planeList);

int main() {
    int item;
    vector<Flight> flightsList;
    vector<Plane> planeList;
    for (int i = 1; i < 10; ++i) { // adding test planes
        Plane p(i * 100, 5); //plane serial is 100, 200, ... and number of seats of all planes is 5
        planeList.push_back(p); // add to airport planes
    }

    while (true) {
        show_menu();
        cin >> item;
        switch (item) {
            case 1: //
                addFlight(planeList, flightsList);// add flight
                break;

            case 2:
                addTicket(flightsList);// add ticket to a flight
                break;

            case 3:
                removeFlight(flightsList);// remove flight
                break;

            case 4:
                removeTicket(flightsList);// remove ticket
                break;
            case 5:
                editFlight(flightsList, planeList);
                break;
            case 6:
                editPassenger(flightsList);
                break;
            case 7:
                flightReport(flightsList);
                break;
            case 8:
                passengerList(flightsList);
                break;
            case 9:
                break;
            default:
                cout << "not an item! try again\n";
                continue;
        }
        if (item == 9) {
            break;
        }

    }

}

void addFlight(vector<Plane> &planeList, vector<Flight> &flightsList) {

    printAvailablePlanes(planeList);

    cout << "enter plane number: " << endl;
    int inputPlaneSerial;
    cin >> inputPlaneSerial;

    bool isPlaneFound = false;
    for (auto &plane : planeList) { // check plane serial and availability
        if (plane.getPlaneSerial() == inputPlaneSerial && !plane.isOnFlight()) {
            Flight flight(&plane);
            flight.setFlight(); // create flight
            flightsList.push_back(flight); // add to flights list
            cout << "flight added\n";
            isPlaneFound = true;
            break;
        }

    }
    if (!isPlaneFound) {
        cout << "plane not found or plane is on flight\n";
    }

}

void passengerList(vector<Flight> &flightList) {
    cout << "enter flight number:\n";
    int inputFlightNumber;
    cin >> inputFlightNumber;
    cout << "+++++++++++++++\n" << "passengers of flight " << inputFlightNumber << ":\n";
    bool isFlightFound = false;
    for (auto &flight : flightList) {
        if (flight.getFlightNumber() == inputFlightNumber) {
            isFlightFound = true;
            for (auto &ticket: flight.getTicketList()) {
                cout << "passenger name: " << ticket.getPassenger().getName();
                cout << "\npassenger last name: " << ticket.getPassenger().getLastName();
                cout << "\npassenger parent name: " << ticket.getPassenger().getParentName();
                cout << "\npassenger ID: " << ticket.getPassenger().getID();
                cout << "\npassenger birthday: " << ticket.getPassenger().getBirthday();
                cout << "\n+++++++++++++++\n";
            }
        }
    }

    if (!isFlightFound) {
        cout << "there is no such flight!\n";
    }

}

void flightReport(vector<Flight> &flightList) {
    cout << "enter date:\n";
    string inputDate;
    cin >> inputDate;
    cout << "+++++++++++++++\n" << "flights serial on " << inputDate << ":\n";
    bool isDateFound = false;
    for (auto &flight : flightList) {
        if (flight.getDate() == inputDate) {
            isDateFound = true;
            cout << "flight serial: " << flight.getFlightNumber();
            cout << "\nflight origin: " << flight.getOrigin();
            cout << "\nflight destination: " << flight.getDestination();
            cout << "\nflight time: " << flight.getTime();
            cout << "\nflight number of passengers: " << flight.getNumberOfPassengers();
            cout << "\n+++++++++++++++\n";
        }
    }

    if (!isDateFound) {
        cout << "there is no flight on this date!\n";
    }

}

void editPassenger(vector<Flight> &flightList) {
    cout << "enter flight number from flight list:\n";
    printFightList(flightList);
    if (!flightList.empty()) { // check if there is flights on air port
        int inputFlightNumber;
        cin >> inputFlightNumber;
        bool isFlightFound = false;
        for (auto &flight : flightList) {
            if (flight.getFlightNumber() == inputFlightNumber) {
                isFlightFound = true;
                cout << "enter passengerID\n";
                long long inputPassengerID;
                cin >> inputPassengerID;
                flight.editPassenger(inputPassengerID);
            }
        }

        if (!isFlightFound) {
            cout << "flight not found\n";
        }
    }

}

void editFlight(vector<Flight> &flightList, vector<Plane> &planeList) {
    cout << "enter flight number from flight list:\n";
    printFightList(flightList);
    if (!flightList.empty()) {
        int inputFlightNumber;
        cin >> inputFlightNumber;
        bool isFlightFound = false;
        for (auto &flight : flightList) {
            if (flight.getFlightNumber() == inputFlightNumber) {
                isFlightFound = true;
                showEditFlightMenu();
                editFlightMenu(flight, planeList);
                break;
            }
        }
        if (!isFlightFound) {
            cout << "invalid flight number\n";
        }
    }

}

void editFlightMenu(Flight &flight, vector<Plane> &planeList) {

    int inputMenuItem = 0;
    cin >> inputMenuItem;
    switch (inputMenuItem) {
        case 1: {
            cout << "enter new flight number:\n";
            int newFlightNumber;
            cin >> newFlightNumber;
            flight.setFlightNumber(newFlightNumber);
        }
            break;

        case 2: {
            printAvailablePlanes(planeList);
            cout << "enter new plane serial:\n";
            int inputNewPlaneSerial;
            cin >> inputNewPlaneSerial;
            bool isPlaneFound = false;
            for (auto &plane : planeList) {
                if (plane.getPlaneSerial() == inputNewPlaneSerial) {
                    isPlaneFound = true;
                    flight.setFlightPlane(&plane);
                    cout << "Flight plane changed\n";
                    break;
                }
            }
            if (!isPlaneFound)
                cout << "there was not such plane!\n";
        }
            break;

        case 3: {
            cout << "enter new origin\n";
            string inputNewOrigin;
            cin >> inputNewOrigin;
            flight.setOrigin(inputNewOrigin);
        }

            break;

        case 4: {
            cout << "enter new destination\n";
            string inputNewDestination;
            cin >> inputNewDestination;
            flight.setDestination(inputNewDestination);
        }
            break;

        case 5: {
            cout << "enter new date\n";
            string inputNewDate;
            cin >> inputNewDate;
            flight.setDate(inputNewDate);
        }
            break;

        case 6: {
            cout << "enter new time\n";
            string inputNewTime;
            cin >> inputNewTime;
            flight.setTime(inputNewTime);
        }
            break;

        case 7: {
            cout << "enter new number of passenger\n";
            int newNumberOfPassengers;
            cin >> newNumberOfPassengers;
            flight.setNumberOfPassengers(newNumberOfPassengers);
        }

            break;

        default:
            cout << "there is no such item \n";
    }

}

void showEditFlightMenu() {
    cout << "witch one you want to edit?\n";
    cout << "1. flight number\n";
    cout << "2. plane\n";
    cout << "3. origin\n";
    cout << "4. destination\n";
    cout << "5. date\n";
    cout << "6. time\n";
    cout << "7. number of passengers\n";

}

void removeFlight(vector<Flight> &flightList) {
    cout << "enter flight number:\n";
    for (auto &flight : flightList) { // show flights list
        cout << " " << flight.getFlightNumber();
    }
    cout << endl;
    int inputFlightNumber;
    cin >> inputFlightNumber;
    bool isFlightFound = false;
    for (int i = 0; i < flightList.size(); ++i) {
        if (flightList[i].getFlightNumber() == inputFlightNumber) {
            isFlightFound = true;
            flightList[i].getPlane()->setOnFlight(false);
            flightList.erase(flightList.begin() + i);
            cout << "flight removed\n";
        }
    }

    if (!isFlightFound) {
        cout << "there is no such flight\n";
    }

}

void printFightList(vector<Flight> &flightList) {
    if (flightList.empty()) {
        cout << "there is no flight!\n";
    } else {
        for (auto &flight : flightList) { // show flights list
            cout << " " << flight.getFlightNumber();
        }
        cout << endl;
    }

};

void printAvailablePlanes(vector<Plane> &planeList) {
    cout << "available plane list: ";
    for (auto &i : planeList) { // show planes serial list
        if (!i.isOnFlight())
            cout << " " << i.getPlaneSerial();
    }
    cout << endl;
}

void removeTicket(vector<Flight> &flightList) {
    cout << "enter flight number to remove:\n";
    for (auto &flight : flightList) { // show flights list
        cout << " " << flight.getFlightNumber();
    }
    cout << endl;
    int inputFlightNumber;
    cin >> inputFlightNumber;
    bool isFound = false;
    for (auto &i : flightList) {
        if (i.getFlightNumber() == inputFlightNumber) {
            i.removeTicketFromFlight();
            isFound = true;
            break;
        }
    }
    if (!isFound) {
        cout << "invalid flight number\n";
    }
}

void addTicket(vector<Flight> &flightsList) {

    if (flightsList.empty()) { // if there is no flight in airport
        cout << "sorry... there is no flight!\n";
    } else {
        cout << "select one from flights list\n";
        for (auto &flight : flightsList) { // print flights list
            if (!flight.isFull())
                cout << " " << flight.getFlightNumber();
        }
        cout << endl;
        int inputFlightNumber;
        cin >> inputFlightNumber;
        bool isFound = false;
        for (auto &i : flightsList) {
            if (i.getFlightNumber() == inputFlightNumber) {
                i.addTicket();
                isFound = true;
                break;
            }
        }
        if (!isFound)
            cout << "flight not found\n";
    }

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