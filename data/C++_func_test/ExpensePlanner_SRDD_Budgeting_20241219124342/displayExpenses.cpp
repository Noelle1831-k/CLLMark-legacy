void ExpenseManager::displayExpenses() const {
    for (const auto& expense : expenses) {
        cout << "ID: " << expense.getID() << ", Amount: " << expense.getAmount()
             << ", Category: " << expense.getCategory() << ", Date: " << expense.getDate()
             << ", Description: " << expense.getDescription() << endl;
    }
}