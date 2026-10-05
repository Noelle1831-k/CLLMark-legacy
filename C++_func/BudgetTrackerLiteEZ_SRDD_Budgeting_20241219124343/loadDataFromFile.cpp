void BudgetManager::loadDataFromFile(const string &filename) {
    ifstream file(filename);
    if (file) {
        file >> budgetGoal;
        size_t incomeCount, expenseCount;
        file >> incomeCount;
        incomes.clear();
        for (size_t i = 0; i < incomeCount; ++i) {
            double amount;
            string description;
            file >> amount;
            file.ignore();
            getline(file, description);
            incomes.emplace_back(amount, description);
        }
        file >> expenseCount;
        expenses.clear();
        for (size_t i = 0; i < expenseCount; ++i) {
            double amount;
            string description;
            file >> amount;
            file.ignore();
            getline(file, description);
            expenses.emplace_back(amount, description);
        }
        file.close();
        cout << "Data loaded successfully!\n";
    } else {
        cout << "Error loading data from file.\n";
    }
}