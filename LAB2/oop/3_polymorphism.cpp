/*
    3) POLYMORPHISM (Virtual Functions & Method Overriding)
    
    Explanation:
    - Polymorphism: "Many forms" - same interface, different behaviors
    - Virtual Function: Function that can be overridden by derived classes
    - Method Overriding: Derived class provides its own implementation
    - Dynamic Dispatch: Correct function chosen at runtime based on actual object type
*/

#include <iostream>
#include <string>
using namespace std;

// Base Class: Abstract Animal
class Animal {
protected:
    string name;

public:
    // Constructor
    Animal(string n) : name(n) {}

    // Virtual Destructor: IMPORTANT!
    // Ensures derived destructors are called
    virtual ~Animal() {
        cout << "Animal Destructor: " << name << " destroyed" << endl;
    }

    // Virtual function: Can be overridden
    // Without 'virtual', derived version is hidden (not true polymorphism)
    virtual void makeSound() {
        cout << "Animal makes a generic sound" << endl;
    }

    // Virtual function: Returns description
    virtual string getDescription() {
        return "I am an animal named " + name;
    }

    // Non-virtual function: Same in all classes
    // NOT overridden by derived classes
    void sleep() {
        cout << name << " is sleeping..." << endl;
    }

    string getName() const {
        return name;
    }
};

// Derived Class: Dog
class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, string b) : Animal(n), breed(b) {}

    ~Dog() {
        cout << "Dog Destructor: " << name << " destroyed" << endl;
    }

    // Override: Provides Dog-specific behavior
    // 'override' keyword ensures we're overriding a virtual function
    void makeSound() override {
        cout << name << " barks: WOOF WOOF!" << endl;
    }

    // Override: Dog-specific description
    string getDescription() override {
        return "I am a dog named " + name + " of breed " + breed;
    }

    // Dog-specific method: Not in base class
    void fetch() {
        cout << name << " fetches the ball!" << endl;
    }
};

// Derived Class: Cat
class Cat : public Animal {
private:
    bool isIndoor;

public:
    Cat(string n, bool indoor) : Animal(n), isIndoor(indoor) {}

    ~Cat() {
        cout << "Cat Destructor: " << name << " destroyed" << endl;
    }

    // Override: Provides Cat-specific behavior
    void makeSound() override {
        cout << name << " meows: Meow meow!" << endl;
    }

    // Override: Cat-specific description
    string getDescription() override {
        return "I am a cat named " + name + (isIndoor ? " (indoor cat)" : " (outdoor cat)");
    }

    // Cat-specific method
    void scratch() {
        cout << name << " scratches the furniture!" << endl;
    }
};

// Derived Class: Bird
class Bird : public Animal {
private:
    string color;

public:
    Bird(string n, string c) : Animal(n), color(c) {}

    ~Bird() {
        cout << "Bird Destructor: " << name << " destroyed" << endl;
    }

    // Override: Bird-specific sound
    void makeSound() override {
        cout << name << " chirps: Tweet tweet!" << endl;
    }

    // Override: Bird-specific description
    string getDescription() override {
        return "I am a " + color + " bird named " + name;
    }

    // Bird-specific method
    void fly() {
        cout << name << " flies in the sky!" << endl;
    }
};

// Function that accepts base class pointer
// Demonstrates polymorphic behavior
void animalShowcase(Animal* animal) {
    cout << "\n--- " << animal->getName() << " ---" << endl;
    animal->makeSound();          // Virtual function - calls correct version
    cout << animal->getDescription() << endl;
    animal->sleep();              // Non-virtual - same for all
}

int main() {
    cout << "===== Creating Animals (Polymorphic Objects) =====" << endl;
    
    Dog dog("Buddy", "Golden Retriever");
    Cat cat("Whiskers", true);
    Bird bird("Tweety", "yellow");

    cout << "\n===== Direct Function Calls =====" << endl;
    dog.makeSound();
    cat.makeSound();
    bird.makeSound();

    cout << "\n===== Polymorphism: Base Class Pointers to Derived Objects =====" << endl;
    // This is the power of polymorphism!
    // One function works with different types
    Animal* animals[3] = {&dog, &cat, &bird};
    
    for (int i = 0; i < 3; i++) {
        animalShowcase(animals[i]);  // Calls correct makeSound() based on actual type
    }

    cout << "\n===== Type-Specific Methods =====" << endl;
    dog.fetch();    // Only Dog has fetch()
    cat.scratch();  // Only Cat has scratch()
    bird.fly();     // Only Bird has fly()

    cout << "\n===== Virtual Destructors in Action =====" << endl;
    {
        Animal* tempAnimal = new Dog("Temporary", "Labrador");
        delete tempAnimal;  // Calls Dog destructor first, then Animal destructor
    }

    cout << "\n===== End of Main (Destructors Called) =====" << endl;
    return 0;
}

/*
    Key Concepts Explained:
    
    1. Virtual Functions
       - Base class marks function as virtual
       - Derived class overrides with 'override' keyword
       - Enables dynamic dispatch (runtime decision)
    
    2. Method Overriding
       - Same function signature in derived class
       - Provides new implementation
       - Hidden if not marked virtual
    
    3. Dynamic Dispatch (Polymorphism)
       - animals[i]->makeSound() calls different function
       - Decision made at runtime based on actual object type
       - Without virtual: compile-time binding (static dispatch)
    
    4. Virtual Destructor
       - CRITICAL in base classes with virtual functions
       - Ensures derived destructors called
       - Prevents memory leaks and incomplete cleanup
    
    5. override Keyword
       - C++11 feature for clarity
       - Compiler error if function doesn't match parent signature
       - Best practice: always use it
    
    6. Non-Virtual Functions
       - sleep() same for all animals
       - Shows difference between virtual and non-virtual
*/
