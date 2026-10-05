void ExpenseManager::viewExpenses() {
    if (expenses.empty()) {
        cout << "No expenses recorded yet!" << endl;
        return;
    }
    cout << "\n===== All Expenses =====" << endl;
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". " << expenses[i].getDetails() << endl;
    }
}