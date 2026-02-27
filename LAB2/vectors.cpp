/* Documnentation
     std::vector<int> (and std::vector<T>) common member functions:

     1) Constructors
         - vector<T> v;
         - vector<T> v(n);
         - vector<T> v(n, value);
         - vector<T> v{a, b, c};

     2) Element access
         - v[i]                // no bounds check
         - v.at(i)             // bounds-checked
         - v.front()
         - v.back()
         - v.data()

     3) Capacity
         - v.empty()
         - v.size()
         - v.capacity()
         - v.max_size()
         - v.reserve(n)
         - v.shrink_to_fit()

     4) Modifiers
         - v.push_back(x)
         - v.pop_back()
         - v.insert(pos, x)
         - v.insert(pos, count, x)
         - v.insert(pos, first, last)
         - v.emplace(pos, args...)
         - v.emplace_back(args...)
         - v.erase(pos)
         - v.erase(first, last)
         - v.clear()
         - v.assign(count, value)
         - v.assign(first, last)
         - v.resize(n)
         - v.resize(n, value)
         - v.swap(other)

     5) Iterators
         - v.begin(), v.end()
         - v.cbegin(), v.cend()
         - v.rbegin(), v.rend()
         - v.crbegin(), v.crend()
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5}; // Declare and initialize a vector of integers

    cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " "; // Access and print each element of the vector
    }
    cout << endl;

    for (int num : vec) { // Range-based for loop to iterate through the vector
        cout << num << " "; // Print each element of the vector
    }
    cout << endl;

    vec.push_back(6); // Add an element to the end of the vector
    cout << "After adding an element: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    vec.pop_back(); // Remove the last element from the vector
    cout << "After removing the last element: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}