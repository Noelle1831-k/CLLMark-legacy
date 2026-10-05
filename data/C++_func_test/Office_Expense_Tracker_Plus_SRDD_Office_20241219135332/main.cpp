int main(int argc, char *argv[]) {
    ExpenseManager expenseManager;
    Budget budget;
    ReportGenerator reportGenerator;
    ReceiptScanner receiptScanner;
    AccountingIntegration accountingIntegration;
    printf("Welcome to Office Expense Tracker Plus!\n");
    expenseManager.addExpense(Expense(100, "Office Supplies", "2023-10-01"));
    expenseManager.addExpense(Expense(200, "Travel", "2023-10-02"));
    budget.setBudget("Office Supplies", 500);
    budget.setBudget("Travel", 1000);
    printf("Scanning receipt...\n");
    string receiptData = "Office Supplies,150,2023-10-03\nTravel,300,2023-10-04";
    receiptScanner.scanReceipt(receiptData, expenseManager);
    printf("Generating report...\n");
    reportGenerator.generateReport(expenseManager, budget);
    printf("Integrating with accounting software...\n");
    accountingIntegration.integrate();
    return 0;
}