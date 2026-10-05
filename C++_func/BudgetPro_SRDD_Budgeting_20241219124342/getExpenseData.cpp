vector<double> BudgetManager::getExpenseData() const {
    vector<double> data;
    for (const auto& transaction : transactions) {
        data.push_back(transaction.getAmount());
    }
    return data;
}