#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int roll;
    float cgpa;
};

int main() {
    Student s;

    cout << "Enter name roll cgpa: ";
    cin >> s.name >> s.roll >> s.cgpa;

    cout << "\nStudent Details\n";
    cout << "Name: " << s.name << "\n";
    cout << "Roll: " << s.roll << "\n";
    cout << "CGPA: " << s.cgpa << "\n";

    return 0;
}
