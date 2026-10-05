int main() {
    printf("Welcome to Expense Analyzer!\n");
    ExpenseManager expenseManager;
    BudgetManager budgetManager;
    ReportGenerator reportGenerator;
    RecommendationEngine recommendationEngine;
    initExpenseManager(&expenseManager);
    initBudgetManager(&budgetManager);
    initReportGenerator(&reportGenerator);
    initRecommendationEngine(&recommendationEngine);
    addExpense(&expenseManager, "Groceries", 150.0);
    setBudget(&budgetManager, "Groceries", 200.0);
    generateReport(&reportGenerator, &expenseManager);
    generateRecommendations(&recommendationEngine, &expenseManager, &budgetManager);
    return 0;
}