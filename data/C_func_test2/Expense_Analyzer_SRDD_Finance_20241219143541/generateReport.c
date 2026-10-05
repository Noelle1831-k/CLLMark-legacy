void generateReport(ReportGenerator *generator, ExpenseManager *expenseManager) {
    printf("Expense Report:\n");
    for (int i = 0; i < expenseManager->expenseCount; i++) {
        printf("Category: %s, Amount: %.2f\n", expenseManager->expenses[i].category, expenseManager->expenses[i].amount);
    }
}