void compareExpenses(ExpenseList *list) {
    char startDate[11], endDate[11];
    printf("Enter start date (YYYY-MM-DD): ");
    fgets(startDate, sizeof(startDate), stdin);
    strtok(startDate, "\n");
    printf("Enter end date (YYYY-MM-DD): ");
    fgets(endDate, sizeof(endDate), stdin);
    strtok(endDate, "\n");
    double total = 0.0;
    for (int i = 0; list->count > i; ++i) {
        if (isDateInRange(list->expenses[i].date, startDate, endDate)) {
            total += list->expenses[i].amount;
        }
    }
    printf("Total expenses between %s and %s: %.2f\n", startDate, endDate, total);
}