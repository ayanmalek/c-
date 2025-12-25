#include <iostream>
#include <string>
using namespace std;

// ==================== Safe Integer Input Function ====================
void safeIntInput(int &x) {
    while (!(cin >> x)) {
        cout << "please input number only: ";
        cin.clear();              // error flag clear
        cin.ignore(1000, '\n');   // wrong input discard
    }
}

// ==================== Base Class ====================
class Vehicle {
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    Vehicle() : vehicleID(0), manufacturer(""), model(""), year(0) { totalVehicles++; }
    Vehicle(int id, string manu, string mod, int yr)
        : vehicleID(id), manufacturer(manu), model(mod), year(yr) { totalVehicles++; }

    virtual ~Vehicle() { totalVehicles--; }

    int getVehicleID() { return vehicleID; }
    static int getTotalVehicles() { return totalVehicles; }

    virtual void display() {
        cout << "ID: " << vehicleID
             << ", Manufacturer: " << manufacturer
             << ", Model: " << model
             << ", Year: " << year;
    }
};

int Vehicle::totalVehicles = 0;

// ==================== Single Inheritance ====================
class Car : public Vehicle {
protected:
    string fuelType;
public:
    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void display() {
        Vehicle::display();
        cout << ", Fuel Type: " << fuelType;
    }
};

// ==================== Multilevel Inheritance ====================
class ElectricCar : public Car {
private:
    int batteryCapacity;
public:
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void display() {
        Car::display();
        cout << ", Battery: " << batteryCapacity << " kWh";
    }
};

// ==================== SportsCar ====================
class SportsCar : public ElectricCar {
private:
    int topSpeed;
public:
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void display() {
        ElectricCar::display();
        cout << ", Top Speed: " << topSpeed << " km/h";
    }
};

// ==================== Vehicle Registry ====================
class VehicleRegistry {
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() : count(0) {}

    void addVehicle(Vehicle* v) {
        vehicles[count++] = v;
        cout << "Vehicle added successfully!\n";
    }

    void viewAllVehicles() {
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
            cout << endl;
        }
        cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;
    }

    void searchByID(int id) {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                vehicles[i]->display();
                cout << endl;
                return;
            }
        }
        cout << "Vehicle not found!\n";
    }
};

// ==================== Main Function ====================
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n--- Vehicle Registry Menu ---\n";
        cout << "1. Add Car\n2. Add Electric Car\n3. Add Sports Car\n";
        cout << "4. View All\n5. Search by ID\n6. Exit\n";
        cout << "Enter choice: ";
        safeIntInput(choice);

        if (choice == 1 || choice == 2 || choice == 3) {
            int id, year, battery, speed;
            string manu, model, fuel;

            cout << "Enter Vehicle ID: ";
            safeIntInput(id);

            cin.ignore();
            cout << "Enter Manufacturer: ";
            getline(cin, manu);

            cout << "Enter Model: ";
            getline(cin, model);

            cout << "Enter Year: ";
            safeIntInput(year);

            cout << "Enter Fuel Type: ";
            cin.ignore();
            getline(cin, fuel);

            if (choice == 1) {
                registry.addVehicle(new Car(id, manu, model, year, fuel));
            }
            else if (choice == 2) {
                cout << "Enter Battery Capacity: ";
                safeIntInput(battery);
                registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
            }
            else if (choice == 3) {
                cout << "Enter Battery Capacity: ";
                safeIntInput(battery);
                cout << "Enter Top Speed: ";
                safeIntInput(speed);
                registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
            }
        }
        else if (choice == 4) {
            registry.viewAllVehicles();
        }
        else if (choice == 5) {
            int id;
            cout << "Enter ID to search: ";
            safeIntInput(id);
            registry.searchByID(id);
        }

    } while (choice != 6);

    cout << "Program exited safely.\n";
    return 0;
}

