void RecommendationEngine::provideRecommendations(const User& user, const BudgetManager& manager) const {
    double income = user.getIncome();
    double expenses = user.getExpenses();
    double savings = income - expenses;
    cout << "\nPersonalized Recommendations:\n";
    if (savings < 0) {
        cout << "Warning: Your expenses exceed your income. Consider reducing unnecessary spending.\n";
    } else if (savings < 0.2 * income) {
        cout << "Tip: Try to save at least 20% of your income. Reduce discretionary expenses.\n";
    } else {
        cout << "Great job! Keep up the good financial habits.\n";
    }
}