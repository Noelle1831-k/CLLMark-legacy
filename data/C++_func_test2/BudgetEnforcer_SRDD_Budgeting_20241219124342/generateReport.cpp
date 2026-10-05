void BudgetManager::generateReport() {
    cout << "Expense Report:\n";
    for (map<string, double>::iterator it = expenses.begin(); it != expenses.end(); ++it) {
        cout << it->first << ": $" << it->second << endl;
    }
}