void PasswordManager::removePassword(const string& account) {
    passwordStore.erase(account);
}