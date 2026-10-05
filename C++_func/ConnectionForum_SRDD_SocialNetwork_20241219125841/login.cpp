void User::login() {
    cout << "Logging in user..." << endl;
    string inputUsername, inputPassword;
    cout << "Enter username: ";
    cin >> inputUsername;
    cout << "Enter password: ";
    cin >> inputPassword;
    if (inputUsername == username && inputPassword == password) {
        cout << "User logged in successfully!" << endl;
    } else {
        cout << "Invalid credentials!" << endl;
    }
}