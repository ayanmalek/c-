#include <iostream>
#include <string>
using namespace std;

// Base class for all bank accounts
class BankAccount {
private:
    int accNumber;              // Account number
    string holderName;          // Account holder name
    double accBalance;          // Current balance

public:
    // Constructor
    BankAccount(int number, const string& name, double balance)
        : accNumber(number), holderName(name), accBalance(balance) {}

    // Virtual destructor
    virtual ~BankAccount() {}

    // Deposit money
    void deposit(double amount) {
        accBalance += amount;
        cout << "Deposited " << amount 
             << ". New Balance: " << accBalance << endl;
    }

    // Withdraw money
    virtual bool withdraw(double amount) {
        if (amount <= accBalance) {
            accBalance -= amount;
            cout << "Withdrew " << amount 
                 << ". New Balance: " << accBalance << endl;
            return true;
        } else {
            cout << "Insufficient balance!" << endl;
            return false;
        }
    }

    // Get current balance
    double getBalance() const {
        return accBalance;
    }

    // Display basic account details
    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accNumber
             << ", Holder Name: " << holderName
             << ", Balance: " << accBalance;
    }

    // Interest calculation (base class)
    virtual double calculateInterest() const {
        return 0.0;   // No interest for base account
    }
};

// Savings Account class
class SavingsAccount : public BankAccount {
private:
    double interestRate;   // Interest rate percentage

public:
    SavingsAccount(int number, const string& name, double balance, double rate)
        : BankAccount(number, name, balance), interestRate(rate) {}

    // Calculate savings interest
    double calculateInterest() const override {
        return getBalance() * interestRate / 100;
    }

    // Display savings account info
    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << ", Interest Rate: " << interestRate << "%" << endl;
    }
};

// Checking Account class
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;   // Allowed overdraft limit

public:
    CheckingAccount(int number, const string& name, double balance, double limit)
        : BankAccount(number, name, balance), overdraftLimit(limit) {}

    // Withdraw with overdraft facility
    bool withdraw(double amount) override {
        if (getBalance() + overdraftLimit >= amount) {
            double newBalance = getBalance() - amount;
            cout << "Withdrew " << amount 
                 << ". New Balance: " << newBalance << endl;
            return true;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
            return false;
        }
    }

    // Display checking account info
    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << ", Overdraft Limit: " << overdraftLimit << endl;
    }
};

// Fixed Deposit Account class
class FixedDepositAccount : public BankAccount {
private:
    int depositMonths;      // FD duration in months
    double fdInterestRate;  // FD interest rate

public:
    FixedDepositAccount(int number, const string& name, double balance,
                        int months, double rate)
        : BankAccount(number, name, balance),
          depositMonths(months), fdInterestRate(rate) {}

    // Calculate fixed deposit interest
    double calculateInterest() const override {
        return getBalance() * fdInterestRate * depositMonths / (100 * 12);
    }

    // Display FD account info
    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << ", Term: " << depositMonths << " months"
             << ", Interest Rate: " << fdInterestRate << "%" << endl;
    }
};

// Menu function
void showMenu() {
    cout << "\n--- Bank Account Management System ---\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Display Account Info\n";
    cout << "5. Calculate Interest\n";
    cout << "6. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    BankAccount* accountList[10];   // Store account pointers
    int totalAccounts = 0;
    int userChoice;

    do {
        showMenu();
        cin >> userChoice;

        switch (userChoice) {

        case 1: {
            cout << "Account Types:\n1. Savings\n2. Checking\n3. Fixed Deposit\n";
            int accountType;
            cout << "Enter type: ";
            cin >> accountType;

            int accNumber, months;
            string name;
            double balance, rate, limit;

//            BankAccount* newAccount = nullptr;

            cout << "Enter Account Number, Name, Initial Balance: ";
            cin >> accNumber >> name >> balance;

            if (accountType == 1) {
                cout << "Enter Interest Rate: ";
                cin >> rate;
//                newAccount = new SavingsAccount(accNumber, name, balance, rate);
            }
            else if (accountType == 2) {
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
//                newAccount = new CheckingAccount(accNumber, name, balance, limit);
            }
            else if (accountType == 3) {
                cout << "Enter Term (months) and Interest Rate: ";
                cin >> months >> rate;
//                newAccount = new FixedDepositAccount(accNumber, name, balance, months, rate);
            }

            if (newAccount && totalAccounts < 10)
                accountList[totalAccounts++] = newAccount;
            else
                cout << "Account creation failed!\n";

            break;
        }

        case 2: {
            int index;
            double amount;
            cout << "Enter account index and deposit amount: ";
            cin >> index >> amount;

            if (index >= 0 && index < totalAccounts)
                accountList[index]->deposit(amount);
            else
                cout << "Invalid account index!\n";
            break;
        }

        case 3: {
            int index;
            double amount;
            cout << "Enter account index and withdraw amount: ";
            cin >> index >> amount;

            if (index >= 0 && index < totalAccounts)
                accountList[index]->withdraw(amount);
            else
                cout << "Invalid account index!\n";
            break;
        }

        case 4: {
            int index;
            cout << "Enter account index: ";
            cin >> index;

            if (index >= 0 && index < totalAccounts)
                accountList[index]->displayAccountInfo();
            else
                cout << "Invalid account index!\n";
            break;
        }

        case 5: {
            int index;
            cout << "Enter account index: ";
            cin >> index;

            if (index >= 0 && index < totalAccounts)
                cout << "Interest: " 
                     << accountList[index]->calculateInterest() << endl;
            else
                cout << "Invalid account index!\n";
            break;
        }

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (userChoice != 6);

    // Free allocated memory
    for (int i = 0; i < totalAccounts; i++)
        delete accountList[i];

    return 0;
}

