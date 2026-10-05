void BudgetAdvisor::provideBudgetingTips(const User &user) {
    double income = user.getIncome();
    double expenses = user.getExpenses();
    if (expenses > income) {
        cout << "Tip: Your expenses exceed your income. Try to reduce non-essential costs." << endl;
    } else if (expenses > (income * 0.7)) {
        cout << "Tip: Your expenses are high. Consider saving at least 20% of your income for long-term security." << endl;
    } else {
        cout << "Tip: You are in good shape! Keep maintaining a healthy savings rate." << endl;
    }
}