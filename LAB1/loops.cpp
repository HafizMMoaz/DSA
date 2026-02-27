#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "For loop: ";
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "While loop (sum 1..n): ";
    int i = 1;
    int sum = 0;
    while (i <= n) {
        sum += i;
        ++i;
    }
    cout << sum << "\n";

    cout << "Do-while loop (countdown): ";
    int count = n;
    if (count <= 0) {
        cout << "none\n";
        return 0;
    }

    do {
        cout << count << " ";
        --count;
    } while (count > 0);

    cout << "\n";
    return 0;
}
