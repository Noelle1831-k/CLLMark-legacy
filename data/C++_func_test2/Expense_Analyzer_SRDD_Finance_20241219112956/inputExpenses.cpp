void ExpenseAnalyzerApp::inputExpenses() {
    char choice;
    do {
        double amount;
        string category, description;
        cout << "Enter expense amount: ";
        cin >> amount;
        cout << "Enter expense category: ";
        cin >> category;
        cout << "Enter expense description: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, description);
        Expense expense(amount, category, description);
        expenseManager.addExpense(expense);
        cout << "Add another expense? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}