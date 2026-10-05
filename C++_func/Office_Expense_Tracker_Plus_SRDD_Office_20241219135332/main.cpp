int main() {
    ExpenseManager expenseManager;
    Budget budget;
    ReportGenerator reportGenerator;
    ReceiptScanner receiptScanner;
    AccountingIntegration accountingIntegration;
    cout << "Welcome to Office Expense Tracker Plus!" << endl;
    expenseManager.addExpense(Expense(100, "Office Supplies", "2023-10-01"));
    expenseManager.addExpense(Expense(200, "Travel", "2023-10-02"));
    budget.setBudget("Office Supplies", 500);
    budget.setBudget("Travel", 1000);
    cout << "Scanning receipt..." << endl;
    string receiptData = "Office Supplies,150,2023-10-03\nTravel,300,2023-10-04";
    receiptScanner.scanReceipt(receiptData, expenseManager);
    cout << "Generating report..." << endl;
    reportGenerator.generateReport(expenseManager, budget);
    cout << "Integrating with accounting software..." << endl;
    accountingIntegration.integrate();
    return 0;
}