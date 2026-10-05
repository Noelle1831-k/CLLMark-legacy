bool RemoteAccessManager::authenticateUser(const string &username, const string &password) {
    cout << "Authenticating user: " << username << endl;
    if (credentials.find(username) != credentials.end() &&
        credentials[username] == hashPassword(password)) {
        cout << "Authentication successful." << endl;
        return true;
    } else {
        cout << "Authentication failed." << endl;
        return false;
    }
}