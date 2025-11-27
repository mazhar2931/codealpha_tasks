#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;
class Transaction {
public:
    string type;
    double amount;
    string timeStamp;

    Transaction(string t, double a) {
        type = t;
        amount = a;
        time_t now = time(0);
        timeStamp = ctime(&now);
        timeStamp.pop_back();
    }

    void showTransaction() {
        cout << type << "  |  Amount: " << amount
             << "  |  Time: " << timeStamp << endl;
    }
};
class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account(int accNo) {
        accountNumber = accNo;
        balance = 0.0;
    }

    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }
    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful!\n";
	}
    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
            return false;
        }
        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrawal successful!\n";
        return true;
    }
    bool transferOut(double amount, int toAcc) {
        if (amount > balance) {
            cout << "Insufficient balance for transfer!\n";
            return false;
        }
        balance -= amount;
        history.push_back(Transaction("Transfer to " + to_string(toAcc), amount));
        return true;
    }
    void transferIn(double amount, int fromAcc) {
        balance += amount;
        history.push_back(Transaction("Transfer from " + to_string(fromAcc), amount));
    }
    void showDetails() {
        cout << "\n--- Account Info ---\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    void showHistory() {
        cout << "\n--- Transaction History ---\n";
        if (history.empty()) {
            cout << "No transactions yet.\n";
        } else {
            for (auto &t : history) {
                t.showTransaction();
            }
        }
    }
};
class Customer {
public:
    string name;
    int customerID;
    Account account;

    Customer(string n, int id, int accNo) : account(accNo) {
        name = n;
        customerID = id;
    }

    void showCustomerInfo() {
        cout << "\n=== Customer Info ===\n";
        cout << "Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        account.showDetails();
    }
};
int main() {
    Customer c("Ali Khan", 101, 5001);

    int choice;
    double amount;
    int targetAcc;

    while (true) {
        cout << "\n===== BANKING SYSTEM MENU =====\n";
        cout << "1. View Customer & Account Info\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            c.showCustomerInfo();
            break;

        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            c.account.deposit(amount);
            break;

        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            c.account.withdraw(amount);
            break;

        case 4:
            cout << "Enter target account number: ";
            cin >> targetAcc;
            cout << "Enter amount to transfer: ";
            cin >> amount;

            if (c.account.transferOut(amount, targetAcc)) {
                cout << "Transferred to " << targetAcc << " successfully.\n";
            }
            break;

        case 5:
            c.account.showHistory();
            break;

        case 6:
            cout << "Exiting system...\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
