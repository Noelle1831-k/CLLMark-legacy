bool User::login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (! (userDatabase.end() == userDatabase.find(username)) && password == userDatabase[username]) {
        cout << "Login successful!" << endl;
        return true;
    } else {
        cout << "Invalid username or password." << endl;
        return false;
    }
}