#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool usernameExists(const string& username) {
    ifstream file("database.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            return true;
        }
    }
    return false;
}
void registerUser() {
    string username, password;

    cout << "\n---- USER REGISTRATION ----\n";
    cout << "Enter username: ";
    cin >> username;
    if (usernameExists(username)) {
        cout << "Error: Username already exists. Try another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;
    if (username.empty() || password.empty()) {
        cout << "Error: Username or password cannot be empty.\n";
        return;
	}
    ofstream file("database.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration Successful!\n";
}
void loginUser() {
    string username, password;

    cout << "\n---- USER LOGIN ----\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database.txt");
    string user, pass;

    bool found = false;

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login Successful! Welcome " << username << "!\n";
    } else {
        cout << "Error: Incorrect username or password.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n==== MENU ====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: 
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
