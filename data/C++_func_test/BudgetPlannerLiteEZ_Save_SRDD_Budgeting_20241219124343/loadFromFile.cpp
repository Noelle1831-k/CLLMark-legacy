void FileHandler::loadFromFile(string filename, BudgetManager &manager) {
    ifstream file(filename);
    if (file.is_open()) {
        double savings, goal;
        file >> savings >> goal;
        manager.addIncome(savings); 
        manager.setSavingsGoal(goal);
        string category;
        double amount;
        while (file >> category >> amount) {
            manager.addExpense(amount, category);
        }
        file.close();
        cout << "Budget loaded successfully from " << filename << ".\n";
    } else {
        cout << "Error: Unable to open file for loading.\n";
    }
}