int main(int argc, char *argv[]) {
    BudgetPlanner planner;
    planner.setIncome(5000);
    planner.addExpense(200, "Groceries");
    planner.addExpense(150, "Utilities");
    planner.setSavingsGoal(1000);
    planner.calculateRecommendations();
    planner.trackProgress();
    Visualization viz;
    viz.generateReport(planner);
    return 0;
}