void ExpensePlanner::suggestSavings() {
    calculateTotalExpenses();
    savingsPlan.calculateSavings(income, totalExpenses, targetSavings);
    cout << "Suggested savings: " << savingsPlan.getSuggestedSavings() << endl;
}