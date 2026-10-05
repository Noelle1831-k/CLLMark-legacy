void FileManager::saveData(User &user, BudgetManager &budgetManager) {
    ofstream outFile("data.txt");
    if (outFile.is_open()) {
        outFile << user.getGoal() << endl;
        outFile << budgetManager.getRemainingBudget() << endl;
        outFile.close();
    } else {
        cout << "Error: Unable to save data." << endl;
    }
}