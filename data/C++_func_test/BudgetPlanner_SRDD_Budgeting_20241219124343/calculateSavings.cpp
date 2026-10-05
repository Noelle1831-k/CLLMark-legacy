void BudgetPlanner::calculateSavings(double income) {
    double totalExpenses = 0;
    for (unsigned int i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses[i].getAmount();
    }
    savings = income - totalExpenses;
    cout << "Your calculated savings are: $" << savings << endl;
}