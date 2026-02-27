/*
    1) CLASSES, CONSTRUCTORS & DESTRUCTORS
    
    Explanation:
    - Class: Blueprint for creating objects (data + methods)
    - Constructor: Special function called when object is created
    - Destructor: Special function called when object is destroyed
    - Access Modifiers: private (only class), public (everyone), protected (class + derived)
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    // Private member variables - hidden from outside
    string name;
    int rollNumber;
    double gpa;

public:
    // Constructor: Initializes object when created
    // Uses initialization list (name:value) for efficiency
    Student(string n, int roll, double g) 
        : name(n), rollNumber(roll), gpa(g) {
        cout << "Constructor called for: " << name << endl;
    }

    // Destructor: Cleanup when object is destroyed
    // Automatically called when object goes out of scope or is deleted
    ~Student() {
        cout << "Destructor called for: " << name << endl;
    }

    // Getter: Returns private member variable
    // const means this function doesn't modify object state
    string getName() const {
        return name;
    }

    // Getter: Returns roll number
    int getRollNumber() const {
        return rollNumber;
    }

    // Getter: Returns GPA
    double getGPA() const {
        return gpa;
    }

    // Setter: Modifies private member variable
    // Includes validation before setting value
    void setGPA(double g) {
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
            cout << "GPA updated to: " << gpa << endl;
        } else {
            cout << "Invalid GPA! Must be between 0.0 and 4.0" << endl;
        }
    }

    // Member function: Displays student information
    void display() {
        cout << "Name: " << name 
             << ", Roll: " << rollNumber 
             << ", GPA: " << gpa << endl;
    }
};


int main() {
    cout << "===== Creating Student Objects =====" << endl;
    
    // Constructor is called here
    Student s1("Alice", 101, 3.8);
    Student s2("Bob", 102, 3.5);

    cout << "\n===== Accessing Student Info =====" << endl;
    s1.display();
    s2.display();

    cout << "\n===== Using Getter Functions =====" << endl;
    cout << "Student 1 Name: " << s1.getName() << endl;
    cout << "Student 1 GPA: " << s1.getGPA() << endl;

    cout << "\n===== Using Setter Functions =====" << endl;
    s1.setGPA(3.9);    // Valid update
    s1.setGPA(5.0);    // Invalid - shows error message

    cout << "\n===== Objects Going Out of Scope =====" << endl;
    return 0;
    // Destructors called automatically for s1 and s2
}

/*
    Key Concepts Explained:
    
    1. Initialization List (: name(n), roll(roll), gpa(g))
       - More efficient than assignment in constructor body
       - Required for const members and references
    
    2. const member functions
       - Promises not to modify object state
       - Can be called on const objects
    
    3. Encapsulation
       - Private data + public interface
       - Hide implementation, expose only necessary methods
    
    4. RAII (Resource Acquisition Is Initialization)
       - Constructor acquires resources
       - Destructor releases resources
       - Automatic cleanup when object destroyed
*/
