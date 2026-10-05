void Transaction::addTransaction(Budget &budget) {
    string type;
    double amount;
    cout << "Enter transaction type (income/expense): ";
    cin >> type;
    cout << "Enter transaction amount: ";
    cin >> amount;
    if (type == "income") {
        budget.addIncome(amount);
        transactions.push_back(make_pair(type, amount));
    } else if (type == "expense") {
        budget.addExpense(amount);
        transactions.push_back(make_pair(type, amount));
    } else {
        cout << "Invalid transaction type. Transaction not recorded.\n";
    }
}