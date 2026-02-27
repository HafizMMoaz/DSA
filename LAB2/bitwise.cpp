#include <iostream>
using namespace std;
int main() {
    int a = 5; // 0101 in binary
    int b = 3; // 0011 in binary 

    cout << "a & b: " << (a & b) << endl; // Bitwise AND
    cout << "a | b: " << (a | b) << endl; // Bitwise OR
    cout << "a ^ b: " << (a ^ b) << endl; // Bitwise XOR
    cout << "~a: " << (~a) << endl;        // Bitwise NOT 11010
    cout << "a << 1: " << (a << 1) << endl; // Left shift 1010 (x*2^n)
    cout << "b >> 1: " << (b >> 1) << endl; // Right shift 0001 (x/2^n)

    return 0;
}