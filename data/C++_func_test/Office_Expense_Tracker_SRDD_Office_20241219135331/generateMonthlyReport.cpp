void ReportGenerator::generateMonthlyReport(const ExpenseManager &expenseManager) {
    cout << "\n===== Monthly Report =====" << endl;
    expenseManager.viewExpenses();
}