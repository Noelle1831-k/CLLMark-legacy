void ExpenseManager::listExpenses() const {
    for (int i = 0; i < expenses.size(); i++) {
        cout << i << ": " << expenses[i].getDetails() << endl;
    }
}