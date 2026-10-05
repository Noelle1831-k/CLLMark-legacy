void BudgetManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Failed to open file for loading.");
    }
    incomeSources.clear();
    expenseCategories.clear();
    file >> totalIncome >> totalExpenses >> budgetGoal;
    char type;
    string name;
    double amount;
    while (file >> type >> name >> amount) {
        if (type == 'I') {
            incomeSources[name] = amount;
        } else if (type == 'E') {
            expenseCategories[name] = amount;
        }
    }
    file.close();
}