void RecommendationEngine::generateRecommendations(const ExpenseManager& expenseManager) const {
    double totalExpenses = expenseManager.getTotalExpenses();
    cout << "Personalized Savings Recommendations:" << endl;
    if (totalExpenses > 1000) {
        cout << "1. Your expenses are high! Try to categorize and reduce unnecessary spending." << endl;
        cout << "2. Consider saving at least 10% of your income." << endl;
    } else if (totalExpenses > 500) {
        cout << "1. Keep track of your expenses. Aim for consistent savings." << endl;
        cout << "2. You can save more by planning your budget better." << endl;
    } else {
        cout << "1. Excellent job! You're managing your finances well. Keep it up!" << endl;
        cout << "2. Explore investment opportunities to grow your savings." << endl;
    }
}