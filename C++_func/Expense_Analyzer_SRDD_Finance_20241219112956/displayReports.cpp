void ExpenseAnalyzerApp::displayReports() {
    map<string, double> categoryTotals = expenseManager.calculateCategoryTotals();
    visualization.generatePieChart(categoryTotals);
    visualization.generateBarChart(categoryTotals, userBudget.getBudgets());
    expenseManager.compareWithBudget(userBudget);
}