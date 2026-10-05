void PasswordManager::retrievePassword(const string &account) {
    if (passwordVault.find(account) != passwordVault.end()) {
        cout << "Password for " << account << ": " << passwordVault[account] << "\n";
    } else {
        cout << "No password stored for account: " << account << "\n";
    }
}