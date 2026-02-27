/* Documentation
     C++ Array Function Reference

     A) Built-in array (T arr[N])
         - No member functions (cannot do arr.size(), arr.push_back(), etc.)
         - Access: arr[i]
         - Number of elements (same scope only):
              size_t n = sizeof(arr) / sizeof(arr[0]);
         - First/last pointers:
              begin(arr), end(arr)            // from <iterator>

     B) Useful functions with built-in arrays (from <algorithm>)
         - sort(arr, arr + n)
         - reverse(arr, arr + n)
         - fill(arr, arr + n, value)
         - copy(src, src + n, dest)
         - find(arr, arr + n, x)
         - count(arr, arr + n, x)
         - min_element(arr, arr + n)
         - max_element(arr, arr + n)
         - binary_search(arr, arr + n, x)      // array must be sorted
         - lower_bound(arr, arr + n, x)        // sorted
         - upper_bound(arr, arr + n, x)        // sorted

     C) C-style helpers (from <cstring>) for character/byte arrays
         - strlen(str)
         - strcpy(dest, src)
         - strncpy(dest, src, n)
         - strcat(dest, src)
         - strcmp(a, b)
         - memset(arr, value, bytes)
         - memcpy(dest, src, bytes)

     D) std::array<T, N> (recommended fixed-size array type)
         - at(i), operator[](i)
         - front(), back(), data()
         - empty(), size(), max_size()
         - fill(value)
         - swap(other)
         - begin(), end(), rbegin(), rend()
         - cbegin(), cend(), crbegin(), crend()

     E) Multi-dimensional arrays
         - Access: arr2[i][j], arr3[i][j][k]
         - Common traversal: nested loops
*/

#include <iostream>
using namespace std;
int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of integers

    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Access and print each element of the array
    }
    cout << endl;


    for (int i : arr) { // Range-based for loop to iterate through the array
        cout << i << " "; // Print each element of the array
    }

    cout << endl;

    int arr2[5][5] = { // Declare and initialize a 2D array (array of arrays)
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    cout << "2D Array elements:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }


    int arr3[3][3][3] = { // Declare and initialize a 3D array (array of arrays of arrays)
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        },
        {
            {19, 20, 21},
            {22, 23, 24},
            {25, 26, 27}
        }
    };

    cout << "3D Array elements:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                cout << arr3[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    return 0;
}