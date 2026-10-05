string PasswordManager::retrievePassword(const string& account) {
    if (passwordStore.find(account) != passwordStore.end()) {
        return passwordStore[account];
    }
    return "";
}