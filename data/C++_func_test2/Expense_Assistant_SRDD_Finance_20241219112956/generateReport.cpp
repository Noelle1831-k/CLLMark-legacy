void Visualization::generateReport(const vector<Expense>& expenses) {
    cout << "Generating report..." << endl;
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << "Expense: " << expenses[i].getAmount() << " in " << expenses[i].getCategory() << " on " << expenses[i].getDate() << endl;
    }
}