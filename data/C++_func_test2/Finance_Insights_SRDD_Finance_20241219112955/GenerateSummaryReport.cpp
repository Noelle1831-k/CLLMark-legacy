void ReportGenerator::GenerateSummaryReport(const User& user) const {
    cout << "\nSummary Report:" << endl;
    cout << "Total Income: " << user.GetTotalIncome() << endl;
    cout << "Total Expenses: " << user.GetTotalExpenses() << endl;
    cout << "Net Savings: " << user.GetTotalIncome() - user.GetTotalExpenses() << endl;
}