void FileHandler::saveToFile(string filename, BudgetManager &manager) {
    ofstream file(filename);
    if (file.is_open()) {
        file << manager.getSavings() << "\n";
        file << manager.getSavingsGoal() << "\n";
        for (auto &expense : manager.getExpenses()) {
            file << expense.first << " " << expense.second << "\n";
        }
        file.close();
        cout << "Budget saved successfully to " << filename << ".\n";
    } else {
        cout << "Error: Unable to open file for saving.\n";
    }
}