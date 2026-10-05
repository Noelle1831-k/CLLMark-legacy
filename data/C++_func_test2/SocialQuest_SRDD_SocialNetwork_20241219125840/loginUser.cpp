void loginUser(string username) {
        if (users.find(username) != users.end()) {
            cout << "User logged in: " << username << endl;
        } else {
            cout << "User not found: " << username << endl;
        }
    }