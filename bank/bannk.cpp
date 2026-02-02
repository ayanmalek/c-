#include<iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, const string& name, double bal)
        : accountNumber(accNum), accountHolderName(name), balance(bal) {}

    virtual ~BankAccount() {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New Balance: " << balance << endl;
    }

    virtual bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New Balance: " << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance!" << endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber
             << ", Holder: " << accountHolderName
             << ", Balance: " << balance;
    }

    virtual double calculateInterest() const {
        return 0.0; // Base class does not implement
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate; // percentage

public:
    SavingsAccount(int accNum, const string& name, double bal, double rate)
        : BankAccount(accNum, name, bal), interestRate(rate) {}

    double calculateInterest() const override {
        return getBalance() * interestRate / 100;
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << ", Savings Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNum, const string& name, double bal, double limit)
        : BankAccount(accNum, name, bal), overdraftLimit(limit) {}

    bool withdraw(double amount) override {
        if (getBalance() + overdraftLimit >= amount) {
            double updated = getBalance() - amount;
            cout << "Withdrew " << amount << ". New Balance: " << updated << endl;
            return true;
        } else {
            cout << "Exceeds overdraft limit!" << endl;
            return false;
        }
    }

    void checkOverdraft(double amount) const {
        if (getBalance() + overdraftLimit >= amount)
            cout << "Withdrawal permitted within overdraft limit.\n";
        else
            cout << "Withdrawal exceeds overdraft limit!\n";
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << ", Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
private:
    int term; // in months
    double interestRate;

public:
    FixedDepositAccount(int accNum, const string& name, double bal, int t, double rate)
        : BankAccount(accNum, name, bal), term(t), interestRate(rate) {}

    double calculateInterest() const override {
        // Simple fixed deposit interest calculation
        return getBalance() * interestRate * term / (100 * 12);
    }

    void displayAccountInfo() const override {
        BankAccount::displayAccountInfo();
        cout << ", Term: " << term << " months"
             << ", FD Interest Rate: " << interestRate << "%" << endl;
    }
};

void menu() {
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
    BankAccount* accounts[10];
    int accCount = 0;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Account Types:\n1. Savings\n2. Checking\n3. Fixed Deposit\n";
            int type;
            cout << "Enter type (1-3): ";
            cin >> type;

            int accNum, term;
            string name;
            double bal, rate, limit;
            BankAccount* acc =nullptr;

            cout << "Enter Account Number, Name, Initial Balance: ";
            cin >> accNum >> name >> bal;

            if (type == 1) {
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                acc = new SavingsAccount(accNum, name, bal, rate);
            } else if (type == 2) {
                cout << "Enter Overdraft Limit: ";
                cin >> limit;
                acc = new CheckingAccount(accNum, name, bal, limit);
            } else if (type == 3) {
                cout << "Enter Term (months) and Interest Rate (%): ";
                cin >> term >> rate;
                acc = new FixedDepositAccount(accNum, name, bal, term, rate);
            }
            if (acc && accCount < 10)
                accounts[accCount++] = acc;
            else
                cout << "Invalid type or max accounts reached!\n";
            break;
        }

        case 2: {
            int idx;
            double amt;
            cout << "Enter account index and amount to deposit: ";
            cin >> idx >> amt;
            if (idx >= 0 && idx < accCount)
                accounts[idx]->deposit(amt);
            else
                cout << "Invalid index!\n";
            break;
        }

        case 3: {
            int idx;
            double amt;
            cout << "Enter account index and amount to withdraw: ";
            cin >> idx >> amt;
            if (idx >= 0 && idx < accCount)
                accounts[idx]->withdraw(amt);
            else
                cout << "Invalid index!\n";
            break;
        }

        case 4: {
            int idx;
            cout << "Enter account index to display info: ";
            cin >> idx;
            if (idx >= 0 && idx < accCount)
                accounts[idx]->displayAccountInfo();
            else
                cout << "Invalid index!\n";
            break;
        }

        case 5: {
            int idx;
            cout << "Enter account index to calculate interest: ";
            cin >> idx;
            if (idx >= 0 && idx < accCount)
                cout << "Interest: " << accounts[idx]->calculateInterest() << endl;
            else
                cout << "Invalid index!\n";
            break;
        }

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    // Cleanup
    for (int i = 0; i < accCount; i++)
        delete accounts[i];

    return 0;
}


