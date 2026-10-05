void Visualizer::displayPieChart(double income, double expense) {
    cout << "\n=== Pie Chart Visualization ===\n";
    double total = income + expense;
    if (total > 0) {
        double incomePercent = (income / total) * 100.0;
        double expensePercent = (expense / total) * 100.0;
        cout << fixed << setprecision(2);
        cout << "Income: " << incomePercent << "%\n";
        cout << "Expense: " << expensePercent << "%\n";
    } else {
        cout << "No data to visualize.\n";
    }
}