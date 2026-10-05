void Dashboard::handleUserInput(int choice) {
    switch (choice) {
        case 1: {
            string date, description;
            double amount;
            cout << "Enter date (YYYY-MM-DD): ";
            cin >> date;
            cout << "Enter amount: ";
            cin >> amount;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter description: ";
            getline(cin, description);
            cashFlow.addTransaction(Transaction(date, amount, description));
            break;
        }
        case 2: {
            int index;
            cout << "Enter transaction index to remove: ";
            cin >> index;
            cashFlow.removeTransaction(index - 1);
            break;
        }
        case 3:
            cashFlow.displayAllTransactions();
            break;
        case 4:
            cout << "Net Cash Flow: " << cashFlow.calculateNetCashFlow() << endl;
            break;
        case 5:
            cout << "Exiting application. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
}