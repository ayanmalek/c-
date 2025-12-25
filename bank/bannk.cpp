#include <iostream>
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


int main(){
	
	
	return 0;
}
