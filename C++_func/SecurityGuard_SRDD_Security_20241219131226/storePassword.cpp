void PasswordManager::storePassword(const string &site, const string &username, const string &password) {
    passwords[site] = encryptPassword(password);
    cout << "Password stored for " << site << " (User: " << username << ")" << endl;
}