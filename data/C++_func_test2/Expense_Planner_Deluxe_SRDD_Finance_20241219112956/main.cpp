int main() {
    ExpensePlanner planner;
    FinancialGoal goal(5000); 
    Notification notification;
    double income;
    cout << "Enter your monthly income: ";
    cin >> income;
    planner.setIncome(income);
    int categoryCount;
    cout << "Enter number of expense categories: ";
    cin >> categoryCount;
    for (int i = 0; i < categoryCount; ++i) {
        string categoryName;
        double categoryBudget;
        cout << "Enter expense category name: ";
        cin >> categoryName;
        cout << "Enter budget for " << categoryName << ": ";
        cin >> categoryBudget;
        planner.addExpenseCategory(ExpenseCategory(categoryName, categoryBudget));
    }
    int billCount;
    cout << "Enter number of bills to track: ";
    cin >> billCount;
    for (int i = 0; i < billCount; ++i) {
        string billName;
        double billAmount;
        int dueDay;
        cout << "Enter bill name: ";
        cin >> billName;
        cout << "Enter bill amount: ";
        cin >> billAmount;
        cout << "Enter due day of the month: ";
        cin >> dueDay;
        planner.addBill(Bill(billName, billAmount, dueDay));
    }
    planner.displaySummary();
    notification.checkExpenses(planner, goal);
    return 0;
}