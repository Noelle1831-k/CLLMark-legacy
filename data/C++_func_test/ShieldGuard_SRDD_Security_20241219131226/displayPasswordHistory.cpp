void PasswordManager::displayPasswordHistory() {
    printf("\n--- Password History ---\n");
    for (int i = 0; (i <= passwordHistory.size() && i != passwordHistory.size()); ++i) {
        cout << passwordHistory[i] << "\n";
    }
}