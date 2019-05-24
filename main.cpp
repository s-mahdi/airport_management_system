#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

class Ticket {
public:

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
};

class Passenger {
private:
    string name;
    string lastName;
    string parentName;
    long long ID;
    string birthday;
};

class Flight;

class Plane {
public:
    Plane(int planeSerial, int numberOfSeats) : planeSerial(planeSerial), numberOfSeats(numberOfSeats) {}

public:
    int getPlaneSerial() const {
        return planeSerial;
    }

    void setOnFlight(bool onFlight) {
        Plane::onFlight = onFlight;
    }


private:
    int planeSerial;
    int numberOfSeats;
    bool onFlight;

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

public:
    Flight() {}

    Flight(int flightNumber, int planeSerial, const string &origin, const string &destination, const string &date,
           const string &time, int numberOfPassengers) : flightNumber(flightNumber), planeSerial(planeSerial),
                                                         origin(origin), destination(destination), date(date),
                                                         time(time), numberOfPassengers(numberOfPassengers) {}

    void setFlight(Plane &plane) {
        planeSerial = plane.planeSerial;

        origin = "ker";
        cout << "enter origin" << endl;

        destination = "teh";
        cout << "enter destination" << endl;

        date = "2019/1/1";
        cout << "enter flight date" << endl;

        time = "13";
        cout << "enter flight time" << endl;

        numberOfPassengers = 99;
        cout << "enter number of passengers" << endl;

    };

};

void show_menu();

void addTicket();

void removeFlight();

void removeTicket();

void editFlight();

void editPassenger();

void flightReport();

void passengerList();


int main() {
    int item;
    vector<Flight> flightsList;
    vector<Plane> planeList;
    for (int i = 1; i < 10; ++i) { // adding test flights
        Plane p(i * 100, 100);
        planeList.push_back(p);
    }
    while (true) {
        show_menu();
        cin >> item;
        switch (item) {
            case 1: // add flight
                cout << "available plane list: ";
                for (auto &i : planeList) { // show planes serial list
                    cout << " " << i.getPlaneSerial();
                }

                cout << "enter plane number" << endl;
                int inputPlaneSerial;
                cin >> inputPlaneSerial;

                bool found;
                for (auto &plane : planeList) { // check if such plane is available
                    if (plane.getPlaneSerial() == inputPlaneSerial) {
                        Flight flight;
                        flight.setFlight(plane); // create flight
                        flightsList.push_back(flight); // add to flights list
                        cout << "flight added\n";
                        found = true;
                        break;
                    }

                }
                if (!found) {
                    cout << "flight not found\n";
                }
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