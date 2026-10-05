void FileManager::loadData(User &user, BudgetManager &budgetManager) {
    ifstream inFile("data.txt");
    if (inFile.is_open()) {
        double goal, remainingBudget;
        inFile >> goal >> remainingBudget;
        user.setGoal(goal);
        while (remainingBudget < budgetManager.getRemainingBudget()) {
            budgetManager.addExpense(1.0, "Loaded");
        }
        inFile.close();
    } else {
        cout << "No previous data found. Starting fresh." << endl;
    }
}