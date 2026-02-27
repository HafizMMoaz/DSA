# Secure File-Based Banking System

## OBJECTIVE
Design and implement a secure banking transaction system
using C++. The system must use OOP, pointers, vectors,
arrays, file handling, and bitwise operators.

---

## CONCEPTS COVERED
- OOP (Inheritance, Polymorphism, Encapsulation)
- Pointers and Dynamic Memory
- File Handling (fstream)
- Arrays
- Vectors
- Bitwise Operators
- System Design Thinking

---

## FUNCTIONAL REQUIREMENTS

### 1) ACCOUNT CLASS HIERARCHY

Create an abstract base class:

```cpp
class Account
{
protected:
int accountId;
string name;
double balance;
unsigned int permissions;
vector<double> transactions;

public:
virtual void deposit(double amount) = 0;
virtual void withdraw(double amount) = 0;
virtual void saveToFile() = 0;
virtual void loadFromFile() = 0;
virtual ~Account() {}
};
```

Create derived classes:
- SavingsAccount
- CurrentAccount

Use runtime polymorphism properly.

---

### 2) BITWISE PERMISSION SYSTEM

Each account must have permission flags stored in an
unsigned int.

Bit Flags:

```text
1 -> Can Withdraw
2 -> Can Deposit
4 -> Can Transfer
8 -> VIP Account
```

Example:

```cpp
permissions = 1 | 2 | 4;
```

You must:
- Use bitwise OR to assign permissions
- Use bitwise AND to check permissions
- Deny operation if permission not granted

Example:

```cpp
if (permissions & 1) // Can Withdraw
```

---

### 3) POINTER USAGE

All accounts must be created dynamically:

```cpp
Account* acc = new SavingsAccount(...);
```

Store accounts in:

```cpp
vector<Account*> accounts;
```

You must:
- Use polymorphism correctly
- Implement destructors
- Delete all allocated memory before exit
- Avoid memory leaks

---

### 4) TRANSACTION MANAGEMENT

Each account must:
- Store transaction history using vector<double>
- Record positive values for deposits
- Record negative values for withdrawals

---

### 5) FILE HANDLING

Implement:
- SAVE ALL ACCOUNTS TO FILE
- LOAD ALL ACCOUNTS FROM FILE

File format example:

```text
ACCOUNT Savings
1001 Ali 5000 7
TRANSACTIONS
1000
-500
300

ACCOUNT Current
1002 Sara 8000 3
TRANSACTIONS
2000
-1000
```

Where:
7 = Withdraw + Deposit + Transfer

You must:
- Save account type
- Save permissions
- Save transaction history
- Correctly reconstruct objects when loading

---

### 6) MONTHLY SUMMARY USING ARRAYS

Create:

```cpp
double monthlyTotals[12];
```

Calculate:
- Total deposits per month
- Total withdrawals per month
- Net monthly balance change
- Use array indexing properly.

---

### 7) TRANSACTION COMPRESSION (ADVANCED)

Compress transaction type and amount into a single
unsigned int using bit manipulation.

Structure:

```text
[ 4 bits transaction type ][ 28 bits amount ]
```

Example:

Type:
- 1 = Deposit
- 2 = Withdrawal
- 3 = Transfer

Use:
- Bit shifting (<<, >>)
- Bit masking
- Bitwise OR and AND

Students must:
- Encode transaction
- Decode transaction

---

### 8) SAMPLE INTERACTION

1. Create Account
2. Deposit
3. Withdraw
4. Show Account
5. Save to File
6. Load from File
7. Exit

---

## CONSTRAINTS
- Do NOT use STL map or set.
- Must use vector<Account*>.
- Must use dynamic memory.
- Must use bitwise operators explicitly.
- Proper destructor implementation required.

---

## EVALUATION CRITERIA
- Correct use of OOP and polymorphism
- Proper dynamic memory handling
- Correct bitwise logic
- Proper file persistence
- Clean modular design
- No memory leaks

---

## BONUS FEATURES
- Implement account transfer between accounts
- Implement overdraft limit
- Implement interest calculation
- Encrypt file using simple XOR cipher
- Implement admin mode with full permissions

---

## END
