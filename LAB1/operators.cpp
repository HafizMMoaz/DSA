/*
assignment operator
arithematic opeartor
relational operator
logical operator
increment and decrement operator
*/

#include <iostream>
using namespace std;
main()
{
    int b = 4; // declaration
    int a = 10; // initialization
    // a + b where + is an operator and a,b are operands

    //------------ ASSIGNMENT OPERATOR ------------
    b = a; // assignment operator => assigning value of a to b
    cout << "Value of b is: " << b << endl; // output the value of b
    b += 5; // compound assignment operator (b = b + 5)
    b -= 3; // compound assignment operator (b = b - 3)
    b *= 2; // compound assignment operator (b = b * 2)
    b /= 4; // compound assignment operator (b = b / 4)
    b %= 3; // compound assignment operator (b = b % 3)

    //------------ ARITHMETIC OPERATOR ------------

    int sum = a + b; // addition operator
    cout << "The sum of a and b is: " << sum << endl; // output the sum
    int diff = a - b; // subtraction operator
    cout << "The difference of a and b is: " << diff << endl; // output the difference
    int prod = a * b; // multiplication operator
    cout << "The product of a and b is: " << prod << endl; // output the product
    int quot = a / b; // division operator
    cout << "The quotient of a and b is: " << quot << endl; // output the quotient
    int mod = a % b; // modulus operator
    cout << "The modulus/reminder of a and b is: " << mod << endl; // output the modulus

    //------------ RELATIONAL OPERATOR ------------
    cout << "Value of a is: " << a << endl; // output the value of a
    cout << "Value of b is: " << b << endl; // output the value
    bool isEqual = (a == b); // equal to operator
    cout << "Is a equal to b? " << isEqual << endl; // output the result of equality check
    bool isNotEqual = (a != b); // not equal to operator
    cout << "Is a not equal to b? " << isNotEqual << endl; // output the result of inequality check
    bool isGreater = (a > b); // greater than operator
    cout << "Is a greater than b? " << isGreater << endl; // output the result of greater than check
    bool isLess = (a < b); // less than operator
    cout << "Is a less than b? " << isLess << endl; // output the result of less than check
    bool isGreaterOrEqual = (a >= b); // greater than or equal to operator
    cout << "Is a greater than or equal to b? " << isGreaterOrEqual << endl; // output the result of greater than or equal to check
    bool isLessOrEqual = (a <= b); // less than or equal to operator
    cout << "Is a less than or equal to b? " << isLessOrEqual << endl; // output the result of less than or equal to check

    //------------ LOGICAL OPERATOR ------------
    bool logicalAnd = (a > 5 && b > 5); // logical AND operator
    cout << "Logical AND result: " << logicalAnd << endl;
    bool logicalOr = (a > 5 || b > 5); // logical OR
    cout << "Logical OR result: " << logicalOr << endl;
    bool logicalNot = !(a > 5); // logical NOT operator
    cout << "Logical NOT result: " << logicalNot << endl;

    //------------ INCREMENT AND DECREMENT OPERATOR ------------
    a++; // increment operator (postfix) a = a + 1 => a += 1
    ++b; // increment operator (prefix)

    cout << "Value of a after increment: " << a << endl; // output the value of a after increment
    cout << "Value of b after increment: " << b << endl; // output the value of b after increment
    a--;                                                 // decrement operator (postfix)
    --b;                                                 // decrement operator (prefix)

    cout << "Value of a after decrement: " << a << endl; // output the value of a after decrement
    cout << "Value of b after decrement: " << b << endl; // output the value


    // postfix and prefix
    int x = 10;
    int y;
    y = x--;
    cout << "Value of x: " << x << endl; // output the value of x after post-increment
    cout << "Value of y: " << y << endl; // output the value of y

}