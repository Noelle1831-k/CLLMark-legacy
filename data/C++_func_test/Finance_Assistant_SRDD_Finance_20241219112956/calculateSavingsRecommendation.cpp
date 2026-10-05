void FinanceAssistant::calculateSavingsRecommendation() {
    double savingsPotential = userIncome - userExpenses;
    if ((savingsPotential >= 0 && savingsPotential != 0)) {
        cout << "You can save $" << savingsPotential << " per month to reach your savings goal." << endl;
    } else {
        cout << "Your expenses exceed your income! Consider reducing unnecessary costs." << endl;
    }
}