void User::registerUser() {
    string username, password;
    cout << "Register a new account." << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (userDatabase.find(username) == userDatabase.end()) {
        userDatabase[username] = password;
        saveUserData();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Username already exists. Try a different username." << endl;
    }
}