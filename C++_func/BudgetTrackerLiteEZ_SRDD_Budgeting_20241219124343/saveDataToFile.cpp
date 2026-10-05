void BudgetManager::saveDataToFile(const string &filename) {
    ofstream file(filename);
    if (file) {
        file << budgetGoal << "\n";
        file << incomes.size() << "\n";
        for (const auto &income : incomes) {
            file << income.getAmount() << "\n" << income.getDescription() << "\n";
        }
        file << expenses.size() << "\n";
        for (const auto &expense : expenses) {
            file << expense.getAmount() << "\n" << expense.getDescription() << "\n";
        }
        file.close();
        cout << "Data saved successfully!\n";
    } else {
        cout << "Error saving data to file.\n";
    }
}