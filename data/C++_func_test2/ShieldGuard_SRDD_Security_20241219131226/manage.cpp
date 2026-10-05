void PasswordManager::manage() {
    int choice;
    string account, password;
    while (true) {
        cout << "\n--- Password Manager ---\n";
        cout << "1. Add Password\n";
        cout << "2. Retrieve Password\n";
        cout << "3. Display Password History\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter account: ";
            cin >> account;
            cout << "Enter password: ";
            cin >> password;
            addPassword(account, password);
            break;
        case 2:
            cout << "Enter account: ";
            cin >> account;
            retrievePassword(account);
            break;
        case 3:
            displayPasswordHistory();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}