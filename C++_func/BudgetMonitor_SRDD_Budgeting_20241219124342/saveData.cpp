void BudgetMonitor::saveData() {
    ofstream file("budget_data.txt");
    if (file.is_open()) {
        file << budgetManager.getMonthlyBudget() << endl;
        file.close();
    }
}