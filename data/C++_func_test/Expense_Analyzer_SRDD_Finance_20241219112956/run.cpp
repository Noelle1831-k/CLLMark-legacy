void ExpenseAnalyzerApp::run() {
    char choice;
    do {
        cout << "1. Input Expenses" << endl;
        cout << "2. Set Budgets" << endl;
        cout << "3. Display Reports" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                inputExpenses();
                break;
            case '2':
                setBudgets();
                break;
            case '3':
                displayReports();
                break;
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '4');
}