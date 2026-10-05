void BudgetMonitor::loadData() {
    ifstream file("budget_data.txt");
    if (file.is_open()) {
        double limit;
        file >> limit;
        budgetManager.setMonthlyBudget(limit);
        file.close();
    }
}