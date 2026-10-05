void Budget::getRemainingBudget() const {
    double totalExpenses = 0;
    for (const auto &expense : expenses) {
        totalExpenses += expense.second;
    }
    cout << "Remaining Budget: $" << (totalBudget - totalExpenses) << endl;
}