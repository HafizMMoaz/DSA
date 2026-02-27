/*
    7) MULTIPLE INHERITANCE
    
    Explanation:
    - Multiple Inheritance: Class inherits from more than one base class
    - Combines features from multiple parents
    - Can lead to "Diamond Problem" if not careful
    - Use sparingly - often better to use composition or single inheritance
*/

#include <iostream>
#include <string>
using namespace std;

// ===== BASE CLASS 1: Drawable Interface =====
class Drawable {
public:
    Drawable() {
        cout << "Drawable constructor" << endl;
    }

    virtual ~Drawable() {
        cout << "Drawable destructor" << endl;
    }

    // Pure virtual function: draw
    // All drawable objects must be able to draw
    virtual void draw() = 0;

    // Virtual function with default: can override
    virtual void setColor(const string& color) {
        cout << "Setting color to " << color << endl;
    }
};

// ===== BASE CLASS 2: Saveable Interface =====
class Saveable {
public:
    Saveable() {
        cout << "Saveable constructor" << endl;
    }

    virtual ~Saveable() {
        cout << "Saveable destructor" << endl;
    }

    // Pure virtual function: save
    // All saveable objects must be able to save
    virtual void save(const string& filename) = 0;

    // Pure virtual function: load
    virtual void load(const string& filename) = 0;

    // Virtual helper: reports if object is modified
    virtual bool isModified() const {
        return false;
    }
};

// ===== BASE CLASS 3: Named objects =====
class Named {
protected:
    string name;

public:
    Named(const string& n) : name(n) {
        cout << "Named constructor: " << name << endl;
    }

    virtual ~Named() {
        cout << "Named destructor" << endl;
    }

    // Getter
    string getName() const {
        return name;
    }

    // Setter
    void setName(const string& n) {
        name = n;
    }

    // Virtual function: display name
    virtual void displayName() {
        cout << "Object name: " << name << endl;
    }
};

// ===== DERIVED CLASS: Shape (Single Inheritance) =====
// Inherits from multiple base classes: Drawable + Saveable + Named
class Shape : public Drawable, public Saveable, public Named {
protected:
    string shapeType;
    bool modified;

public:
    // Constructor: Calls ALL base class constructors
    // Syntax: Base1(args), Base2(args), Base3(args)
    Shape(const string& type, const string& shapeName)
        : Drawable(),           // First base class
          Saveable(),            // Second base class
          Named(shapeName),      // Third base class (with parameter)
          shapeType(type),
          modified(true) {
        cout << "Shape constructor" << endl;
    }

    virtual ~Shape() {
        cout << "Shape destructor" << endl;
    }

    // Implement pure virtual from Drawable
    void draw() override {
        cout << "Drawing " << shapeType << " named: " << name << endl;
    }

    // Implement pure virtual from Saveable
    void save(const string& filename) override {
        cout << "Saving " << shapeType << " to: " << filename << endl;
        modified = false;
    }

    // Implement pure virtual from Saveable
    void load(const string& filename) override {
        cout << "Loading " << shapeType << " from: " << filename << endl;
    }

    // Override from Saveable
    bool isModified() const override {
        return modified;
    }

    // Getter
    string getShapeType() const {
        return shapeType;
    }

    // Setter (marks as modified)
    void setShapeType(const string& type) {
        shapeType = type;
        modified = true;
    }
};

// ===== DERIVED CLASS: Circle (Specific Shape) =====
class Circle : public Shape {
private:
    double radius;

public:
    Circle(const string& name, double r)
        : Shape("Circle", name), radius(r) {
        cout << "Circle constructor" << endl;
    }

    ~Circle() {
        cout << "Circle destructor" << endl;
    }

    // Override: draw implementation
    void draw() override {
        cout << "Drawing Circle '" << name << "' with radius " << radius << endl;
    }

    // Override: save implementation
    void save(const string& filename) override {
        cout << "Saving Circle to: " << filename 
             << " (radius: " << radius << ")" << endl;
        modified = false;
    }

    // Circle-specific method
    void setRadius(double r) {
        radius = r;
        modified = true;
        cout << "Circle radius changed to: " << radius << endl;
    }

    double getRadius() const {
        return radius;
    }
};

// ===== DERIVED CLASS: Rectangle (Specific Shape) =====
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(const string& name, double w, double h)
        : Shape("Rectangle", name), width(w), height(h) {
        cout << "Rectangle constructor" << endl;
    }

    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
    }

    void draw() override {
        cout << "Drawing Rectangle '" << name 
             << "' (" << width << "x" << height << ")" << endl;
    }

    void save(const string& filename) override {
        cout << "Saving Rectangle to: " << filename 
             << " (width: " << width << ", height: " << height << ")" << endl;
        modified = false;
    }

    void setDimensions(double w, double h) {
        width = w;
        height = h;
        modified = true;
        cout << "Rectangle dimensions changed to: " << width << "x" << height << endl;
    }

    double getArea() const {
        return width * height;
    }
};

int main() {
    cout << "===== CREATING SHAPES (Multiple Inheritance) =====" << endl;
    Circle circle("MyCircle", 5.0);
    Rectangle rectangle("MyRectangle", 10.0, 7.0);

    cout << "\n===== USING DRAWABLE INTERFACE =====" << endl;
    circle.draw();
    rectangle.draw();

    cout << "\n===== USING NAMED INTERFACE =====" << endl;
    circle.displayName();
    rectangle.displayName();

    cout << "\n===== USING SAVEABLE INTERFACE =====" << endl;
    cout << "Circle modified? " << (circle.isModified() ? "yes" : "no") << endl;
    circle.save("circle.txt");
    cout << "Circle modified? " << (circle.isModified() ? "yes" : "no") << endl;

    cout << "\n===== POLYMORPHISM WITH MULTIPLE BASE CLASSES =====" << endl;
    // Array of Drawable pointers
    Drawable* drawables[2] = {&circle, &rectangle};
    cout << "Drawing all shapes:" << endl;
    for (int i = 0; i < 2; i++) {
        drawables[i]->draw();
    }

    // Array of Saveable pointers
    Saveable* saveables[2] = {&circle, &rectangle};
    cout << "\nSaving all shapes:" << endl;
    for (int i = 0; i < 2; i++) {
        saveables[i]->save("file.dat");
    }

    cout << "\n===== MODIFYING AND CHECKING STATE =====" << endl;
    circle.setRadius(7.5);
    cout << "Circle modified? " << (circle.isModified() ? "yes" : "no") << endl;
    
    rectangle.setDimensions(12.0, 8.0);
    cout << "Rectangle area: " << rectangle.getArea() << endl;

    cout << "\n===== DESTRUCTORS CALLED (Reverse Order) =====" << endl;
    return 0;
}

/*
    Key Concepts Explained:
    
    1. Multiple Inheritance Syntax
       class Derived : public Base1, public Base2, public Base3 { ... };
       - Can inherit from multiple base classes
       - Each base class separated by comma
       - Order matters for constructor/destructor calls
    
    2. Constructor Call Order
       - Base classes constructed in declaration order
       - Circle -> Drawable -> Saveable -> Named -> Shape -> Circle
       - Destructors called in REVERSE order
    
    3. Pure Virtual Functions
       - Must implement ALL from all base classes
       - Shape implements from Drawable, Saveable
       - Circle/Rectangle override Shape's implementations
    
    4. Polymorphism with Multiple Base Classes
       - Drawable* ptr = &circle works
       - Saveable* ptr = &circle also works
       - Can use different base class pointers for same object
    
    5. IMPORTANT: Diamond Problem (Not shown here)
       - Occurs when both parents inherit from same base
       - Use virtual inheritance to avoid: class A : virtual public Base
       - Careful design avoids this issue
    
    6. When to Use Multiple Inheritance
       - Rarely: usually indicates design issues
       - Better alternative: Composition (has-a instead of is-a)
       - Use interfaces (abstract classes) for contracts
       - Consider separating concerns
    
    7. Constructor Initialization
       Base1(), Base2(), Base3(params), memberVar(value)
       - All constructors must be called
       - Order is left-to-right in inheritance declaration
       - Parents initialized before child
    
    8. Member Function Resolution
       - Can cause ambiguity if bases have same function name
       - Use Base1::func() or Base2::func() to disambiguate
       - Virtual inheritance needed for diamond fix
*/
