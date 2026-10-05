void FileHandler::saveToFile(string filename, const BudgetPlanner &planner) {
    ofstream file(filename);
    if (!file) {
        cout << "Error saving to file!" << endl;
        return;
    }
    file << "Expenses:\n";
    vector<Expense> expenses = planner.getExpenses();
    for (unsigned int i = 0; i < expenses.size(); i++) {
        file << expenses[i].getCategory() << " " << expenses[i].getAmount() << "\n";
    }
    file << "Savings: " << planner.getSavings() << "\n";
    file.close();
    cout << "Data saved to " << filename << endl;
}