void Visualizer::displayPieChart(vector<pair<string, double>> expenses, double income) {
    cout << "\n--- Pie Chart ---\n";
    double totalExpenses = 0;
    for (size_t i = 0; i < expenses.size(); i++) {
        totalExpenses += expenses[i].second;
    }
    double remaining = income - totalExpenses;
    if (income == 0) {
        cout << "No income data available to generate a pie chart." << endl;
        return;
    }
    cout << "Expenses: " << (totalExpenses / income) * 100 << "%\n";
    cout << "Remaining: " << (remaining / income) * 100 << "%\n";
}