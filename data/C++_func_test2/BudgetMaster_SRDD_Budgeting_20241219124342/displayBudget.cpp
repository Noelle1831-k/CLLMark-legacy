void Budget::displayBudget() const {
    cout << "\n=== Budget Overview ===" << endl;
    for (map<string, double>::const_iterator it = categoryLimits.begin(); it != categoryLimits.end(); ++it) {
        string category = it->first;
        double limit = it->second;
        double spent = currentSpending.at(category);
        cout << "Category: " << category << endl;
        cout << "Limit: $" << fixed << setprecision(2) << limit << endl;
        cout << "Spent: $" << fixed << setprecision(2) << spent << endl;
        cout << "Status: " << (checkBudgetStatus(category) ? "Within Budget" : "Over Budget") << endl;
        cout << "------------------------" << endl;
    }
}