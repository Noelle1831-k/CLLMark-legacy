void PasswordManager::displayPasswordHistory() {
    cout << "\n--- Password History ---\n";
    for (int i = 0; i < passwordHistory.size(); i++) {
        cout << passwordHistory[i] << "\n";
    }
}