void Visualization::generateExpenseChart(vector<double> expenses) {
    cout << "Expense Chart:" << endl;
    for (double exp : expenses) {
        cout << exp << " ";
    }
    cout << endl;
}