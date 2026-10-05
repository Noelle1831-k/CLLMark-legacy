void Dashboard::showMenu() {
    int choice;
    do {
        cout << "\n--- Cash Flow Manager ---\n";
        cout << "1. Add Transaction\n";
        cout << "2. Remove Transaction\n";
        cout << "3. Display All Transactions\n";
        cout << "4. Calculate Net Cash Flow\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        handleUserInput(choice);
    } while (choice != 5);
}