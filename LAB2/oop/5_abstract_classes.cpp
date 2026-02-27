/*
    6) ABSTRACT CLASSES & PURE VIRTUAL FUNCTIONS
    
    Explanation:
    - Abstract Class: Cannot be instantiated, only used as base class
    - Pure Virtual Function: = 0, no implementation in base class
    - Interface: Contract that derived classes MUST implement
    - Use Case: Define family of related classes with common interface
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===== ABSTRACT BASE CLASS =====
class Employee {
protected:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id, double s) 
        : name(n), employeeID(id), salary(s) {}

    // Virtual destructor: ESSENTIAL for polymorphism
    virtual ~Employee() {}

    // Pure virtual function: = 0
    // No implementation provided by base class
    // MUST be overridden by all derived classes
    virtual void calculateSalary() = 0;

    // Another pure virtual function
    virtual void displayRole() = 0;

    // Virtual function with default implementation
    // Derived classes can override but don't have to
    virtual void giveBonus(double amount) {
        salary += amount;
        cout << name << " received bonus: $" << amount << endl;
    }

    // Non-virtual function: Same for all derived classes
    void displayBasicInfo() {
        cout << "ID: " << employeeID << ", Name: " << name 
             << ", Salary: $" << salary << endl;
    }

    // Getter
    double getSalary() const {
        return salary;
    }

    string getName() const {
        return name;
    }
};

// ===== CONCRETE CLASS 1: Manager =====
class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(string n, int id, double s, int team) 
        : Employee(n, id, s), teamSize(team) {}

    // MUST override pure virtual functions
    // Override 1: calculateSalary
    // Implementation: Base salary + team bonus
    void calculateSalary() override {
        cout << "Manager " << name << " salary calculation:" << endl;
        double bonus = 5000 + (teamSize * 500);  // $500 per team member
        salary += bonus;
        cout << "  Base + Team Bonus: " << bonus << endl;
        cout << "  Total Salary: $" << salary << endl;
    }

    // Override 2: displayRole
    void displayRole() override {
        cout << "Role: Manager (supervising " << teamSize << " team members)" << endl;
    }

    // Manager-specific method
    void conductReview() {
        cout << name << " is conducting performance reviews..." << endl;
    }
};

// ===== CONCRETE CLASS 2: Developer =====
class Developer : public Employee {
private:
    string programmingLanguage;
    int projectsCompleted;

public:
    Developer(string n, int id, double s, string lang, int projects)
        : Employee(n, id, s), programmingLanguage(lang), projectsCompleted(projects) {}

    // Override pure virtual functions

    // Override 1: calculateSalary
    // Implementation: Base salary + project bonus + language bonus
    void calculateSalary() override {
        cout << "Developer " << name << " salary calculation:" << endl;
        double projectBonus = projectsCompleted * 1000;  // $1000 per project
        double languageBonus = 0;
        
        if (programmingLanguage == "C++") languageBonus = 3000;
        else if (programmingLanguage == "Python") languageBonus = 2500;
        else if (programmingLanguage == "Java") languageBonus = 2000;
        
        salary += projectBonus + languageBonus;
        cout << "  Project Bonus: $" << projectBonus << endl;
        cout << "  Language Bonus: $" << languageBonus << endl;
        cout << "  Total Salary: $" << salary << endl;
    }

    // Override 2: displayRole
    void displayRole() override {
        cout << "Role: Developer (specializes in " << programmingLanguage << ")" << endl;
    }

    // Developer-specific method
    void writeCode() {
        cout << name << " is writing " << programmingLanguage << " code..." << endl;
    }
};

// ===== CONCRETE CLASS 3: Designer =====
class Designer : public Employee {
private:
    string designTools;

public:
    Designer(string n, int id, double s, string tools)
        : Employee(n, id, s), designTools(tools) {}

    // Override pure virtual functions

    // Override 1: calculateSalary
    void calculateSalary() override {
        cout << "Designer " << name << " salary calculation:" << endl;
        double creativeBonus = 3500;  // Fixed creative bonus
        salary += creativeBonus;
        cout << "  Creative Bonus: $" << creativeBonus << endl;
        cout << "  Total Salary: $" << salary << endl;
    }

    // Override 2: displayRole
    void displayRole() override {
        cout << "Role: Designer (using " << designTools << ")" << endl;
    }

    // Designer-specific method
    void createDesign() {
        cout << name << " is creating UI/UX design using " << designTools << "..." << endl;
    }

    // Override optional virtual function
    void giveBonus(double amount) override {
        cout << "DESIGN BONUS: Giving " << amount * 1.2 << " (20% extra for designers)" << endl;
        salary += (amount * 1.2);
    }
};

int main() {
    cout << "===== DEMONSTRATING ABSTRACT CLASSES =====" << endl;
    cout << "Note: Cannot create Employee object directly (abstract)" << endl;
    // Employee emp("Test", 0, 0); // COMPILER ERROR - cannot instantiate abstract class

    cout << "\n===== Creating Concrete Employee Objects =====" << endl;
    Manager manager("Alice Johnson", 101, 50000, 5);
    Developer developer("Bob Smith", 102, 45000, "C++", 8);
    Designer designer("Carol White", 103, 40000, "Adobe XD");

    cout << "\n===== Polymorphic Array of Employees =====" << endl;
    // All derived objects stored as base class pointers
    // This demonstrates polymorphism and power of abstract classes
    Employee* employees[3] = {&manager, &developer, &designer};

    cout << "\n===== PROCESSING ALL EMPLOYEES =====" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\n--- Employee " << (i + 1) << " ---" << endl;
        employees[i]->displayBasicInfo();
        employees[i]->displayRole();      // Calls correct override
        employees[i]->calculateSalary();  // Calls correct override (pure virtual)
    }

    cout << "\n===== GIVING BONUSES (Some overridden) =====" << endl;
    manager.giveBonus(1000);      // Uses base class version
    developer.giveBonus(1000);    // Uses base class version
    designer.giveBonus(1000);     // Uses Designer's override (20% extra)

    cout << "\n===== TYPE-SPECIFIC METHODS =====" << endl;
    manager.conductReview();
    developer.writeCode();
    designer.createDesign();

    cout << "\n===== SALARIES AFTER BONUSES =====" << endl;
    for (int i = 0; i < 3; i++) {
        cout << employees[i]->getName() << ": $" 
             << employees[i]->getSalary() << endl;
    }

    return 0;
}

/*
    Key Concepts Explained:
    
    1. Abstract Class
       - Contains at least one pure virtual function (= 0)
       - Cannot be instantiated directly
       - Must be inherited
       - Only purpose is to be base class
    
    2. Pure Virtual Function (= 0)
       - No implementation in abstract class
       - Derived class MUST provide implementation
       - Enforces contract/interface
       - Similar to Java/C# interfaces
    
    3. Concrete Class
       - Implements ALL pure virtual functions
       - Can be instantiated
       - CAN have its own virtual functions
    
    4. Benefits of Abstract Classes
       - Define common interface for family of classes
       - Polymorphic behavior with base class pointers
       - Force consistent implementation across derived classes
       - Prevent instantiation of incomplete classes
    
    5. Polymorphism with Abstract Base
       - Employee* ptr = &manager; works
       - Dynamic dispatch for virtual functions
       - Same pointer works with all derived types
    
    6. Optional Overrides
       - Virtual function with implementation: derived SHOULD override
       - Pure virtual (= 0): derived MUST override
    
    7. Real-World Example
       - Employee is abstract (no actual 'Employee' object exists)
       - Manager, Developer, Designer are concrete
       - Each implements calculateSalary() differently
       - Main program works with Employee pointers
*/
