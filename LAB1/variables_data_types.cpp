#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int age;
    double height;
    char grade;
    bool isStudent;
    string name;

    cout << "Enter name age height grade isStudent(0/1): ";
    cin >> name >> age >> height >> grade >> isStudent;

    cout << "\nName: " << name;
    cout << "\nAge: " << age;
    cout << "\nHeight: " << fixed << setprecision(2) << height;
    cout << "\nGrade: " << grade;
    cout << "\nStudent: " << boolalpha << isStudent << "\n";

    return 0;
}
