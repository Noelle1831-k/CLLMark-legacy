void Reminder::checkReminders(const Budget& budget, const ExpenseManager& expenseManager) {
    cout << "Checking reminders..." << endl;
    vector<Expense> expenses = expenseManager.getExpenses();
    for (size_t i = 0; i < expenses.size(); ++i) {
        string category = expenses[i].getCategory();
        double total = 0.0;
        for (size_t j = 0; j < expenses.size(); ++j) {
            if (expenses[j].getCategory() == category) {
                total += expenses[j].getAmount();
            }
        }
        if (total > budget.getLimit(category)) {
            cout << "Reminder: You have exceeded your budget for " << category << "." << endl;
        }
    }
}