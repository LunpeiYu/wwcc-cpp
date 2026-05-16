#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {

    private:
        // Original: Members were public (no encapsulation).
        // Now: Made all data members private to protect internal state.
        string customerName;
        double balance;
        bool isOpen;
        int accountNumber;
        string accountType;

        // Original: Interest rates were magic numbers.
        // Now: Extracted into name constants for clarity and maintainability.
        const double savingInterest = 0.03;
        const double checkingInterest = 0.01;
        const double businessInterest = 0.005;
    
    public:
        // Original: setup() method was used instead of constructor.
        // Now: Proper constructor initialization.
        BankAccount(string name, int number, string type) 
        : customerName(name), balance(0.0), isOpen(true), accountNumber(number) {
        
        accountType = "checking";
        
        // Validate account type
        if (type == "savings" || type == "checking" || type == "business") {

            accountType = type;
        }
        else {

            cout << "\nInvalid account type. Defaulting to checking!" << endl;
            accountType = "checking";
        }
        }
    // Original: No validation for deposit amount.
    // Now: Reject invalid (<=0) deposits amount.
    void deposit(double depositAmount) {
        
        if (depositAmount <= 0) {
            cout << "\nInvalid deposit amount!" << endl;
            return;
        }

        balance += depositAmount;

        cout << "Deposit successful: $" << depositAmount << endl;
        cout << "New balance: $" << balance << endl;
    }

    // Original: No overdraft protection.
    // Now: Added validation to prevent negative balance.
    void withdraw(double withdrawAmount) {
        
        if (withdrawAmount <= 0) {
            cout << "Invalid withdraw amount!" << endl;
            return;
        }

        if (withdrawAmount > balance) {
            cout << "Insufficient balance!" << endl;
            return;
        }
        balance -= withdrawAmount;

        cout << "\nWithdrawal successful: $" << withdrawAmount << endl;
        cout << "New balance: $" << balance << endl;
    }

    // Original: Interest logic used hard0code values.
    // Now: Used named constants and calculated interest separately.
    void applyInterest() {

        double interestAmount = 0.0;

        if (accountType == "savings") {
            interestAmount = balance * savingInterest;
        }
        else if (accountType == "checking") {
            interestAmount = balance * checkingInterest;
        }
        else if (accountType == "business") {
            interestAmount = balance * businessInterest;
        }

        balance += interestAmount;

        cout << "\nInterest applied: $" << interestAmount << endl;
        cout << "New Balance: $" << balance << endl;
    }

    // Original: Getter not marked const.
    // NOw: Added const correctness.
    double getBalance() const {
        return balance;
    }

    // Original: No structured output format.
    // Now: Improved readability and formatting.
    void printAccountInformation() const {

        cout << "Account Information" << endl;
        cout << "====================" << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Customer Name:  " << customerName << endl;
        cout << "Balance:        " << "$" << balance << endl;
        cout << "Account Type:   " << accountType << endl;
        cout << "Status:         " << (isOpen ? "Open" : "Closed") << endl;
        cout << "====================" << endl;
    }

    // Original: No feedback when closing account.
    // Now: Added confirmation message.
    void closeAccount() {
        isOpen = false;
        cout << "\nAccount has been closed!" << endl;
    }
};

// Test Program (Main Function)
int main() {

    cout << fixed << setprecision(2);

    // Test 1 : Create a valid saving account
    BankAccount acc1("Alan Smith", 1001, "savings");

    // Test 2: Basic operations(deposit, withdraw, interest)
    acc1.deposit(1000);
    acc1.withdraw(300);
    acc1.applyInterest();

    // Test 3: Invalid input handling
    acc1.deposit(-500);
    acc1.withdraw(-200);
    acc1.withdraw(9999);

    // Test 4: Check current balance using getter
    cout << "\nAccount balance: $" << acc1.getBalance() << endl << endl;
    
    // Test 5: Display account information after transactions
    acc1.printAccountInformation();

    // Test 6: Invalid account type handling and Print account with default type
    BankAccount acc2("Tony Mike", 1002, "apple");
    acc2.printAccountInformation();

    // Test 7: Close account and Verify account status after closing
    acc1.closeAccount();
    acc1.printAccountInformation();

    return 0;
}