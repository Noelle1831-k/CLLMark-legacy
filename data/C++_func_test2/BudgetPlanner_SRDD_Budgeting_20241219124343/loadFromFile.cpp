void FileHandler::loadFromFile(string filename, BudgetPlanner &planner) {
    ifstream file(filename);
    if (!file) {
        cout << "Error loading file!" << endl;
        return;
    }
    string line, category;
    double amount, savings;
    planner.clearExpenses();
    while (getline(file, line)) {
        if (line == "Expenses:") continue;
        if (line.find("Savings:") == 0) {
            savings = stod(line.substr(8));
            planner.setSavings(savings);
        } else {
            istringstream iss(line);
            iss >> category >> amount;
            Expense expense;
            expense.setExpenseDetails(category, amount);
            planner.addExpense(expense);
        }
    }
    file.close();
    cout << "Data loaded from " << filename << endl;
}