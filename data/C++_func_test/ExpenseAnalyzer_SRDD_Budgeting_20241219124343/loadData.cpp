void ExpenseManager::loadData() {
    ifstream file("expenses.txt");
    if (!file) {
        cout << "No previous data found. Starting fresh.\n";
        return;
    }
    string type, category;
    double amount;
    while (file >> type >> category >> amount) {
        if (type == "Expense") {
            expenses.push_back({category, amount});
        } else if (type == "Income") {
            incomes.push_back({category, amount});
        }
    }
    file.close();
}