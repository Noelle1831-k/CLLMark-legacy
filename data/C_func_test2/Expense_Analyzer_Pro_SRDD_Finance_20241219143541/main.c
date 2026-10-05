int main(int argc, char *argv[]) {
    ExpenseManager expenseManager;
    ReportGenerator reportGenerator;
    ForecastingEngine forecastingEngine;
    RecommendationEngine recommendationEngine;
    BudgetManager budgetManager;
    initExpenseManager(&expenseManager);
    initReportGenerator(&reportGenerator);
    initForecastingEngine(&forecastingEngine);
    initRecommendationEngine(&recommendationEngine);
    initBudgetManager(&budgetManager);
    addExpense(&expenseManager, "Groceries", 150.0);
    addExpense(&expenseManager, "Utilities", 75.0);
    categorizeExpense(&expenseManager, "Groceries", "Food");
    categorizeExpense(&expenseManager, "Utilities", "Bills");
    generateReport(&reportGenerator, &expenseManager);
    visualizeExpenses(&reportGenerator, &expenseManager);
    forecastExpenses(&forecastingEngine, &expenseManager);
    generateRecommendations(&recommendationEngine, &expenseManager);
    compareToBudget(&budgetManager, &expenseManager);
    return 0;
}