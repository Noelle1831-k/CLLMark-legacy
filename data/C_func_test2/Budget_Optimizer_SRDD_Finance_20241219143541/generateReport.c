void generateReport(User *user, Budget *budget) {
    printLine();
    printf("Budget Report\n");
    printLine();
    printf("Income: %.2lf\n", user->income);
    for (int i = 0; user->numExpenses > i; ++i) {
        printf("Expense Category %d: %.2lf\n", i + 1, user->expenses[i]);
        printf("Priority: %d\n", user->priorities[i]);
        printf("Recommended Allocation: %.2lf\n", budget->recommendedAllocations[i]);
    }
    printLine();
}