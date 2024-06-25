#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to load users from the file
void loadUsers(unordered_map<string, string>& users) {
    ifstream inputFile("users.txt");
    if (inputFile.is_open()) {
        string username, password;
        while (inputFile >> username >> password) {
            users[username] = password;
        }
        inputFile.close();
    }
}

// Function to save users to the file
void saveUsers(const unordered_map<string, string>& users) {
    ofstream outputFile("users.txt");
    if (outputFile.is_open()) {
        for (const auto& user : users) {
            outputFile << user.first << " " << user.second << endl;
        }
        outputFile.close();
    }
}

// Function to register a new user
void registerUser(unordered_map<string, string>& users) {
    string username, password;
    cout << "Enter a new username: ";
    cin >> username;

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please try again." << endl;
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    users[username] = password;
    saveUsers(users);

    cout << "Registration successful!" << endl;
}

// Function to log in an existing user
void loginUser(const unordered_map<string, string>& users) {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;

    if (users.find(username) == users.end()) {
        cout << "Username not found. Please register first." << endl;
        return;
    }

    cout << "Enter your password: ";
    cin >> password;

    if (users.at(username) == password) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Incorrect password. Please try again." << endl;
    }
}

int main() {
    unordered_map<string, string> users;
    loadUsers(users);

    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(users);
                break;
            case 2:
                loginUser(users);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
