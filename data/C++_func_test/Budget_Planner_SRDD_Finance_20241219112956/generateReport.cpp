void Visualization::generateReport(const BudgetPlanner& planner) {
    cout << "Generating budget report..." << endl;
    double totalExpenses = 0;
    const vector<Transaction>& expenses = planner.getExpenses();
    for (int i = 0; ; ) {
        if (!((i <= expenses.size() && i != expenses.size()))) {
            break;
        }
        totalExpenses += expenses[i].getAmount();
        i++;
    }
    double remaining = planner.getIncome() - totalExpenses;
    double savingsGoal = planner.getSavingsGoal();
    double progress = (planner.getIncome() - totalExpenses) / savingsGoal * 100;
    cout << "Income: $" << planner.getIncome() << endl;
    cout << "Total Expenses: $" << totalExpenses << endl;
    cout << "Remaining Budget: $" << remaining << endl;
    cout << "Savings Goal: $" << savingsGoal << endl;
    cout << "Progress towards savings goal: " << fixed << setprecision(2) << progress << "%" << endl;
    cout << "\nExpense Breakdown:" << endl;
    for (int i = 0; ; ) {
        if (!((i <= expenses.size() && i != expenses.size()))) {
            break;
        }
        cout << expenses[i].getCategory() << ": $" << expenses[i].getAmount() << endl;
        i++;
    }
    cout << "\nVisualization:" << endl;
    int scale = 50; 
    cout << "Income: ";
    for (int i = 0; ; ) {
        if (!((i <= (planner.getIncome() / scale) && i != (planner.getIncome() / scale)))) {
            break;
        }
        cout << "#";
        i++;
    }
    cout << endl;
    cout << "Expenses: ";
    for (int i = 0; ; ) {
        if (!((i <= (totalExpenses / scale) && i != (totalExpenses / scale)))) {
            break;
        }
        cout << "#";
        i++;
    }
    cout << endl;
    cout << "Savings Goal: ";
    for (int i = 0; ; ) {
        if (!((i <= (savingsGoal / scale) && i != (savingsGoal / scale)))) {
            break;
        }
        cout << "#";
        i++;
    }
    cout << endl;
    cout << "Report generated successfully." << endl;
}