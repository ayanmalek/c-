
#include <iostream>
#include <string>
using namespace std;

// ==================== Ahi me base classs Vehical che  ====================
class Vehicle {
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    // Constructors vaprel che 
    Vehicle() : vehicleID(0), manufacturer(""), model(""), year(0) { totalVehicles++; }
    Vehicle(int id, string manu, string mod, int yr) : vehicleID(id), manufacturer(manu), model(mod), year(yr) { totalVehicles++; }

    // Distoptor vaprel che 
    virtual ~Vehicle() { totalVehicles--; }

    // Getters thi get karavel che 
    
    int getVehicleID() { return vehicleID; }
    string getManufacturer() { return manufacturer; }
    string getModel() { return model; }
    int getYear() { return year; }
    static int getTotalVehicles() { return totalVehicles; }

    // Setters thi value set kare li che 
    
    void setVehicleID(int id) { vehicleID = id; }
    void setManufacturer(string manu) { manufacturer = manu; }
    void setModel(string mod) { model = mod; }
    void setYear(int yr) { year = yr; }

    // Virtual method thi  info display kare che 
    
    virtual void display() {
        cout << "ID: " << vehicleID
             << ", Manufacturer: " << manufacturer
             << ", Model: " << model
             << ", Year: " << year;
    }
};

int Vehicle::totalVehicles = 0;

// ==================== Single Inheritance apel che car ne ane Vehical ne  ====================
class Car : public Vehicle {
protected:
    string fuelType;
public:
    Car() : Vehicle(), fuelType("") {}
    Car(int id, string manu, string mod, int yr, string fuel) 
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}

    void setFuelType(string fuel) { fuelType = fuel; }
    string getFuelType() { return fuelType; }

    void display() override {
        Vehicle::display();
        cout << ", Fuel Type: " << fuelType;
    }
};

// ==================== Multilevel Inheritance Aapel che ElectricCar ne ElectricCar ehican jode   ====================
class ElectricCar : public Car {
private:
    int batteryCapacity; 
public:
    ElectricCar() :
	 Car(), batteryCapacity(0) {}
	 
    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery) :
	 Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void setBatteryCapacity(int battery) { batteryCapacity = battery; }
    int getBatteryCapacity() { return batteryCapacity; }

    void display() override {
        Car::display();
        cout << ", Battery Capacity: " << batteryCapacity << " kWh";
    }
};

// ==================== Ahi Aircraft ne base class lidhel che for  Multiple Inheritance ====================
class Aircraft {
private:
    int flightRange; 
public:
    Aircraft() : flightRange(0) {}
    Aircraft(int range) : flightRange(range) {}

    void setFlightRange(int range) { flightRange = range; }
    int getFlightRange() { return flightRange; }

    virtual void displayAircraft() {
        cout << ", Flight Range: " << flightRange << " km";
    }
};

// ==================== Multiple Inheritance aapel che Flyingcar ne car ane aircraft jode ====================
class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : 
	 Car(), Aircraft() {}
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range) 
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}

    void display() {
        Car::display();
        Aircraft::displayAircraft();
    }
};

// ==================== Multilevel Inheritance che sportscar ne electrinccar jode an pachi vehical jode ====================
class SportsCar : public ElectricCar {
private:
    int topSpeed; 
public:
    SportsCar() : ElectricCar(), topSpeed(0) {}
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}

    void setTopSpeed(int speed) { topSpeed = speed; }
    int getTopSpeed() { return topSpeed; }

    void display() override {
        ElectricCar::display();
        cout << ", Top Speed: " << topSpeed << " km/h";
    }
};

// ==================== Hierarchical Inheritance  Sedancar and Vehical jode ====================
class Sedan : public Car {
public:
    Sedan() : Car() {}
    Sedan(int id, string manu, string mod, int yr, string fuel) : Car(id, manu, mod, yr, fuel) {}
    void display() override { Car::display(); }
};

class SUV : public Car {
public:
    SUV() : Car() {}
    SUV(int id, string manu, string mod, int yr, string fuel) : Car(id, manu, mod, yr, fuel) {}
    void display() override { Car::display(); }
};

// ==================== Ahi Me Vehicle Registry Bnaveli che For Registrying Vehical  ====================
class VehicleRegistry {
    Vehicle* vehicles[100]; 
    int count;

public:
    VehicleRegistry() : count(0) {}

    void addVehicle(Vehicle* v) {
        if (count < 100) {
            vehicles[count++] = v;
            cout << "Vehicle added successfully!\n";
        } else {
            cout << "Registry full!\n";
        }
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
        cout << "Vehicle with ID " << id << " not found.\n";
    }
};

// ==================== Ahi thi main fonction chalu  ====================
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n--- Vehicle Registry Menu ---\n";
        cout << "1. Add Vehicle\n2. View All Vehicles\n3. Search by ID\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int type;
            cout << "Select Vehicle Type:\n1. Car\n2. ElectricCar\n3. SportsCar\n4. Sedan\n5. SUV\n6. FlyingCar\n";
            cin >> type;

            int id, year, battery, speed, range;
            string manu, model, fuel;

            cout << "Enter Vehicle ID: "; cin >> id;
            cin.ignore(); 
            cout << "Enter Manufacturer: "; getline(cin, manu);
            cout << "Enter Model: "; getline(cin, model);
            cout << "Enter Year: "; cin >> year;

            switch (type) {
                case 1: 
                    cin.ignore();
                    cout << "Enter Fuel Type: "; getline(cin, fuel);
                    registry.addVehicle(new Car(id, manu, model, year, fuel));
                    break;
                case 2: 
                    cin.ignore();
                    cout << "Enter Fuel Type: "; getline(cin, fuel);
                    cout << "Enter Battery Capacity: "; cin >> battery;
                    registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
                    break;
                case 3: 
                    cin.ignore();
                    cout << "Enter Fuel Type: "; getline(cin, fuel);
                    cout << "Enter Battery Capacity: "; cin >> battery;
                    cout << "Enter Top Speed: "; cin >> speed;
                    registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
                    break;
                case 4: 
                    cin.ignore();
                    cout << "Enter Fuel Type: "; getline(cin, fuel);
                    registry.addVehicle(new Sedan(id, manu, model, year, fuel));
                    break;
                case 5: 
                    cin.ignore();
                    cout << "Enter Fuel Type: "; getline(cin, fuel);
                    registry.addVehicle(new SUV(id, manu, model, year, fuel));
                    break;
                case 6: 
                    cin.ignore();
                    cout << "Enter Fuel Type: "; getline(cin, fuel);
                    cout << "Enter Flight Range: "; cin >> range;
                    registry.addVehicle(new FlyingCar(id, manu, model, year, fuel, range));
                    break;
                default:
                    cout << "Invalid Type!\n";
            }
        } else if (choice == 2) {
            registry.viewAllVehicles();
        } else if (choice == 3) {
            int id;
            cout << "Enter Vehicle ID to search: ";
            cin >> id;
            registry.searchByID(id);
        } else if (choice != 4) {
            cout << "Invalid Choice!\n";
        }
    } while (choice != 4);

    cout << "Exiting Vehicle Registry System.\n";
    return 0;
}

