/*
    2) INHERITANCE
    
    Explanation:
    - Inheritance: Allows class to inherit members and functions from parent class
    - Derived Class: Child class that inherits (e.g., Car)
    - Base Class: Parent class being inherited from (e.g., Vehicle)
    - Access Control: public (inherit as-is), protected (private in parent becomes protected), private (all become private)
*/

#include <iostream>
#include <string>
using namespace std;

// Base Class (Parent Class)
class Vehicle {
private:
    // Private: Not accessible in derived class
    string vin;

protected:
    // Protected: Accessible in derived class but not outside
    string brand;
    int yearManufactured;

public:
    // Constructor of base class
    // Initializes base class members
    Vehicle(string b, int year, string v) 
        : brand(b), yearManufactured(year), vin(v) {
        cout << "Vehicle Constructor called: " << brand << endl;
    }

    // Destructor of base class
    virtual ~Vehicle() {
        cout << "Vehicle Destructor called" << endl;
    }

    // Public getter: Accessible everywhere
    string getBrand() const {
        return brand;
    }

    // Public getter: Returns year
    int getYear() const {
        return yearManufactured;
    }

    // Public getter: Returns VIN (private variable)
    string getVIN() const {
        return vin;
    }

    // Member function: Available to derived class and outside
    void displayVehicleInfo() {
        cout << "Brand: " << brand << ", Year: " << yearManufactured << endl;
    }
};

// Derived Class (Child Class) - public inheritance
// Car inherits all public and protected members from Vehicle
class Car : public Vehicle {
private:
    // Car-specific private member
    int numberOfDoors;

public:
    // Constructor of derived class
    // : Vehicle(b, y, v) calls base class constructor first
    Car(string b, int year, string vin, int doors) 
        : Vehicle(b, year, vin), numberOfDoors(doors) {
        cout << "Car Constructor called" << endl;
    }

    // Destructor: ~Vehicle() called automatically after this
    ~Car() {
        cout << "Car Destructor called" << endl;
    }

    // Getter: Car-specific property
    int getNumberOfDoors() const {
        return numberOfDoors;
    }

    // Setter: Modifies car-specific property
    void setNumberOfDoors(int doors) {
        if (doors >= 2 && doors <= 8) {
            numberOfDoors = doors;
        }
    }

    // Function overriding: Same name, redefined behavior
    // Hides parent's displayVehicleInfo()
    void displayVehicleInfo() {
        cout << "Car - Brand: " << brand           // Can access protected member
             << ", Year: " << yearManufactured     // Can access protected member
             << ", Doors: " << numberOfDoors 
             << ", VIN: " << getVIN() << endl;     // Must use getter for private member
    }

    // Car-specific function: Not in base class
    void honk() {
        cout << "Car honks: Beep beep!" << endl;
    }
};

// Another Derived Class: Truck
class Truck : public Vehicle {
private:
    double loadCapacity;  // In tons

public:
    Truck(string b, int year, string vin, double capacity) 
        : Vehicle(b, year, vin), loadCapacity(capacity) {
        cout << "Truck Constructor called" << endl;
    }

    ~Truck() {
        cout << "Truck Destructor called" << endl;
    }

    double getLoadCapacity() const {
        return loadCapacity;
    }

    void displayVehicleInfo() {
        cout << "Truck - Brand: " << brand 
             << ", Year: " << yearManufactured 
             << ", Load Capacity: " << loadCapacity << " tons" << endl;
    }
};

int main() {
    cout << "===== Creating Objects (Constructor Chain) =====" << endl;
    Car car("Honda", 2023, "ABC123XYZ", 4);
    Truck truck("Volvo", 2022, "XYZ987DEF", 15.5);

    cout << "\n===== Accessing Inherited Members =====" << endl;
    cout << "Car Brand (from Vehicle): " << car.getBrand() << endl;
    cout << "Car Year (from Vehicle): " << car.getYear() << endl;

    cout << "\n===== Accessing Derived Class Members =====" << endl;
    cout << "Car Doors: " << car.getNumberOfDoors() << endl;

    cout << "\n===== Function Overriding =====" << endl;
    car.displayVehicleInfo();     // Calls Car's version
    truck.displayVehicleInfo();   // Calls Truck's version

    cout << "\n===== Car-Specific Methods =====" << endl;
    car.honk();

    cout << "\n===== Object Destruction (Destructor Chain) =====" << endl;
    return 0;
    // ~Car() -> ~Vehicle() called automatically
    // ~Truck() -> ~Vehicle() called automatically
}

/*
    Key Concepts Explained:
    
    1. public inheritance
       - Child can access parent's public members directly
       - Child can access parent's protected members
       - Child inherits parent's private members (can't access directly)
    
    2. Constructor initialization list with parent constructor
       - Vehicle(b, y, v) must come first
       - Initializes base class before derived class members
    
    3. Function Overriding
       - Derived class defines function with same name as parent
       - Original parent function is hidden (not virtual yet)
       - Good for adding derived-class-specific behavior
    
    4. Destructor Chain
       - Derived destructor runs first
       - Then base class destructor
       - Important for proper resource cleanup
    
    5. Reusability
       - Avoid repeating code (brand, year) in each vehicle type
       - Common interface through base class
*/
