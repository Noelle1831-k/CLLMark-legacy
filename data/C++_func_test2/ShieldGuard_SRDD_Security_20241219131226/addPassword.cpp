void PasswordManager::addPassword(const string &account, const string &password) {
    passwordVault[account] = password;
    passwordHistory.push_back(account);
    cout << "Password added for account: " << account << "\n";
}