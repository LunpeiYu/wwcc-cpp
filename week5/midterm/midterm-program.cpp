// =======================================
// Project: Simple Bank System
// Author: Lunpei Yu
// Description: Simple banking system with
// account creation, deposit, withdrawal,
// transfer, account information, 
// transaction history, and account statement
// =======================================

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

// =================== DATA STRUCTURES ====================

// Store transaction (type + amount)
struct Transaction{
    string type;
    double amount;
    string date;    
};

// Store account information and transaction history
struct Account {
    int accountNumber;
    string holderName;
    double balance;
    Transaction history[100];
    int transactionCount;

};

// ==================== GLOBAL VARIABLES ====================

// Maximum number of accounts
const int MAX = 100;
// Array storing all accounts
Account accounts[MAX];
// Track how many accounts are created
int accountCount = 0;
// Generate account numbers automatically
int nextAccountNumber = 1001; 

// ==================== FUNCTION PROTOTYPES ====================
void displayMenu();
void createAccount();
void deposit();
void withdraw();
void transfer();

void searchAndShowAccount();
int searchAccount(int searchAccountNumber);
void showAccount(int index);

void searchAndShowTransaction();
void addTransaction(int index, string type, double amount);
void showTransaction(int index);
void showStatement();

string getCurrentDate();

// ==================== MAIN FUNCTION ====================
int main () {

    // Format all money outputs to 2 decimal places
    cout << fixed << setprecision(2);

    int choice;

    do {
        displayMenu();

        cin >> choice;

        if(cin.fail()) {
            cout << "Invalid input! Please enter a number (1-8)!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice < 1 || choice >8) {
            cout << "Invalid choice. Please enter (1-8)." << endl;
            continue;
        }

        switch (choice) {

            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                transfer();
                break;
            case 5:
                searchAndShowAccount();
                break;
            case 6 :
                searchAndShowTransaction();
                break;
            case 7 :
                showStatement();
                break;
            case 8:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter(1-8)." << endl;
                break;
        }

    } while (choice!=8);
    
    return 0;
}
    
// ==================== FUNCTIONS =====================

// Display main menu options
void displayMenu() {

    cout << "\n==================== WWCC BANK MENU ====================\n" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Transfer" << endl;
    cout << "5. Show Account Information" << endl;
    cout << "6. Show Transaction History" << endl;
    cout << "7. Show Statement" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice (1-8): ";
}

// Create a new account
void createAccount(){

    if (accountCount >= MAX) {
        cout << "You have reached max accounts, cannot create more accounts!" << endl;
        return;
    }

    Account newAccount;

    newAccount.accountNumber = nextAccountNumber;
    nextAccountNumber++;

    cin.ignore(10000, '\n');

    cout << "Enter account holder name: ";
    getline(cin, newAccount.holderName);

    newAccount.balance = 0.00;
    newAccount.transactionCount = 0;

    accounts[accountCount] = newAccount;
    accountCount++;

    cout << "Account created successfully!" << endl;
    cout << "Your account number is: " << newAccount.accountNumber << endl;
}

// Search account index by account number
// Return index if found, otherwise -1
int searchAccount(int searchAccountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == searchAccountNumber) {
            return i;
        }
    }
    return -1;
}

// Deposit money into account
void deposit() {

    int depositAccountNumber;
    double depositAmount;

    cout << "Enter the account number you want to deposit: ";
    cin >> depositAccountNumber;
    cin.ignore(10000, '\n');

    int index = searchAccount(depositAccountNumber);

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }

    while(true) {
         cout << "Enter deposit amount: ";
         cin >> depositAmount;

         if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Input must be a valid number!" << endl;
            return;
        }

         if (depositAmount > 0) {
            break;
         }
         cout << "Amount must be positive! Please try again." << endl;
         
    }
       
    accounts[index].balance += depositAmount;
    addTransaction(index, "deposit", depositAmount);

    cout << "Deposit successful!" << endl;
    cout << "New balance: $" << accounts[index].balance << endl;

}

// Withdraw money from account
void withdraw() {

    int withdrawAccountNumber;
    double withdrawAmount;

    cout << "Enter account number: ";
    cin >> withdrawAccountNumber;
    cin.ignore(10000, '\n');

    int index = searchAccount(withdrawAccountNumber);

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }

    while (true) {

        cout << "Enter withdraw amount: ";
        cin >> withdrawAmount;

        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Error: Input must be a valid number!" << endl;
            return;
        }

        if (withdrawAmount <= 0) {
            cout << "Invalid amount. Please try again." << endl;
            continue;
        }

        if (withdrawAmount > accounts[index].balance) {
            cout << "Not enough balance. Please try again." << endl;
            continue;
        }
        break;
    }
    accounts[index].balance -= withdrawAmount;
    addTransaction(index, "withdraw", withdrawAmount);

    cout << "Withdrawal successful!" << endl;
    cout << "New balance: $" << accounts[index].balance << endl;

}

// Transfer money between two accounts
void transfer() {

    int transferFromAccount, transferToAccount;
    double transferAmount;

    cout << "Enter transferFromAccount: ";
    cin >> transferFromAccount;
    cin.ignore(10000, '\n');

    cout << "Enter transferToAccount: ";
    cin >> transferToAccount;
    cin.ignore(10000, '\n');

    if (transferFromAccount == transferToAccount) {
        cout << "Cannot transfer to the same account!" << endl;
        return;
    }

    int fromIndex = searchAccount(transferFromAccount);
    int toIndex = searchAccount(transferToAccount);

    if (fromIndex == -1 || toIndex == -1) {
        cout << "Account not found! Please check." << endl;
        return;
    }

    while(true) {
        cout << "Enter transfer amount: ";
        cin >> transferAmount;
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid amount input!" << endl;
            return;
        }

        if (transferAmount > 0 && transferAmount <= accounts[fromIndex].balance ) {
            break;
        }
        
        cout << "Invalid amount or insufficient balance!" << endl;
        }
           
    accounts[fromIndex].balance -= transferAmount;
    accounts[toIndex].balance += transferAmount;

    addTransaction(fromIndex, "transfer_out" , transferAmount);
    addTransaction(toIndex, "transfer_in", transferAmount);

    cout << "Transfer successful!" << endl;
}

// Display account information
void showAccount(int index) {
    cout << "-------------------- Account Information --------------------\n" << endl;

    string fullName = accounts[index].holderName;

    size_t pos = fullName.find(" ");

    string firstName;
    string lastName;

    if (pos != string::npos) {
        firstName = fullName.substr(0, pos);
        lastName = fullName.substr(pos + 1);
    }
    else {
        firstName = fullName;
        lastName = "";
    }
    string displayName = firstName + " " + lastName;

    cout << "First name:     " << firstName << endl;
    cout << "Last name:      " << lastName << endl;
    cout << "Full name:      " << displayName << endl;
    cout << "Account Number: " << accounts[index].accountNumber << endl;
    cout << "Balance:        " << "$" << accounts[index].balance << endl;
}

// Search + show account
void searchAndShowAccount() {
    int searchAndShowNum;

    cout << "Enter account number: ";
    cin >> searchAndShowNum;
    cin.ignore(10000, '\n');

    int index = searchAccount(searchAndShowNum);

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }
    showAccount(index);
}

// Add transaction records
void addTransaction(int index, string type, double amount) {
    if (accounts[index].transactionCount >= 100) {
        cout << "Transaction history full!" << endl;
        return;
    }
    int count = accounts[index].transactionCount;

    accounts[index].history[count].type = type;
    accounts[index].history[count].amount = amount;
    accounts[index].history[count].date = getCurrentDate();

    accounts[index].transactionCount++;
}

// Show transaction history
void showTransaction(int index) {
    cout << "\n-------------------- Transaction History --------------------\n" << endl;
    
    if (accounts[index].transactionCount == 0) {
        cout << "No transactions yet." << endl;
        return;
    }

    cout << left;
    cout << setw(15) << "Type" << setw(15) << "Amount($)" << setw(15) << "Date" << endl;
    for (int i = 0; i< accounts[index].transactionCount; i++) {
        cout << setw(15) << accounts[index].history[i].type << setw(15) << accounts[index].history[i].amount << setw(15) << accounts[index].history[i].date << endl;
    }
}

// Search + show transaction
void searchAndShowTransaction() {

    int showTransactionAccount;
    cout << "Enter account number you want to show transaction: ";
    cin >> showTransactionAccount;
    cin.ignore(10000, '\n');

    int index = searchAccount(showTransactionAccount);

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }

    showTransaction(index);
}

// Get system date automatically using system time library
string getCurrentDate() {

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

// Statement combines account information and transaction history
void showStatement() {

    int showStatementAccount;
    cout << "Enter account number for statement: ";
    cin >> showStatementAccount;
    cin.ignore(10000, '\n');

    int index = searchAccount(showStatementAccount);

    if (index == -1) {
        cout << "Account not found!" << endl;
        return;
    }
    cout << "\n==================== ACCOUNT STATEMENT ====================\n" << endl;
    
    showAccount(index);
    showTransaction(index);   
}






    



