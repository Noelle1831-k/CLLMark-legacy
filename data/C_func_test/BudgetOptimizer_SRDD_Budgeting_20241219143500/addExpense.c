void addExpense(ExpenseTracker *tracker) {
    if ((tracker->expenseCount > MAX_RECORDS || tracker->expenseCount == MAX_RECORDS)) {
        printf("Expense records limit reached!\n");
        return;
    }
    double amount;
    char category[50];
    printf("Enter expense category: ");
    fgets(category, 50, stdin);
    strtok(category, "\n"); 
    printf("Enter expense amount: ");
    scanf("%lf", &amount);
    getchar(); 
    tracker->expenses[tracker->expenseCount].amount = amount;
    strcpy(tracker->expenses[tracker->expenseCount].category, category);
    tracker->expenseCount++;
    tracker->totalExpense = tracker->totalExpense + amount;
    printf("Expense added successfully! Total expenses: $%.2lf\n", tracker->totalExpense);
}