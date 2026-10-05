void FinanceTracker::viewSummary() const {
    double totalIncome = 0, totalExpenses = 0;
    for (int i = 0; i < transactions.size(); i++) {
        if (transactions[i].getType() == 'i') totalIncome += transactions[i].getAmount();
        else totalExpenses += transactions[i].getAmount();
    }
    cout << "Total Income: " << totalIncome << "\n";
    cout << "Total Expenses: " << totalExpenses << "\n";
    cout << "Net Balance: " << (totalIncome - totalExpenses) << "\n";
}