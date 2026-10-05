void showMenu() {
        int choice;
        do {
            cout << "\n--- Main Menu ---\n";
            cout << "1. Set User Details\n";
            cout << "2. Add Expense\n";
            cout << "3. View Expense Breakdown\n";
            cout << "4. Analyze Budget\n";
            cout << "5. Save and Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            processInput(choice);
        } while (choice != 5);
    }