void EventManager::manageBudget() {
    int choice;
    cout << "1. Set Budget\n2. Add Expense\n3. View Remaining Budget\nEnter choice: ";
    cin >> choice;
    if (choice == 1) {
        double amount;
        cout << "Enter Total Budget: ";
        cin >> amount;
        budget.setBudget(amount);
        cout << "Budget set successfully!" << endl;
    } else if (choice == 2) {
        string expenseName;
        double amount;
        cout << "Enter Expense Name: ";
        cin.ignore();
        getline(cin, expenseName);
        cout << "Enter Expense Amount: ";
        cin >> amount;
        budget.addExpense(expenseName, amount);
    } else if (choice == 3) {
        budget.getRemainingBudget();
    } else {
        cout << "Invalid Choice!" << endl;
    }
}