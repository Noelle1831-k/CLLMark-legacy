void BudgetOptimizer::displayDashboard() {
    cout << "========== Dashboard ==========" << endl;
    cout << "Category\tAmount" << endl;
    cout << "-------------------------------" << endl;
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << expenses[i].first << "\t\t" << Utility::formatCurrency(expenses[i].second) << endl;
    }
    cout << "-------------------------------" << endl;
    cout << "Total Expenses: " << Utility::formatCurrency(totalExpenses) << endl;
    cout << "================================" << endl;
}