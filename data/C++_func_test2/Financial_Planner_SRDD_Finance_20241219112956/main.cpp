int main() {
    User user;
    Budget budget;
    Goal goal;
    Investment investment;
    Visualization visualization;
    Education education;
    user.addIncome(5000);
    user.addExpense(2000);
    user.addSavings(1000);
    budget.setBudget(3000);
    goal.setGoal("Buy a car", 20000);
    investment.addInvestment("Stocks", 5000);
    visualization.generateIncomeChart(user.getIncome());
    visualization.generateExpenseChart(user.getExpenses());
    visualization.generateSavingsChart(user.getSavings());
    education.getTips();
    education.getResources();
    user.generateReport();
    return 0;
}