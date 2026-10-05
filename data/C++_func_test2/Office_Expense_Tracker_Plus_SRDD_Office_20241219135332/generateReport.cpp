void ReportGenerator::generateReport(const ExpenseManager& expenseManager, const Budget& budget) {
    vector<Expense> expenses = expenseManager.getExpenses();
    for (unsigned int i = 0; i < expenses.size(); i++) {
        cout << "Expense: " << expenses[i].getCategory() << ", Amount: " << expenses[i].getAmount() << ", Date: " << expenses[i].getDate() << endl;
    }
}