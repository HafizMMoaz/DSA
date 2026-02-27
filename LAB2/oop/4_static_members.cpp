/*
    4) STATIC MEMBERS & STATIC FUNCTIONS
    
    Explanation:
    - Static Variable: Shared by all objects of a class (only one copy)
    - Static Function: Can access only static members, called without object
    - Use Case: Counting objects, global class-level data, utility functions
*/

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    // Instance variables: Each object has its own copy
    string accountHolder;
    double balance;
    
    // Static variable: SHARED by all BankAccount objects (only one copy in memory)
    static int totalAccounts;      // Count of all accounts created
    static double totalBalance;    // Sum of all balances

    // Static constant: Class-level constant
    static const double MINIMUM_BALANCE;

public:
    // Constructor: Each time object created
    BankAccount(string holder, double initialBalance) 
        : accountHolder(holder), balance(initialBalance) {
        
        // Modify static members (shared by all objects)
        totalAccounts++;      // Increment total count
        totalBalance += balance;
        
        cout << "Account created for " << accountHolder 
             << " with balance $" << balance << endl;
    }

    // Destructor: When object destroyed
    ~BankAccount() {
        // Update static members when account deleted
        totalBalance -= balance;
        totalAccounts--;
    }

    // Instance function: Can access both instance and static members
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBalance += amount;
            cout << accountHolder << " deposited $" << amount << endl;
        }
    }

    // Instance function: Can access both instance and static members
    void withdraw(double amount) {
        if (amount > 0 && (balance - amount >= MINIMUM_BALANCE)) {
            balance -= amount;
            totalBalance -= amount;
            cout << accountHolder << " withdrew $" << amount << endl;
        } else {
            cout << "Withdrawal failed - insufficient funds or below minimum" << endl;
        }
    }

    // Getter: Returns instance variable
    double getBalance() const {
        return balance;
    }

    // Getter: Returns instance variable
    string getAccountHolder() const {
        return accountHolder;
    }

    // Static function: Can access ONLY static members
    // Called using ClassName::functionName()
    // NO 'this' pointer available
    static int getTotalAccounts() {
        return totalAccounts;
    }

    // Static function: Returns total balance of all accounts
    static double getTotalBalance() {
        return totalBalance;
    }

    // Static function: Returns minimum balance requirement
    static double getMinimumBalance() {
        return MINIMUM_BALANCE;
    }

    // Static function: Displays bank statistics
    static void displayBankStats() {
        cout << "\n===== BANK STATISTICS =====" << endl;
        cout << "Total Accounts: " << totalAccounts << endl;
        cout << "Total Balance in Bank: $" << totalBalance << endl;
        if (totalAccounts > 0) {
            cout << "Average Balance: $" << (totalBalance / totalAccounts) << endl;
        }
    }
};

// Static variable definitions OUTSIDE the class (required!)
// Initialize the static variables
int BankAccount::totalAccounts = 0;
double BankAccount::totalBalance = 0.0;

// Static constant definition
const double BankAccount::MINIMUM_BALANCE = 100.0;

int main() {
    cout << "===== Creating Bank Accounts =====" << endl;
    
    BankAccount acc1("Alice", 1000);
    BankAccount acc2("Bob", 1500);
    BankAccount acc3("Charlie", 2000);

    cout << "\n===== Accessing Static Members via Static Functions =====" << endl;
    // Call static function WITHOUT creating object
    cout << "Total Accounts (static): " << BankAccount::getTotalAccounts() << endl;
    cout << "Total Balance (static): $" << BankAccount::getTotalBalance() << endl;

    cout << "\n===== Performing Transactions =====" << endl;
    acc1.deposit(500);      // Alice deposits $500
    BankAccount::displayBankStats();  // Show updated stats

    acc2.withdraw(300);     // Bob withdraws $300
    BankAccount::displayBankStats();  // Show updated stats

    cout << "\n===== Instance Variables vs Static Variables =====" << endl;
    cout << "Alice's Balance: $" << acc1.getBalance() << " (instance variable)" << endl;
    cout << "Bob's Balance: $" << acc2.getBalance() << " (instance variable)" << endl;
    cout << "Total in Bank: $" << BankAccount::getTotalBalance() 
         << " (static variable - shared)" << endl;

    cout << "\n===== Attempting Invalid Withdrawal =====" << endl;
    cout << "Minimum Balance Required: $" << BankAccount::getMinimumBalance() << endl;
    acc1.withdraw(2000);  // Should fail - would go below minimum

    cout << "\n===== Final Bank Statistics =====" << endl;
    BankAccount::displayBankStats();

    cout << "\n===== Account Deletion (Accounts Going Out of Scope) =====" << endl;
    return 0;
    // As each account destroyed, totalAccounts and totalBalance updated
}

/*
    Key Concepts Explained:
    
    1. Static Variables
       - Declared with 'static' keyword inside class
       - Only ONE copy shared by ALL objects
       - Initialized outside class: ClassName::variable = value
       - Memory allocated once, persists for program lifetime
    
    2. Static Functions
       - No 'this' pointer (not bound to any object)
       - Can only access static members and static functions
       - Called using ClassName::functionName()
       - Useful for utilities, factory methods, statistics
    
    3. Use Cases
       - totalAccounts: Count of instances created
       - totalBalance: Aggregate data across all objects
       - Logging: Shared log file handles
       - Counters: Object creation/deletion
       - Global configuration: Class-level settings
    
    4. Static Constant
       - const double MINIMUM_BALANCE = 100.0;
       - Compile-time constant shared by all objects
    
    5. Important Rules
       - Static variables MUST be defined outside class
       - No initialization in class definition (except const)
       - Static functions have no access to 'this'
       - Each instance shares same static data
       
    6. When to Use Static
       - Need data shared across ALL instances
       - Factory methods (create objects)
       - Utility functions (don't need object state)
       - Counters and statistics
*/
