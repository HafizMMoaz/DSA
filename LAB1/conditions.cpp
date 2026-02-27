#include <iostream>

using namespace std;

int main() {
    int choice;
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice\n";
        return 0;
    }

    switch (choice) {
        case 1:
            cout << "You selected addition\n";
            break;
        case 2:
            cout << "You selected subtraction\n";
            break;
        case 3:
            cout << "You selected multiplication\n";
            break;
        default:
            cout << "Unexpected input\n";
            break;
    }

    int marks;
    cout << "Enter marks (0-100): ";
    cin >> marks;

    if (marks >= 90) {
        cout << "Grade A\n";
    } else if (marks >= 75) {
        cout << "Grade B\n";
    } else if (marks >= 60) {
        cout << "Grade C\n";
    } else {
        cout << "Grade D\n";
    }

    return 0;
}
