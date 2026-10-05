void BudgetManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        throw runtime_error("Failed to open file for saving.");
    }
    file << totalIncome << " " << totalExpenses << " " << budgetGoal << endl;
    for (const auto& entry : incomeSources) {
        file << "I " << entry.first << " " << entry.second << endl;
    }
    for (const auto& entry : expenseCategories) {
        file << "E " << entry.first << " " << entry.second << endl;
    }
    file.close();
}