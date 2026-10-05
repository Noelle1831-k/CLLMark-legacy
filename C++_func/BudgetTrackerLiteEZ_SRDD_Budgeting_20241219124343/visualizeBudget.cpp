void BudgetManager::visualizeBudget() {
    Visualizer viz;
    viz.displayBarChart(incomes);
    viz.displayPieChart(incomes.size(), expenses.size());
}