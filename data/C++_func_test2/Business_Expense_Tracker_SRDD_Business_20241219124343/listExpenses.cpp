void ExpenseManager::listExpenses() const {
    cout << "Listing all expenses:\n";
    for (const auto &expense : expenses) {
        cout << "ID: " << expense.getId() << ", Amount: " << fixed << setprecision(2) << expense.getAmount()
             << ", Category: " << expense.getCategory() << ", Description: " << expense.getDescription()
             << ", Date: " << expense.getDate() << ", Receipt Path: " << expense.getReceiptPath() << endl;
    }
}