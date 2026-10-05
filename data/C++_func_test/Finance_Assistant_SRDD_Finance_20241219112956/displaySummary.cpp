void FinanceAssistant::displaySummary() {
    cout << "Income: $" << userIncome << endl;
    cout << "Expenses: $" << userExpenses << endl;
    cout << "Savings Goal: $" << userSavingsGoal << endl;
    calculateSavingsRecommendation();
}