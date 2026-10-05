void UserInterface::collectBudgetData() {
    double income, expense;
    string category;
    cout << "Enter your income: ";
    validateInput(income);
    budgetManager.addIncome(income);
    cout << "Enter your expenses (enter -1 to stop):\n";
    while (true) {
        cout << "Amount: ";
        validateInput(expense);
        if (expense == -1) break;
        cout << "Category: ";
        cin >> category;
        budgetManager.addExpense(expense, category);
    }
}