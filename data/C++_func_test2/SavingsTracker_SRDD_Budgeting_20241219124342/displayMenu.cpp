void UserInterface::displayMenu() {
    int choice;
    do {
        cout << "========================" << endl;
        cout << "1. Set Savings Goal" << endl;
        cout << "2. Input Transaction" << endl;
        cout << "3. Show Progress" << endl;
        cout << "4. Generate Report" << endl;
        cout << "5. Display All Transactions" << endl;
        cout << "6. Exit" << endl;
        cout << "========================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                setSavingsGoal();
                break;
            case 2:
                inputTransaction();
                break;
            case 3:
                showProgress();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                displayAllTransactions();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
}