#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

double average(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

bool isEven(int value) {
    return value % 2 == 0;
}

int main() {
    int x, y, z;
    cout << "Enter three integers: ";
    cin >> x >> y >> z;

    cout << "add(x, y): " << add(x, y) << "\n";
    cout << "average(x, y, z): " << average(x, y, z) << "\n";
    cout << "isEven(z): " << (isEven(z) ? "true" : "false") << "\n";

    return 0;
}
