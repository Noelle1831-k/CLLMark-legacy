void Budget::checkBudget(double expense) const {
    if (totalExpenses + expense > budgetLimit) {
        cout << "Warning: Budget limit exceeded!\n";
    }
}