int main() {
    BudgetOptimizer optimizer;
    optimizer.loadUserData();
    optimizer.analyzeIncomeExpenses();
    optimizer.generateRecommendations();
    optimizer.displayRecommendations();
    return 0;
}