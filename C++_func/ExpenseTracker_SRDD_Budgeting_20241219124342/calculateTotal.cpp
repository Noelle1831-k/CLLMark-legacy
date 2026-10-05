void ExpenseManager::calculateTotal() const {
    double total = 0.0;
    for (int i = 0; i < expenses.size(); i++) {
        total += expenses[i].getAmount();
    }
    cout << "Total Expenses: " << total << endl;
}