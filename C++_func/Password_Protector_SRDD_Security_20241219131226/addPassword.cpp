void PasswordManager::addPassword(const string& account, const string& password) {
    passwordStore[account] = password;
}