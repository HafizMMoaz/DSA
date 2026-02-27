/*
    8) ENCAPSULATION - Data Hiding & Information Hiding
    
    Explanation:
    - Encapsulation: Bundle data + methods together, hide internals
    - Data Hiding: Private members accessible only through public interface
    - Benefits: Control access, validate data, implement changes without breaking code
    - Access Levels: private (only class), protected (class+derived), public (everyone)
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// ===== ENCAPSULATED CLASS: BankAccount =====
class BankAccount {
private:
    // Private data: Hidden from outside world
    string accountNumber;
    double balance;
    string accountHolder;
    int pin;
    vector<string> transactionHistory;

    // Private helper function: Only used internally
    // Validates PIN without exposing it
    bool validatePIN(int enteredPin) const {
        return pin == enteredPin;
    }

    // Private helper: Records transactions internally
    void recordTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

public:
    // Constructor: Sets initial state
    BankAccount(string accNum, string holder, int initialPin, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), pin(initialPin), 
          balance(initialBalance) {
        cout << "Account created for " << accountHolder << endl;
        recordTransaction("Account opened with balance: $" + to_string(initialBalance));
    }

    // Destructor
    ~BankAccount() {
        cout << "Account closed for " << accountHolder << endl;
    }

    // ===== GETTER FUNCTIONS =====
    // Allow READ-ONLY access to private data
    // const guarantees no modification

    // Getter: Account number (safe - read only)
    string getAccountNumber() const {
        return accountNumber;
    }

    // Getter: Account holder name (safe - read only)
    string getAccountHolder() const {
        return accountHolder;
    }

    // Getter: Current balance (safe - read only)
    double getBalance() const {
        return balance;
    }

    // ===== SETTER FUNCTIONS =====
    // Control HOW data can be modified
    // Validate before allowing change

    // Setter: Change account holder name
    // Validation: Name cannot be empty
    bool setAccountHolder(string newName) {
        if (newName.empty()) {
            cout << "Error: Name cannot be empty!" << endl;
            return false;
        }
        accountHolder = newName;
        return true;
    }

    // Setter: Change PIN
    // Security: Must provide old PIN and new PIN
    bool changePIN(int oldPin, int newPin) {
        if (!validatePIN(oldPin)) {
            cout << "Error: Invalid current PIN!" << endl;
            return false;
        }
        if (newPin < 1000 || newPin > 9999) {
            cout << "Error: PIN must be 4 digits!" << endl;
            return false;
        }
        pin = newPin;
        cout << "PIN changed successfully" << endl;
        return true;
    }

    // ===== CONTROLLED OPERATIONS =====
    // Business logic that controls access to private data

    // Deposit: Add money to account
    // Pre-conditions:
    //   - Amount must be positive
    //   - PIN must be correct (security)
    bool deposit(double amount, int enteredPin) {
        if (!validatePIN(enteredPin)) {
            cout << "Error: Invalid PIN!" << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive!" << endl;
            return false;
        }
        balance += amount;
        recordTransaction("Deposit: +$" + to_string(amount));
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
        return true;
    }

    // Withdraw: Remove money from account
    // Pre-conditions:
    //   - Amount must be positive
    //   - Sufficient balance must exist
    //   - PIN must be correct
    //   - Amount must not exceed limit ($1000/day)
    bool withdraw(double amount, int enteredPin) {
        if (!validatePIN(enteredPin)) {
            cout << "Error: Invalid PIN!" << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive!" << endl;
            return false;
        }
        if (amount > 1000) {
            cout << "Error: Daily withdrawal limit is $1000!" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Error: Insufficient funds!" << endl;
            cout << "Available balance: $" << balance << endl;
            return false;
        }
        balance -= amount;
        recordTransaction("Withdrawal: -$" + to_string(amount));
        cout << "Withdrawn: $" << amount << ". New balance: $" << balance << endl;
        return true;
    }

    // Transfer: Send money to another account
    // Complex operation using multiple validations
    bool transfer(BankAccount& recipient, double amount, int enteredPin) {
        if (!validatePIN(enteredPin)) {
            cout << "Error: Invalid PIN!" << endl;
            return false;
        }
        if (amount <= 0) {
            cout << "Error: Transfer amount must be positive!" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Error: Insufficient funds for transfer!" << endl;
            return false;
        }
        
        // Perform transfer
        balance -= amount;
        recipient.balance += amount;
        
        recordTransaction("Transfer to " + recipient.accountNumber + ": -$" + to_string(amount));
        recipient.recordTransaction("Transfer from " + accountNumber + ": +$" + to_string(amount));
        
        cout << "Transferred $" << amount << " to " << recipient.accountNumber << endl;
        return true;
    }

    // Check interest earned (calculation based on balance)
    double getInterestEarned() const {
        return balance * 0.04;  // 4% annual interest
    }

    // Apply interest to account
    void applyInterest(int enteredPin) {
        if (!validatePIN(enteredPin)) {
            cout << "Error: Invalid PIN!" << endl;
            return;
        }
        double interest = getInterestEarned();
        balance += interest;
        recordTransaction("Interest applied: +$" + to_string(interest));
        cout << "Interest applied: $" << interest << endl;
    }

    // Display transaction history (limited - only holder can see)
    void displayHistory(int enteredPin) const {
        if (!validatePIN(enteredPin)) {
            cout << "Error: Invalid PIN!" << endl;
            return;
        }
        cout << "\n--- Transaction History for " << accountNumber << " ---" << endl;
        for (const auto& transaction : transactionHistory) {
            cout << "  " << transaction << endl;
        }
    }
};

int main() {
    cout << "===== CREATING ENCAPSULATED ACCOUNTS =====" << endl;
    BankAccount account1("ACC001", "Alice", 1234, 1000);
    BankAccount account2("ACC002", "Bob", 5678, 500);

    cout << "\n===== ACCESSING PRIVATE DATA VIA GETTERS =====" << endl;
    cout << "Account: " << account1.getAccountNumber() << endl;
    cout << "Holder: " << account1.getAccountHolder() << endl;
    cout << "Balance: $" << account1.getBalance() << endl;

    cout << "\n===== ATTEMPTING INVALID OPERATIONS (Encapsulation Prevents) =====" << endl;
    account1.deposit(-100, 1234);      // Negative amount rejected
    account1.withdraw(2000, 1234);     // Exceeds limit rejected
    account1.withdraw(500, 9999);      // Wrong PIN rejected

    cout << "\n===== VALID OPERATIONS =====" << endl;
    account1.deposit(500, 1234);       // Correct PIN, valid amount
    account1.withdraw(250, 1234);      // Correct PIN, valid amount

    cout << "\n===== CALCULATING INTEREST =====" << endl;
    cout << "Interest earned on $" << account1.getBalance() 
         << ": $" << account1.getInterestEarned() << endl;
    account1.applyInterest(1234);

    cout << "\n===== TRANSFER BETWEEN ACCOUNTS =====" << endl;
    account1.transfer(account2, 300, 1234);  // Correct PIN
    cout << "Account 1 balance: $" << account1.getBalance() << endl;
    cout << "Account 2 balance: $" << account2.getBalance() << endl;

    cout << "\n===== CHANGING PIN =====" << endl;
    account1.changePIN(9999, 4321);    // Wrong old PIN
    account1.changePIN(1234, 4321);    // Correct old PIN
    account1.withdraw(100, 4321);      // Using new PIN

    cout << "\n===== VIEWING TRANSACTION HISTORY =====" << endl;
    account1.displayHistory(4321);     // Correct PIN

    cout << "\n===== ATTEMPTING UNAUTHORIZED ACCESS =====" << endl;
    account1.displayHistory(9999);     // Wrong PIN

    cout << "\n===== PROGRAM END (Destructor Called) =====" << endl;
    return 0;
}

/*
    Key Concepts Explained:
    
    1. Data Hiding (Private Members)
       - accountNumber, balance, pin: Hidden from outside
       - Can only be accessed through public interface
       - Prevents accidental or malicious modification
    
    2. Getters (Accessors)
       - Read-only access to private data
       - Return by value or const reference
       - Marked const: promise not to modify object
       - Control what information is exposed
    
    3. Setters (Mutators)
       - Controlled modification of private data
       - Can validate before allowing change
       - Example: changePIN requires old PIN (security)
       - bool return indicates success/failure
    
    4. Business Logic Methods
       - deposit(), withdraw(): Complex operations
       - Enforce pre-conditions (validations)
       - Maintain class invariants (balance >= 0)
       - Cannot be done by simple setter
    
    5. Private Helper Functions
       - validatePIN(): Used internally only
       - recordTransaction(): Maintains history
       - Hidden complexity from users
    
    6. Benefits of Encapsulation
       - Validation: No invalid state possible
       - Security: PIN protection, limited access
       - Flexibility: Can change internals without breaking code
       - Interface: Clear contract for users
       - Maintainability: Logic in one place
    
    7. Invariants
       - Class maintains consistent state
       - balance >= 0 always
       - pin always 4 digits
       - transactions always recorded
    
    8. Information Hiding Levels
       - private: Best for internal state
       - protected: For derived classes
       - public: For external users
       - Each level has purpose
*/
