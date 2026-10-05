void ReportGenerator::GenerateGraphicalReport(const User& user) const {
    cout << "\nGraphical Report (Text-based):" << endl;
    double totalExpenses = user.GetTotalExpenses();
    double totalIncome = user.GetTotalIncome();
    int expenseBars = static_cast<int>((totalExpenses / totalIncome) * 50);
    int incomeBars = 50 - expenseBars;
    cout << "Income: ";
    for (int i = 0; i < incomeBars; i++) cout << "=";
    cout << endl;
    cout << "Expenses: ";
    for (int i = 0; i < expenseBars; i++) cout << "=";
    cout << endl;
}