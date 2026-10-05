void ExpenseManager::addExpense(double amount, const string &category, const string &description, const string &date, const string &receiptPath) {
    int id = Utility::generateUniqueId();
    Expense newExpense(id, amount, category, description, date, receiptPath);
    expenses.push_back(newExpense);
    cout << "Expense added successfully with ID: " << id << endl;
}