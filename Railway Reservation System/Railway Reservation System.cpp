#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
    static int trainCount;

public:
    Train() {
        trainNumber = 0;
        trainName = source = destination = trainTime = "";
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void inputTrainDetails() {
       
        cout << "Enter Train Number: ";
        while (!(cin >> trainNumber)) {
            cout << "Please input number only: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);

        cout << "Enter Train Time (HH:MM): ";
        getline(cin, trainTime);
       
    }

    void displayTrainDetails() const {
        cout << "Train Number   : " << trainNumber << endl;
        cout << "Train Name     : " << trainName << endl;
        cout << "Source         : " << source << endl;
        cout << "Destination    : " << destination << endl;
        cout << "Train Time     : " << trainTime << endl;
        cout << "----------------------------" << endl;
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains >= 100) {
            cout << "Train limit reached!" << endl;
            return;
        }
        trains[totalTrains].inputTrainDetails();
        totalTrains++;
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records available." << endl;
            return;
        }
        for (int i = 0; i < totalTrains; i++) {
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber() const {
        int number;
        cout << "Enter Train Number to search: ";
        while (!(cin >> number)) {
            cout << "? Please input number only: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Train not found!" << endl;
        }
    }
};

int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Add Train\n";
        cout << "2. Display All Trains\n";
        cout << "3. Search Train\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {
            cout << "? Please input number only: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3:
            system.searchTrainByNumber();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

