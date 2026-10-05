void BudgetOptimizer::generateRecommendations() {
    cout << "Analyzing your expenses to generate recommendations..." << endl;
    if (expenses.empty()) {
        cout << "No expenses to analyze. Please track expenses first." << endl;
        return;
    }
    for (size_t i = 0; i < expenses.size(); i++) {
        if (expenses[i].second > totalExpenses * 0.2) {
            cout << "Consider reducing spending in category: " << expenses[i].first << endl;
        }
    }
}