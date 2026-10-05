bool User::login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid username or password." << endl;
        return false;
    }
}